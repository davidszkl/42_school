#include "server.hpp"

server::server(vector<config> vector_config):
	_configs(vector_config),
	_port(htons(vector_config[0].port))
{
	_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (_sockfd < 0)
		throw server_exception("Socket creation failed.\nShutting down server.\n"); 
	log("Socket ");
	log(_sockfd);
	logn(" Successfully created");

	if (fcntl(_sockfd, F_SETFL, O_NONBLOCK) < 0)
	{
		close(_sockfd);
		throw server_exception("Socket configuration failed. ( fcntl() )\nShutting down server.\n");
	}
	logn("O_NONBLOCK set");

	memset(&_server_addr, 0, sizeof(_server_addr));
	_server_addr.sin_family			= AF_INET;
	_server_addr.sin_addr.s_addr	= inet_addr("127.0.0.1");
	_server_addr.sin_port			= _port;

	int temporary = 0;
	if (setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &temporary, sizeof(int)) < 0)
	{
		close(_sockfd);
		throw server_exception("Socket configuration failed. ( setsockopt() )\nShutting down server.\n");
	}
	logn("SO_REUSEADDR set"); 

	if (setsockopt(_sockfd, SOL_SOCKET, SO_REUSEPORT, &temporary, sizeof(int)) < 0)
	{
		close(_sockfd);
		throw server_exception("Socket configuration failed. ( setsockopt() )\nShutting down server.\n");
	}
	logn("SO_REUSEPORT set"); 

	if (bind(	_sockfd,									\
				reinterpret_cast<sockaddr*>(&_server_addr), \
				sizeof(_server_addr))						\
				< 0)
	{
		close(_sockfd);
		throw server_exception("bind() failed.\nShutting down server.\n");
	}
	log("Socket successfully bound to port ");
	logn(ntohs(_server_addr.sin_port));

	if (listen(_sockfd, MAX_ACCEPT_QUEUE) < 0)
	{
		close(_sockfd);
		throw server_exception("listen() failed.\nShutting down server.\n");
	}
	logn("Socket listening"); 
}

server::~server()
{
	log("Server destructor for\nPort: ");
	logn(_port);
	log("Socket: ");
	logn(_sockfd);
}