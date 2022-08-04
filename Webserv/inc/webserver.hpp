#pragma once

#include "server.hpp"
#include "cgi.hpp"
#include "utilities.hpp"

#include <signal.h>				//TO_ERASE

#define URI_MAX 1024

enum RESPONSE_CODES {
	OK					= 200,	//Martin
	CREATED				= 201,	//Martin
	ACCEPTED			= 202,	//Martin
	NO_CONTENT			= 204,	//Martin
	RESET_CONTENT 		= 205,	//Martin
	PARTIAL_CONTENT 	= 206,	//Martin

	MULTIPLE_CHOICES	= 300,  //X
	MOVED_PERMANENTLY	= 301,	//Martin
	FOUND				= 302,	//X
	SEE_OTHER			= 303,	//X
	NOT_MODIFIED		= 304,	//X
	USE_PROXY			= 305,	//X
	TEMPORARY_REDIRECT	= 307,	//X

	BAD_REQUEST						= 400,	//OK
	UNAUTHORIZED					= 401,	//X
	FORBIDDEN						= 403,	//GET: OK,
	NOT_FOUND						= 404,	//GET: OK,
	METHOD_NOT_ALLOWED				= 405,	//GET: OK,
	NOT_ACCEPTABLE					= 406,	//X
	PROXY_AUTHENTICATION_REQUIRED	= 407,	//X
	REQUEST_TIMEOUT					= 408,	//X
	CONFLICT						= 409,	//X
	GONE							= 410,	//X
	LENGTH_REQUIRED					= 411,	//Martin
	PRECONDITION_FAILED				= 412,	//X
	REQUEST_ENTITY_TOO_LARGE		= 413,	//Martin
	REQUEST_URI_TOO_LONG			= 414,	//OK
	UNSUPPORTED_MEDIA_TYPE			= 415,	//X
	REQUESTED_RANGE_NOT_SATISFIABLE	= 416,	//X
	EXPECTATION_FAILED				= 417,	//X

	INTERNAL_SERVER_ERROR			= 500,	//X
	NOT_IMPLEMENTED					= 501,	//OK
	BAD_GATEWAY						= 502,	//X
	SERVICE_UNAVAILABLE				= 503,	//X
	GATEWAY_TIMEOUT					= 504,	//X
	HTTP_VERSION_NOT_SUPPORTED		= 505	//OK
};

extern bool	_server_alive;

class webserver
{
public:

	webserver() {};
	webserver(vector<config> config_vector);
	~webserver();

	void	listen_all();
	void	clear_errors();
	void	init_pollsock();
	void	init_request(const server & server);
	void	clear_request();
	void	request_handler(const pollfd& fd, server& server);
	void	send_response(const pollfd& fd, string filename, bool error);
	void	send_autoindex(const pollfd &fd);
	void	send_redirect(const pollfd& fd, const string& redirect);
	bool	is_deletable(server& server, const string& filename) const;
	int		get_fd_ready()			const;
	int		get_server_id(int fd)	const;
	int		read_msg(int fd);
	int		handle_POST(const pollfd& fd, server &server);
	int		handle_DELETE(const pollfd& fd, server& server);
	int		handle_GET(const pollfd& fd, server& server);
	int		get_config_index(unsigned short _port, const vector<config>& _configs, const vector<string>& header_lines);
	int		get_location_index(const string &uri, const config conf);
	int		do_cgi(const config::location& current_block, const config& current_server, server & server, const pollfd &fd);
	string	autoindex(const string& path) const;

	class webserver_exception : public std::runtime_error
	{
	public:
		webserver_exception(const char* what): runtime_error(what) {}
	};

	typedef map<unsigned short, vector<config> >::iterator map_it;
	struct http_request
	{
		string			_full_request;
		string			_header;
		string			_body;
		string			_method;
		string			_uri;
		string			_version;
		string			_path;
		vector<string>	_header_lines;
	};
	
	char **envp;

private:

	int				_config_index;
	int				_location_index;
	int				_response_code;
	vector<server>	_servers;
	vector<pollfd>	_pollsock;
	http_request	_http_request;
	sockaddr_in		_client_addr;
	socklen_t		_socklen;
	size_t			_content_length;
	pollfd			_pollfd;
	string			_root;
};