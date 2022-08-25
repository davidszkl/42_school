#include "cgi.hpp"
#include "debug.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

void fix_content_in_split(char**& split);

char	**ft_split(char const *s, char c);

/*
	e.g.: if s == "hello ok" return "hello"
	s must not begin with a space character
 */
static std::string get_next_word(const std::string& s)
{
	std::string rval;
	for(std::size_t i = 0; i < s.length() && s[i] != ' '; i++)
		rval += s[i];
	return rval;
}


static std::size_t get_next_slash(const std::string& s)
{
	std::size_t i;
	for (i = 0; i < s.length(); i++)
		if (s[i] == '/')
			return i;
	return i;
}

static bool is_py(const std::string file)
{
	std::size_t l = file.length();
	return file[l - 1] == 'y' && file[l - 2] == 'p' && file[l - 3] == '.';
}

static bool is_exec(const std::string& file_path, const std::string& root)
{
	return access((root + file_path).c_str(), X_OK) != -1;
}

static void ft_freetab(const char **tab)
{
	for (std::size_t i = 0; tab[i]; i++)
		free((void *)tab[i]);
	free(tab);
}

/*
	checks if there is a valid executable .py file in the header path.
	return std::string::npos if nothnig found, otherwise index of character after the 'y' in the .py
 */
static std::size_t get_end_path(const std::string& path, const std::string& root)
{
	for (std::size_t i = 0; i < path.length(); i++)
	{
		if (path[i] == '/' && i + 1 != path.length())
		{
			std::string file = path.substr(i+1, get_next_slash(&path[i+1]));
			if (is_py(file) && is_exec(path.substr(0, i + 1 + file.length()), root))
				return i + 1 + file.length();
		}
	}
	return std::string::npos;
}

static std::string get_end_file(const std::string& path)
{
	std::size_t i = path.rfind("/") + 1;
	return path.substr(i, path.length() - i);	
}

//if post && define_query ->  pass it to stdin
//if get && define query -> pass it as env
//if define path -> pass it as env
static int setup_and_exec(int output_fd,
		std::string request,
		bool define_query,
		std::string query_string,
		bool define_path,
		std::string path_info,
		std::string exec_path,
		std::string content_type,
		bool define_content,
		const std::string& upload_pass,
		char **envp)
{
	std::string command = "/usr/bin/env";
	std::string exec_path2 = exec_path;
	while (exec_path2[exec_path2.length() - 1] != '/')
		exec_path2 = exec_path2.substr(0, exec_path2.length() - 1);
	if (define_query && request == "GET")
		command += " QUERY_STRING=" + query_string;
	if (define_path)
		command += " PATH_INFO=" + path_info;
	if (define_content)
		command += " CONTENT_TYPE=" + content_type;
	command += " REQUEST_METHOD=" + request;
	if (upload_pass != "")
		command += " UPLOAD_PASS=" + upload_pass;
	command += " ./" + get_end_file(exec_path);
	int pipefds[2];
	if (pipe(pipefds) == -1)
	{
		perror("pipe()");
		return 1;
	}
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork()");
			return 1;
	} else if (pid == 0) {	
		close(pipefds[1]);
		if (-1 == dup2(pipefds[0], 0)) {
			close(pipefds[0]);
			close(output_fd);
			perror("dup2()"); exit(1);
		}
		close(pipefds[0]);
		if (-1 == dup2(output_fd, 1))   {
			if (output_fd != 1) close(output_fd);
			perror("dup2()"); exit(1);
		}
		if (output_fd != 1) close(output_fd);
		logn("child process changes dir to: " + exec_path2);
		if (chdir(exec_path2.c_str()) == -1)
		{
			perror("chdir()");
			exit(1);
		}
		logn("Commmand to split: " + command);
		char **split = ft_split(command.c_str(), ' ');
		if (!split) { perror("ft_split()"); exit(1); }
		fix_content_in_split(split);
		logn("executing " + exec_path + ":");
		execve(split[0], (char * const *)split, envp);
		ft_freetab(const_cast<const char**>(split));
		perror("execve()");
		exit(1);
	}
	if (request == "POST" && define_query)
		write(pipefds[1], query_string.c_str(), query_string.length());
	close(pipefds[0]);
	close(pipefds[1]);
	int status = 0;
	waitpid(pid, &status, 0);
	int rval = WEXITSTATUS(status);
	if (rval == 403 % 256 || rval == 415 % 256) //because process rval fits in only one byte...
		rval += 256;
	return rval;
}

/*
	This function needs the first line of the http header and the body, so pass the full http message in full_message.
	root -> root of location block
	location -> path of location block
	ouput_fd is where the python script will write its output.
	The http message should be valid! (is_valid_for_cgi must have returned true with the same message/root)
	return values:
		0 -> success
		1 -> system error
		415 or 403 -> error page to display
 */
int execute_cgi(const std::string& full_message, std::string root, const std::string& location, const std::string& upload_pass, int output_fd, char **envp)
{
	cerr << "IN EXECUTE =" << upload_pass << endl;
	if (root != "" && root[root.length() -1] != '/') root += '/';
	using std::string;
	logn("Executing cgi...");
	const string request = get_next_word(full_message);
	string path = get_next_word(&full_message[request.length() + 1]);
	path = path.substr(location.length(), path.length() - location.length());
	std::size_t path_end = get_end_path(path, root);
	if (path_end == std::string::npos) path_end = path.length();
	std::string exec_path = root + path.substr(0, path_end);
	logn("path to cgi executable==" + exec_path);
	logn("cgi request==" + request);
	if (upload_pass == "")
		logn("Warning: upload_pass passed to cgi is empty");
	std::size_t qpos = path_end;
	while (qpos < path.length() && path[qpos] != '?')
		qpos++;
	const string path_info = path.substr(path_end, qpos - path_end);
	const bool define_path = path_info != "";
	logn("path_info==" + path_info);
	string query_string;
	bool define_query = false;
	if (request == "GET" && qpos != path.length())
	{
		query_string = path.substr(qpos + 1, path.length() - qpos - 1);
		define_query = true;
	}
	else if (request == "POST")
	{
		const std::size_t content_length = atoi(get_header_info(full_message, "Content-Length").c_str());
		if (content_length != 0)
		{
			define_query = true;
			query_string = full_message.substr(full_message.find("\r\n\r\n") + 4, content_length);
		}
	}
	if (define_query == true)
		logn("QUERY_STRING==" + query_string);
	else
		logn("No QUERY_STRING will be defined/passed to stdin");
	string content_type = get_header_info(full_message, "Content-Type");
	bool define_content = (content_type != "");
	return setup_and_exec(output_fd, request, define_query, query_string, define_path, path_info, exec_path, content_type, define_content, upload_pass, envp);
}


