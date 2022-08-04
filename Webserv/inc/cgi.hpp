#pragma once
#include "utilities.hpp"

/*
	checks if http message (header + body) is valid for a cgi response.
	full_message is the whole http message received from the client.
	Return 1 on success, 0 on failure or the number of error (415, 411 or 413);
	root -> root of location block
	location -> path of location block
	max_body -> max size of client body allowed
 */
int is_valid_for_cgi(const string& full_message, string root, const string& location, std::size_t max_body);

/*
	This function needs the first line of the http header and the body, so pass the full http message in full_message.
	root -> root of location block
	location -> path of location block
	ouput_fd is where the python script will write its output.
	The http message should be valid! (is_valid_for_cgi must have returned true with the same message/root)
	return values:
		0 -> success
		1 -> system error
		415 or 403 -> error page to display
 */
int execute_cgi(const string& full_message, string root, const string& location, const string& upload_pass, int output_fd, char **envp);

/*
header must end with \r\n\r\n. Everything after that is ignored.
if there is Content-Length: 200 in the header and name=="Content-Length"m then returns "200"
returns "" if not found
 */
string get_header_info(const string& header, const string& name);



//example test:
/*

#include <iostream>
#include <string>
#include "cgi.hpp"
#include "debug.hpp"

static std::string get_request()
{
	return "\
POST /upload.py HTTP/1.1\r\n\
Host: 4242\r\n\
Accept-Encoding:  gzip, deflate\r\n\
Accept-Language:  en-US,en;q=0.5\r\n\
Connection:  keep-alive\r\n\
Content-Length:  253\r\n\
Content-Type:  multipart/form-data; boundary=---------------------------186655929040397696981263301363\r\n\
Dnt:  1\r\n\
Origin: 4242\r\n\
Referer: 4242/upload\r\n\
Sec-Fetch-Dest:  document\r\n\
Sec-Fetch-Mode:  navigate\r\n\
Sec-Fetch-Site:  same-origin\r\n\
Sec-Fetch-User:  ?1\r\n\
Sec-Gpc:  1\r\n\
Upgrade-Insecure-Requests:  1\r\n\
User-Agent: 98.0) Gecko/20100101 Firefox/98.0\r\n\
\r\n\
-----------------------------186655929040397696981263301363\r\n\
Content-Disposition: form-data; name=\"file1\"; filename=\"ok.txt\"\r\n\
Content-Type: text/plain\r\n\
\r\n\
je suis beau\n\
et \n\
\n\
\n\
magnig=fique\n\
;\n\
\r\n\
-----------------------------186655929040397696981263301363--\r\n";
}

int main()
{
	std::string full_message = get_request();
	std::string root = "/media/martin/Bowser/webserv/cgi/cgi-bin";
	std::string location = "/";
	std::string upload_pass = "/tmpppp";
	std::size_t max_body = 500;

	int rval = is_valid_for_cgi(full_message, root, location, max_body);
	if (rval == 1)
	{
		rval = execute_cgi(full_message, root, location, upload_pass, 1);
		if (rval != 0)
		{
			log("Warning: execute_cgi returned a non-zero value: ");
			logn(rval);
		}
	}
	else
	{
		log("Warning: is_valid_for_cgi returned ");
		logn(rval);
	}
}

*/
