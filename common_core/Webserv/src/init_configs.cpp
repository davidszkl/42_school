#include "debug.hpp"
#include "config.hpp"
#include <fstream>
#include <exception>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include "string_utils.hpp"

std::vector<config> get_config_vector(const std::string& str, std::size_t line_num);

static std::string get_file_content(const std::string& file_path)
{
	std::ifstream file(file_path.c_str());
	if (!file) throw std::runtime_error("Invalid config file (" + file_path + ")");
	std::ostringstream sstr;
	sstr << file.rdbuf();
	return sstr.str();
}

//clean comments and empty nl in file header
//return number of lines deleted
static std::size_t clean_file_head(std::string& str)
{
	std::size_t i = 1;
	while (1)
	{
		if (str[0] == '#')
		{
			std::size_t tmp = str.find('\n');
			if (tmp == std::string::npos) tmp = str.length() - 1;
			str = str.substr(tmp, str.length() - tmp);
		}
		if (str[0] == '\n')
			str = str.substr(1, str.length() - 1);
		else
			break;
		i++;
	}
	return i;
}

//i is index of location '{'
//will check if location block has valid syntax (i.e.: location /ok/cool { )
static bool is_valid_location(const std::string& str, std::size_t i, std::size_t ln2)
{
	std::size_t j = str.rfind("location", i);
	if (j == std::string::npos) throw std::runtime_error(to_string(ln2) + ": no location keyword before '{'");
	j += std::string("location").length();
	while (std::isspace(str[j])) j++;
	if (j == i) throw std::runtime_error(to_string(ln2) + ": need path between location and '{'");
	if (str[j] != '/') throw std::runtime_error(to_string(ln2) + ": location path must begin with a '/'");
	while (!std::isspace(str[j]) && j != i) j++;
	if (j == i) return true;
	while (std::isspace(str[j]) && j != i) j++;
	if (j == i) return true;
	throw std::runtime_error(to_string(ln2) + ": only whitespaces are allowed between location path and '{'");
}

//check if correct depth of braces in server and returns index of ending '}'
//i is index of beginning '{'
//also checks if location blocks are valid
static std::size_t get_end_server_block(const std::string& str, std::size_t i, std::size_t ln2)
{
	int depth = 0;
	while (++i < str.length())
	{
		if (str[i] == '\n') ln2++;
		if (str[i] == '}' && depth == 0) return i;
		if (str[i] == '}' && depth == 1) depth--;
		if (str[i] == '{' && depth == 1) throw std::runtime_error(to_string(ln2) + ": open bracket in location block");
		if (str[i] == '{' && depth == 0)
		{
			if (is_valid_location(str, i, ln2)) depth++;
			else throw std::runtime_error(to_string(ln2) + ": block inside server is not a location block");
		}
	}
	throw std::runtime_error(to_string(ln2) + ": server block not closed");
}

//check if braces are only server and location blocks
static void check_braces(const std::string& str, std::size_t line_num)
{
	std::size_t ln2 = line_num;
	std::size_t i = 0;
	while (i < str.length())
	{
		std::size_t j = std::string(&str[i]).find("server");
		if (j == std::string::npos) j = str.length(); else j += i;
		while (i < j) {
			if (str[i] == '\n') ln2++;
			if (!std::isspace(str[i])) throw std::runtime_error(to_string(ln2) + ": global statement is not 'server'");
			i++;
		}
		if (i == str.length()) return; // parsed everything until the end
		i += std::string("server").length();
		j = std::string(&str[i]).find("{");
		if (j == std::string::npos) j = str.length(); else j += i;
		while (i < j) {
			if (str[i] == '\n') ln2++;
			if (!std::isspace(str[i]))
				throw std::runtime_error(to_string(ln2) + ": global 'server' statement not followed by '{'");
			i++;
		}
		j = get_end_server_block(str, i, ln2); //i is on '{' here
		while (++i < j)
			ln2 += str[i] == '\n';
		i++; //to jump over '}'
	}
}

