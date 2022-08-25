#!/usr/bin/env python3

"""
cgi script.
if REQUEST_METHOD env var == GET, then get QUERY_STRING form env vars.
Else if REQUEST_METHOD == POST, get it from stdin
"""

import os, cgitb, sys

cgitb.enable()

print('HTTP/1.1 200 OK\r')
print('Content-type: text/html\r')
print('\r')

print('<html>')
print('<head>')
print('Cool Program Omg')
print('</head>')

print('<body>')

print('<h1>sys.argv:', sys.argv, '</h1>')

print('<output>')
request_method = os.getenv('REQUEST_METHOD')
print('REQUEST_METHOD ==', request_method)
print('</output>')
if request_method == None:
	print('<output>No request method defined. Defaulting to GET</output>')
	request_method = 'GET'

if request_method == 'GET':
	query_string = os.getenv('QUERY_STRING')
elif request_method == 'POST':
	print('<debug_ouput>Reading query string from stdin...</debug_output>')
	query_string = sys.stdin.read()
else:
	print('<output>Invalid request method:', request_method, '</ouput>')

path_info = os.getenv('PATH_INFO')

print('<output>')
print("QUERY_STRING ==", query_string)
print('</output>')
print("PATH_INFO ==", path_info)
if query_string != None:
	print('<output>')
	print('query_string len:', len(query_string))
	print('</output>')
if path_info != None:
	print('<output>')
	print('path_info len:', len(path_info))
	print('</output>')

print("CONTENT_TYPE ==", os.getenv('CONTENT_TYPE'));

print('</body>')
print('</html>')
