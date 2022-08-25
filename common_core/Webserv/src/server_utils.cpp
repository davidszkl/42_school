#include "webserver.hpp"
#include "utilities.hpp"
#include "debug.hpp"

bool find_crlf(string str) {
	if (str.find("\r\n\r\n") != string::npos)
		return true;
	return false;
}

string slurp_file(string file) {
	ifstream stream(file.c_str());
	stringstream buffer;
	buffer << stream.rdbuf();
	string file_content(buffer.str());
	if (!(file == "server_files/favicon.ico"))
		logn("WEBPAGE\n" + file_content + "WEBPAGE\n");
	return file_content;
}

string i_to_str(int nbr) {
	stringstream ss;
    string s;
    ss << nbr;
    s = ss.str();
    return s;
}

string my_get_line(string from) {
	string to;
	for (size_t n = 0; from[n] && from[n] != '\n'; n++)
		to += from[n];
	return to;
}

string read_header_line(string from) {
	string str;
	for (size_t n = 0; from[n]; n++)
	{
		str += from[n];
		if (str[n] == '\n' && str.size() > 2 && str[n - 1] == '\r')
			break;
	}
	return str;
}

void poll_result(const pollfd & fd){
	cerr << "events  : "												\
		 << (fd.events & POLLIN 	? " POLLIN |"	: "        |")		\
		 << (fd.events & POLLHUP	? " POLLHUP |"	: "         |")		\
		 << (fd.events & POLLERR	? " POLLERR |"	: "         |")		\
		 << (fd.events & POLLPRI	? " POLLPRI |"	: "         |")		\
		 << (fd.events & POLLOUT	? " POLLOUT |"	: "         |")		\
		 << (fd.events & POLLNVAL	? " POLLNVAL |"	: "          |")	<< endl;
	cerr << "revents : " 												\
		 << (fd.revents & POLLIN 	? " POLLIN |"	: "        |")		\
		 << (fd.revents & POLLHUP	? " POLLHUP |"	: "         |")		\
		 << (fd.revents & POLLERR	? " POLLERR |"	: "         |")		\
		 << (fd.revents & POLLPRI	? " POLLPRI |"	: "         |")		\
		 << (fd.revents & POLLOUT	? " POLLOUT |"	: "         |")		\
		 << (fd.revents & POLLNVAL	? " POLLNVAL |"	: "          |")	<< endl;
}

void	webserver::clear_request() {
	_http_request._full_request.clear();
	_http_request._header.clear();
	_http_request._body.clear();
	_http_request._method.clear();
	_http_request._uri.clear();
	_http_request._version.clear();
	_http_request._header_lines.clear();
	_http_request._path.clear();
}

string get_code_description(int code) {
	switch (code) {
		case OK :
			return " OK";
		case CREATED :
			return " CREATED";
		case ACCEPTED :
			return " ACCEPTED";
		case NO_CONTENT :
			return " NO_CONTENT";
		case RESET_CONTENT :
			return " RESET_CONTENT";
		case PARTIAL_CONTENT :
			return " PARTIAL_CONTENT";
		case MULTIPLE_CHOICES :
			return " MULTIPLE_CHOICES";
		case MOVED_PERMANENTLY :
			return " MOVED_PERMANENTLY";
		case FOUND :
			return " FOUND";
		case SEE_OTHER :
			return " SEE_OTHER";
		case NOT_MODIFIED :
			return " NOT_MODIFIED";
		case USE_PROXY :
			return " USE_PROXY";
		case TEMPORARY_REDIRECT :
			return " TEMPORARY_REDIRECT";
		case BAD_REQUEST :
			return " BAD_REQUEST";
		case UNAUTHORIZED :
			return " UNAUTHORIZED";
		case FORBIDDEN :
			return " FORBIDDEN";
		case NOT_FOUND :
			return " NOT_FOUND";
		case METHOD_NOT_ALLOWED :
			return " METHOD_NOT_ALLOWED";
		case NOT_ACCEPTABLE :
			return " NOT_ACCEPTABLE";
		case PROXY_AUTHENTICATION_REQUIRED :
			return " PROXY_AUTHENTICATION_REQUIRED";
		case REQUEST_TIMEOUT :
			return " REQUEST_TIMEOUT";
		case CONFLICT :
			return " CONFLICT";
		case GONE :
			return " GONE";
		case LENGTH_REQUIRED :
			return " LENGTH_REQUIRED";
		case PRECONDITION_FAILED :
			return " PRECONDITION_FAILED";
		case REQUEST_ENTITY_TOO_LARGE :
			return " REQUEST_ENTITY_TOO_LARGE";
		case REQUEST_URI_TOO_LONG :
			return " REQUEST_URI_TOO_LONG";
		case UNSUPPORTED_MEDIA_TYPE :
			return " UNSUPPORTED_MEDIA_TYPE";
		case REQUESTED_RANGE_NOT_SATISFIABLE :
			return " REQUESTED_RANGE_NOT_SATISFIABLE";
		case EXPECTATION_FAILED :
			return " EXPECTATION_FAILED";
		case INTERNAL_SERVER_ERROR :
			return " INTERNAL_SERVER_ERROR";
		case NOT_IMPLEMENTED :
			return " NOT_IMPLEMENTED";
		case BAD_GATEWAY :
			return " BAD_GATEWAY";
		case SERVICE_UNAVAILABLE :
			return " SERVICE_UNAVAILABLE";
		case GATEWAY_TIMEOUT :
			return " GATEWAY_TIMEOUT";
		default :
			return " ";
	}
}