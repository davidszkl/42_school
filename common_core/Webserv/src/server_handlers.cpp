#include "webserver.hpp"

int	webserver::handle_GET(const pollfd &fd, server & server) {
	bool body					= true;
	std::string& response_file	= _http_request._path;
	const config::location& current_block = server._configs[_config_index].location_blocks[_location_index];
	const config& current_server = server._configs[_config_index];
	struct stat s;

	if (std::find(current_block.allowed_methods.begin(), current_block.allowed_methods.end(),
	 	"GET") == current_block.allowed_methods.end())
	{
		_response_code = METHOD_NOT_ALLOWED;
		response_file = server._configs[_config_index].error_pages[METHOD_NOT_ALLOWED];
	}
	int tmp = do_cgi(current_block, current_server, server, fd);
	if (!tmp)
		return 0;
	if (_http_request._path[_http_request._path.size() - 1] == '/')
		_http_request._path += current_block.index;
	logn("requestpath: " + _http_request._path);
    if (current_block.autoindex && stat(_http_request._path.c_str(), &s) == 0 && (s.st_mode & S_IFDIR))
    {
		_response_code = OK;
		logn("autoindexing from " + current_block.path);
		_response_code = OK;
		send_autoindex(fd);
		return 0;
    }
	else if (current_block.redirect != "")
	{
		_response_code = MOVED_PERMANENTLY;
		send_redirect(fd, current_block.redirect);
		return 0;
	}
	else if (!file_exists(_http_request._path)) {
		_response_code	= NOT_FOUND;
		response_file	= server._configs[_config_index].error_pages[NOT_FOUND];
	}
	else
		_response_code = OK;
	logn("RESPONSE_FILE\n" + response_file);
	send_response(fd, response_file, body);
	return 0;
}

void webserver::send_autoindex(const pollfd& fd) {
	string http_response;

	http_response += "HTTP/1.1 ";
	http_response += i_to_str(_response_code);
	http_response += get_code_description(_response_code);
	http_response += "\r\n\r\n";
	http_response += autoindex(_http_request._path);
	send(fd.fd, http_response.c_str(), http_response.size(), 0);
}

void webserver::send_redirect(const pollfd& fd, const string& redirect)
{
	string http_response;

	http_response += "HTTP/1.1 ";
	http_response += i_to_str(_response_code);
	http_response += get_code_description(_response_code);
	http_response += "\r\n";
	http_response += ("Location: " + redirect);
	http_response += "\r\n\r\n";
	cerr << http_response << endl;
	send(fd.fd, http_response.c_str(), http_response.size(), 0);
}

void webserver::send_response(const pollfd &fd, string filename, bool body) {
	string http_response;
	http_response += "HTTP/1.1 ";
	http_response += i_to_str(_response_code);
	http_response += get_code_description(_response_code);
	http_response += "\r\n\r\n";
	if (body)
		http_response += slurp_file(filename);
	send(fd.fd, http_response.c_str(), http_response.size(), 0);
}

int	webserver::handle_POST(const pollfd &fd, server &server) {
    bool body					= true;
    std::string& response_file	= _http_request._path;
    const config::location & current_block = server._configs[_config_index].location_blocks[_location_index];
	const config& current_server = server._configs[_config_index];

	cerr << "config index = " << _config_index << endl;
	cerr << "location index = " << _location_index << endl;
	cerr << "path: " << current_block.path << endl
		 << "root: " << current_block.root << endl
		 << "index: " << current_block.index << endl;
    if (std::find(current_block.allowed_methods.begin(), current_block.allowed_methods.end(),"POST")== current_block.allowed_methods.end())
    {
        _response_code = METHOD_NOT_ALLOWED;
        response_file = server._configs[_config_index].error_pages[METHOD_NOT_ALLOWED];
    }
	int tmp = do_cgi(current_block, current_server, server, fd);
	if (!tmp)
		return 0;
    _response_code = LENGTH_REQUIRED;
    response_file = server._configs[_config_index].error_pages[LENGTH_REQUIRED];
    send_response(fd, response_file, body);
    return 0;
}

int	webserver::handle_DELETE(const pollfd &fd, server& server) {
	bool body					= true;
	std::string& response_file	= _http_request._path;
	const config::location& current_block = server._configs[_config_index].location_blocks[_location_index];

	if (std::find(current_block.allowed_methods.begin(), current_block.allowed_methods.end(),
	 	"DELETE") == current_block.allowed_methods.end())
	{
		_response_code = METHOD_NOT_ALLOWED;
		response_file = server._configs[_config_index].error_pages[METHOD_NOT_ALLOWED];
	}
	else if (!file_exists(_http_request._path)) {
		_response_code = NOT_FOUND;
		response_file = server._configs[_config_index].error_pages[NOT_FOUND];
	}
	else
	{
		body = false;
		if (remove(_http_request._path.c_str()))
			_response_code = FORBIDDEN;
		else
			_response_code = NO_CONTENT;			
	}
	send_response(fd, response_file, body);
	return 0;
}

inline bool file_exists (const string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int webserver::do_cgi(const config::location& current_block, const config& current_server, server & server, const pollfd &fd) {
	int tmp = is_valid_for_cgi(_http_request._full_request, current_block.root, current_block.path, current_server.max_body);
	std::string& response_file	= _http_request._path;
	int tmp2 = 0;
	cerr << "upload dir = " << current_block.upload_dir << endl;
	cerr << "tmp = " << tmp << endl;
	switch (tmp) {
		case 0:
			return 1;
		case 1:
			tmp2 = execute_cgi(_http_request._full_request, current_block.root, current_block.path, current_block.upload_dir, fd.fd, envp); 
			switch (tmp2) {
				case 0:
					break;
				case 1:
					logn("system errror in execute_cgi()");
					break;
				case FORBIDDEN:
					_response_code = FORBIDDEN;
					response_file = server._configs[_config_index].error_pages[FORBIDDEN];
					send_response(fd, response_file, true);
					break;
				case UNSUPPORTED_MEDIA_TYPE:
					_response_code = UNSUPPORTED_MEDIA_TYPE;
					response_file = server._configs[_config_index].error_pages[UNSUPPORTED_MEDIA_TYPE];
					send_response(fd, response_file, true);
					break;
			}
			return 0;
		case LENGTH_REQUIRED:
			_response_code = LENGTH_REQUIRED;
			response_file = server._configs[_config_index].error_pages[LENGTH_REQUIRED];
			send_response(fd, response_file, true);
			return 0;
		case REQUEST_ENTITY_TOO_LARGE:
			_response_code = REQUEST_ENTITY_TOO_LARGE;
			response_file = server._configs[_config_index].error_pages[REQUEST_ENTITY_TOO_LARGE];
			send_response(fd, response_file, true);
			return 0;
		case UNSUPPORTED_MEDIA_TYPE:
			_response_code = UNSUPPORTED_MEDIA_TYPE;
			response_file = server._configs[_config_index].error_pages[UNSUPPORTED_MEDIA_TYPE];
			send_response(fd, response_file, true);
			return 0;
	}
	return 0;
}