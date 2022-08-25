#include "webserver.hpp"
#include "debug.hpp"

bool _server_alive = true;

void server_shutdown(int signbr) {
	(void)signbr;
	_server_alive = false;
}

webserver::webserver(vector<config> config_vector):	_response_code(404), _socklen(sizeof(_client_addr))
{
	signal(SIGINT, &server_shutdown);
	_server_alive = true;
	memset(&_pollfd, 0, sizeof(_pollfd));
	_pollfd.fd	= -1;
	try {
		map<unsigned short, vector<config> > ports;						//plusieurs serveurs peuvent ecouter sur un port
		for(size_t n = 0; n < config_vector.size(); n++)				
			ports[config_vector[n].port].push_back(config_vector[n]);	//trier les configs en fonction des ports
		for(map_it n = ports.begin(); n != ports.end(); n++)
			_servers.push_back(server(n->second));
	}
	catch (...) {
		throw ;
	}
}

webserver::~webserver() {
	logn("webserv destructor");
	for (size_t n = 0; n < _servers.size(); n++) {
		if (_servers[n]._sockfd)
		{
			log("CLOSING FD ");
			logn(_servers[n]._sockfd);
			close(_servers[n]._sockfd);
		}
	}
}

void webserver::init_pollsock()
{
	pollfd listener;
	memset(&listener, 0, sizeof(listener));
	_pollsock.push_back(listener);
	for (size_t n = 0; n < _servers.size(); n++)
	{
		pollfd tmp;
		memset(&tmp, 0, sizeof(tmp));
		tmp.fd		= _servers[n]._sockfd;
		tmp.events	= POLLIN | POLLOUT;
		_pollsock.push_back(tmp);
	}
}

int webserver::get_fd_ready() const {
	for (size_t n = 0; n < _pollsock.size(); n++)
		if (_pollsock[n].revents & POLLIN)
			return _pollsock[n].fd;
	return -1;
}

void webserver::listen_all()
{
	init_pollsock();
	int accept_fd = -1;
	while (_server_alive)
	{
		int rval = 0;
		while (true)
		{
			cerr << "Waiting for connection.\r";
			if ((rval = poll(&_pollsock[0], _pollsock.size(), 1000)))
				break ;
			// cerr << "Waiting for connection..\r";						style
			// if ((rval = poll(&_pollsock[0], _pollsock.size(), 1000)))
			// 	break ;
			// cerr << "Waiting for connection...\r";
			// if ((rval = poll(&_pollsock[0], _pollsock.size(), 1000)))
			// 	break ;
			cerr << "                         \r";
		}
		cerr << endl;
		if (rval < 0)
			throw webserver_exception("Poll failed on an fd");

		if (accept_fd < 0)
		{
			accept_fd = get_fd_ready();
			log("accept_fd = ");
			logn(accept_fd);
			if ((_pollsock[0].fd = accept(accept_fd,								\
										reinterpret_cast<sockaddr*>(&_client_addr),	\
										&_socklen))									\
										< 0)
				throw webserver_exception("Accept failed");
			_pollsock[0].events = POLLIN | POLLOUT;
			log("Connection on fd ");
			log(accept_fd);
			logn(" accepted");
			log("Connection fd is ");
			logn(_pollsock[0].fd);
			logn("");
			continue ;
		}

		if (!(_pollsock[0].revents & POLLIN))
			continue ;

		int read_rval = read_msg(_pollsock[0].fd);
		if (read_rval == -1) {
			cerr << "Fatal problem occured during connection with " << accept_fd << endl;
			log("ERRNO ");
			logn(errno);
			logn("");
			throw webserver_exception("Poll fatal error");
		}
		if (read_rval != -2)
		{
			try {
				int id = get_server_id(accept_fd);
				request_handler(_pollsock[0], _servers[id]);
			}
			catch (webserver_exception & e) {
				cerr << e.what() << endl;
			}
		}
		close(_pollsock[0].fd);
		_pollsock[0].fd		= 0;
		_pollsock[0].events = 0;
		accept_fd = -1;
		clear_errors();
	}
}

int webserver::read_msg(int fd) {;
	char buffer[10000] = {0};
	clear_request();
	cerr << "Receiving message:\n";
	logn("Method: " + _http_request._method);	
	int end = recv(fd, &buffer, 10000, 0);
	if (end < 0)
		return -1;
	if (!find_crlf(string(buffer)))
		return -2;
	buffer[end] = '\0';
	_http_request._full_request += buffer;
	_content_length = std::atoi(get_header_info(_http_request._full_request, "Content-Length").c_str());
	log("_content_length = ");
	logn(_content_length);
	return 0;
}

int webserver::get_server_id(int fd_tofind) const {
	for (size_t n = 1; n < _pollsock.size(); n++)
		if (_pollsock[n].fd == fd_tofind)
			return n - 1;
	return -1;
}

