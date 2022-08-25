#pragma once

#include "utilities.hpp"
#include "config.hpp"

#define MAX_ACCEPT_QUEUE 128	//size of the queue for the socket

class server
{
public:

	server(vector<config> vector_config);
	~server();

	class server_exception : public std::runtime_error
	{
	public:
		server_exception(const char* what) : runtime_error(what) {}
	};

	friend class webserver;

private:

	vector<config>	_configs;
	string			_full_url;
	sockaddr_in		_server_addr;
	unsigned short	_port;
	int				_sockfd;

	typedef map<int, string>::iterator map_it;
};
