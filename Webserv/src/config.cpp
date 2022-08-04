#include "string_utils.hpp"
#include "config.hpp"
#include "debug.hpp"
#include <unistd.h>
#include <limits.h>
#include <algorithm>
#include <iostream>

std::ostream& operator <<(std::ostream& o, const config::location& c)
{
	o << "---location " + c.path + ":---\n";
	o << '>' << "root: " << c.root << '\n';
	o << '>' << "index: " << c.index << '\n';
	o << '>' << "autoindex: " << c.autoindex << '\n';
	o << '>' << "allowed_methods:";
	for(std::size_t i = 0; i < c.allowed_methods.size(); i++)
		o << ' ' << i << ":" << c.allowed_methods[i];
	o << '\n';
	o << '>' << "redirect: " << c.redirect << '\n';
	o << '>' << "upload_dir: " << c.upload_dir << '\n';
	return o;
}

std::ostream& operator <<(std::ostream& o, const config& c)
{
	o << "======config of " + c.server_name + ":" << c.port << "======\n";
	o << "max_body: " << c.max_body << '\n';
	o << "error_pages:\n";
	for (config::mapcit it = c.error_pages.begin(); it != c.error_pages.end(); it++)
		o << it->first << ": " << it->second << '\n';
	o << "location_blocks:\n";
	for (std::size_t i = 0; i < c.location_blocks.size(); i++)
		o << c.location_blocks[i];
	return o;
}

unsigned config::location::match_url(const std::string& url_path) const {
	std::string url_path_tmp = url_path;
	std::string path_tmp = path;

	if (url_path.length() < path.length())
		return 0;
	if (url_path.compare(0, path.length(), path) != 0)
		return 0;
	if (url_path[url_path.length() - 1] != '/')
		url_path_tmp += "/";
	if (path[path.length() - 1] == '/')
		path_tmp = path.substr(0, path.length() - 1);
	if (path_tmp.length() == url_path_tmp.length())
		return path.length();
	if (url_path_tmp[path_tmp.length()] == '/')
		return path.length();
	return 0;
}

config::config()
: port(0), max_body(500)
{
	const std::string default_error_path = "./server_files/error_pages/";
	for(int i = 200; i <= 206; i++)
		error_pages[i] = default_error_path + to_string(i) + ".html";
	for(int i = 300; i <= 307; i++)
		error_pages[i] = default_error_path + to_string(i) + ".html";
	for(int i = 400; i <= 417; i++)
		error_pages[i] = default_error_path + to_string(i) + ".html";
	for(int i = 500; i <= 505; i++)
		error_pages[i] = default_error_path + to_string(i) + ".html";
}

config::location::location()
: autoindex(false) {}