void webserver::request_handler(const pollfd & fd, server & server) {
	init_request(server);
	cerr << _http_request._header << endl;
	cerr << server._configs[_config_index].location_blocks[_location_index] << endl;
	logn("request=================\n" + _http_request._full_request + "\nrequest=================");
	logn("uri: " + _http_request._uri);
	logn("");
	if (!_http_request._method.size()	||
		!_http_request._uri.size()		||
		!_http_request._version.size())
	{
		_response_code = BAD_REQUEST;
		send_response(fd, "", false);
	}
	else if (_http_request._uri.size() > URI_MAX)
	{
		_response_code = REQUEST_URI_TOO_LONG;
		send_response(fd, "", false);
	}
	else if (_http_request._version != "HTTP/1.1")
	{
		_response_code = HTTP_VERSION_NOT_SUPPORTED;
		send_response(fd, "", false);
	}
	else if (_http_request._method	== "GET")
		handle_GET(fd, server);
	else if (_http_request._method	== "POST")
		handle_POST(fd, server);
	else if (_http_request._method	== "DELETE")
		handle_DELETE(fd, server);
	else {
		_response_code = NOT_IMPLEMENTED;
		send_response(fd, server._configs[_config_index].error_pages[NOT_IMPLEMENTED], true);
	}
}

void webserver::init_request(const server & server) {
	int temp_pos = _http_request._full_request.find("\r\n\r\n");
	if (temp_pos)
		_http_request._header = _http_request._full_request.substr(0, temp_pos);
	_http_request._body = _http_request._full_request.substr(temp_pos + 4, _http_request._full_request.size());

	size_t cursor = 0;
	while(1)
	{
		string str_from(&_http_request._header[cursor]);
		string line = read_header_line(&_http_request._header[cursor]);
		cursor += line.size();
		_http_request._header_lines.push_back(line);
		if (line == "\r\n" || !line.size())
			break ;
	}
	std::stringstream ss(_http_request._header_lines[0]);
	logn("HEADER_LINES: " + _http_request._header_lines[0]);
	ss >> _http_request._method;
	logn("METHOD: " + _http_request._method);
	ss >> _http_request._uri;
	ss >> _http_request._version;
	_config_index = get_config_index(server._port, server._configs, _http_request._header_lines);
	if (_config_index == -1)
	{
		logn("config index is -1. setting path to " + _http_request._uri);
		_http_request._path = _http_request._uri;
		return;
	}
	_location_index = get_location_index(_http_request._uri, server._configs[_config_index]);
	const std::size_t l = server._configs[_config_index].location_blocks[_location_index].path.length();
	_root = server._configs[_config_index].location_blocks[_location_index].root;
	_http_request._path = _root + _http_request._uri.substr(l, _http_request._uri.length() - l);
	logn("new request_path: " + _http_request._path);
	logn("used root: " + _root);
	logn("");
}

void webserver::clear_errors() {						//clear servers that got shutdown for some reason
	for (size_t n = 1; n < _pollsock.size(); n++)
	{
		if (_pollsock[n].revents & POLLERR)
		{
			log("killing server ");
			logn(n);
			close(_pollsock[n].fd);
			_servers.erase(_servers.begin() + n);
			_pollsock.erase(_pollsock.begin() + n);
		}
	}
}

int webserver::get_config_index(unsigned short _port,
    const vector<config>& _configs,
    const vector<string>& header_lines)
{
	_port = ntohs(_port);
    string host;
	cerr << "host =" << host << endl;
    for (std::size_t i = 0; i < header_lines.size(); i++)
    {
        if (header_lines[i].compare(0, 6, "Host: ") == 0)
        {
            host = header_lines[i].substr(6, string::npos);
			if (host.size() >= 2)
				host = host.substr(0, host.size() - 2);
            break;
        }
    }
    for (std::size_t i = 0; i < _configs.size(); i++)
    {
        if (_configs[i].port != _port) continue;
        if (host != "" && _configs[i].server_name != host)
			continue;
        return i;
    }
	for (std::size_t i = 0; i < _configs.size(); i++)
		if (_configs[i].port == _port)
			return i;
	logn("get_config_index returned -1. Host=" + host + " port=" + i_to_str(_port));
    return -1;
}

int webserver::get_location_index(const string& uri, const config conf)
{
    vector<int> results;
    for (std::size_t i = 0; i < conf.location_blocks.size(); i++)
    {
        const int r = conf.location_blocks[i].match_url(uri);
        results.push_back(r);
    }
    int n = 0;
    for (std::size_t i = 0; i < results.size(); i++)
        if (results[i] > results[n])
            n = i;
   return n; 
}

string webserver::autoindex(const string& path) const
{
	string	body;
	DIR		*dir;
	const bool missing_slash = (_http_request._uri[_http_request._uri.length() -1] != '/');

	dir = opendir(path.c_str());
	if (!dir)
		return "error";
body += "<html>\r\n<head>\n\
<title>Index of "
+ path
+ "</title></head>\r\n\
<body>\r\n\
<h1>Index of "
+ path
+ "</h1><hr><pre>\r\n";
	string file_ent;
	struct dirent *ent;
	while ((ent = readdir(dir)))
	{
		if (!ent)
			break;
		file_ent = ent->d_name;
		body += "<a href='" + _http_request._uri + (missing_slash ? "/" : "") + file_ent + "'>" + file_ent + "</a>\r\n";
	}
	body += "</body>\n</html>";
	logn("index body:\n" + body);
	closedir(dir);
	return body;
}

inline size_t get_read_bytes(string str) {
	return (str.size() - str.find("\r\n\r\n") + 4);
}
