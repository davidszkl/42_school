#pragma once

#include <algorithm>    //find
#include <vector>		//webserver, config
#include <map>			//config, server

#include <string>		//string_utils, config, cgi
#include <cstring>		//server
#include <cstdlib>		//webserver
#include <utility>		//config

#include <fstream>		//webserver
#include <sstream>		//string_utils, server
#include <iostream>		//server, debug, config

#include <fcntl.h>		//server
#include <unistd.h>		//server
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

#include <arpa/inet.h>	//server
#include <netinet/in.h>	//server
#include <poll.h>		//server

#include <stdexcept>	//server

#include "debug.hpp"

using namespace std;

void 		poll_result(const pollfd& fd);
bool		find_crlf(string str);
bool		is_post(string str);
bool	 	file_exists (const string& name);
string		my_get_line(string from );
string		i_to_str(int nbr);
string		slurp_file(string file);
string		read_header_line(string from);
string		get_code_description(int code);
size_t		get_read_bytes(string str);