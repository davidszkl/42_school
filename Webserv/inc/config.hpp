#pragma once

#include "utilities.hpp"

/*
   config of a server instance.
   Instances of this class will be stored in a vector.
   thus a config file containing two server blocks will generate a vector of two config objects
   Please not that this class DOES NOT arrange anything in network byte order!
 */
class config
{
	public:
		typedef std::map<int, string>::iterator mapit;
		typedef std::map<int, string>::const_iterator mapcit;
		class location {
			public:
				bool autoindex;
				string path;			// contains location path last '/' will be removed
				string root;			// empty if none
				string index;			//empty if none
				string redirect;		// empty if no redirect
				string upload_dir;		//empty if upload not permitted
				vector<string> allowed_methods;
				/* return 0 if path does not match location. Otherwise length of path
				 url_path should be something like /ok/foo/bar */
				unsigned match_url(const string& url_path) const;
				location();
		};
		string server_name;
		unsigned short port;
		size_t max_body;
		map<int, string> error_pages; // error number, path/to/file
		vector<location> location_blocks;

		config();

		friend std::ostream& operator <<(std::ostream& o, const config::location& c);
		friend std::ostream& operator <<(std::ostream& o, const config& c);
};

std::vector<config> init_configs(const string& file_path);