static void remove_locations_trailing_slash(config& c)
{
	for (std::size_t i = 0; i < c.location_blocks.size(); i++)
	{
		std::size_t l = c.location_blocks[i].path.length();
		if (l != 1 && c.location_blocks[i].path[l - 1] == '/')
		{
			logn("removing trailing / of " + c.location_blocks[i].path + " location");
			c.location_blocks[i].path = c.location_blocks[i].path.substr(0, --l);
		}
	}
}

static void check_duplicate_locations(const config& c)
{
	for (std::size_t i = 0; i < c.location_blocks.size(); i++)
	{
		for (std::size_t j = i + 1; j < c.location_blocks.size(); j++)
			if (c.location_blocks[i].path == c.location_blocks[j].path)
				throw std::runtime_error("duplicate location: " + c.location_blocks[i].path);
	}
}

static void check_valid_locations(const config& c)
{
	for (std::size_t i = 0; i < c.location_blocks.size(); i++)
	{
		const std::string& s = c.location_blocks[i].path;
		for(std::size_t j = 0; j < s.length(); j++)
		{
			if(!(std::isalnum(s[j]) || s[j] == '/' || s[j] == '_' || s[j] == '-'))
				throw std::runtime_error("Invalid character '" + s.substr(j, 1) + "' in location: " + s);
		}
		if (s.find("//") != std::string::npos)
				throw std::runtime_error("Consecutive '/' in location: " + s);
	}	
}

static void check_methods_in_locations(const config& c)
{
	for (std::size_t i = 0; i < c.location_blocks.size(); i++)
	{
		const std::vector<std::string>& m = c.location_blocks[i].allowed_methods;
		for (std::size_t i = 0; i < m.size(); i++)
			if (m[i] != "GET" && m[i] != "POST" && m[i] != "DELETE")
				throw std::runtime_error("Invalid method in location block: " + m[i]);
	}
}

static void add_trailing_to_root(config& c)
{
	for (std::size_t i = 0; i < c.location_blocks.size(); i++)
	{
		string& s = c.location_blocks[i].root;
		if (s != "" && s[s.length() - 1] != '/')
		{
			logn("Adding trailing / to root " + s);
			s += "/";
		}
	}
}

static void check_at_least_root(const config& c)
{
	bool b = true;
	for (std::size_t i = 0; i < c.location_blocks.size(); i++)
	{
		if (c.location_blocks[i].path == "/")
			b = false;
	}
	if (b)
		throw std::runtime_error("server needs at least a location /");
}

static void check_config_vector(std::vector<config>& cv)
{
	typedef std::pair<std::string, int> psi;
	//checking duplicate host:port
	for (std::size_t i = 0; i < cv.size(); i++)
	{	
		psi host_port = psi(cv[i].server_name, cv[i].port);
		for (std::size_t j = i + 1; j < cv.size(); j++)
			if (host_port == psi(cv[j].server_name, cv[j].port))
				throw std::runtime_error("Two or more servers with the same server_name and port");
	}
	//checking duplicate locations and more
	for (std::size_t i = 0; i < cv.size(); i++)
	{
		add_trailing_to_root(cv[i]);
		check_valid_locations(cv[i]);
		remove_locations_trailing_slash(cv[i]);
		check_duplicate_locations(cv[i]);
		check_methods_in_locations(cv[i]);
		check_at_least_root(cv[i]);
	}
}

static void display_vector(const std::vector<config>& v)
{
	for (std::size_t i = 0; i < v.size(); i++)
		logn(v[i]);
}

std::vector<config> init_configs(const std::string& file_path)
{
	std::string str = get_file_content(file_path);
	std::size_t line_num = clean_file_head(str);
	check_braces(str, line_num);
	//here server blocks and location blocks are good.
	//still need to fill vector and check if statements are valid.
	std::vector<config> config_vec = get_config_vector(str, line_num);
	//config vector is initialized. Still need to check if it's possible or not (e.g.: duplicate hostname:port)
	check_config_vector(config_vec);
	display_vector(config_vec);
	return config_vec;
}

