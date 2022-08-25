#include "webserver.hpp"
enum error_codes {
	VECTOR_INIT_ERROR = 1,
	RUNTIME_ERROR,
	FATAL_ERROR,
	CONFIG_ERROR,
	INVALID_ARGS
};

string read_args(int argc, char *argv[])
{
	if (argc == 1)
		return "./conf.d/default.conf";
	if (argc == 2)
		return argv[1];
	throw std::runtime_error("invalid number of arguments");
	return "";
}

int main(int argc, char *argv[], char *envp[])
{
	string path;
	try {
		path = read_args(argc, argv);
	} catch (const std::exception& e) {
		cerr << string("Invalid argument: ") + e.what() + "\n";
		return INVALID_ARGS;
	}
	vector<config> vec;
	try {
		vec = init_configs(path);
	}
	catch (std::exception& e) {
		cerr << "Error in " + path + ":\n\t" + e.what() + "\n";
		return CONFIG_ERROR;
	}
	try {
		webserver main_server(vec);
		main_server.envp = reinterpret_cast<char**>(envp);				//all servers initialized in webserver constructor
		main_server.listen_all();										//main function listening on all servers
	}
	catch (server::server_exception &e) {								//one of the servers couldn't be initialized
		cerr << e.what() << endl;
		return VECTOR_INIT_ERROR;
	}
	catch (webserver::webserver_exception &e) {							//runtime error: accept(), recv(), etc..
		cerr << e.what() << endl;
		return RUNTIME_ERROR;
	}
	catch (...) {														//other errors like bad_alloc
		cerr << "Fatal error.\nShutting down server..." << endl;
		return FATAL_ERROR;
	}
	return 0;
}
