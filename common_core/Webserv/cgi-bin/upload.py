#!/usr/bin/env python3

import os, cgitb, sys
cgitb.enable()

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def is_multipart(content_type):
	if content_type == None or (len(content_type) > len("multipart/form-data; boundary=")\
	and content_type[:30] == "multipart/form-data; boundary="):
		return True
	return False

def append_pwd(upload_pass):
	if len(upload_pass) >= 2 and upload_pass[0:2] == './':
		upload_pass = upload_pass[2:]
	if len(upload_pass) >= 1 and upload_pass[0] != '/':
		upload_pass = os.getenv('PWD') + '/' + upload_pass
	return upload_pass

upload_pass = os.getenv("UPLOAD_PASS")
body = sys.stdin.read()
content_type = os.getenv("CONTENT_TYPE")

# eror checking
if not is_multipart(content_type):
    eprint(f"(upload.py): content_type is not multipart")
    exit(415)
if upload_pass == None or upload_pass == "":
    eprint(f"(upload.py): upload pass is empty or not defined")
    exit(403)

upload_pass = append_pwd(upload_pass)
eprint('final upload_pass:', upload_pass)

boundary = content_type[content_type.find("boundary=") + 9:]

# finding file body
begin = body.find('\r\n\r\n') + 4
end = body.find('\r\n--' + boundary + '--')
file_body = body[begin:end]

# finding filename and path
b1 = body.find('--' + boundary)
b1end = b1 + len(boundary) + 2
fnamebegin = b1end + body[b1end:].find('filename="') + 10
fnameend = fnamebegin + body[fnamebegin:].find('"\r\n')
file_name = body[fnamebegin:fnameend]

if upload_pass[-1] != '/':
    upload_pass += '/'

file_path = upload_pass + file_name

eprint(f"(upload.py): file to create: {file_path}")

try:
    fp = open(file_path, 'w')
except:
    eprint(f"(upload.py): cannot open {file_path}")
    exit(403)

eprint(f"(upload.py): created {file_path}")

fp.write(file_body)

fp.close()

response_body = f'''<HTML><HEAD><meta http-equiv="content-type" content="text/html;charset=utf-8">
<TITLE>Upload successful</TITLE></HEAD><BODY>
<H1>{file_name} has been uploaded</H1>
</BODY></HTML>'''

print(f'''HTTP/1.1 200 OK\r
Content-Type: text/html; charset=UTF-8\r
Content-Length: {len(response_body)}\r
\r
{response_body}''')
