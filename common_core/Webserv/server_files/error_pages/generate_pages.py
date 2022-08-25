#!/usr/bin/env python3

def generate_page(message, number):
	f = open(f'{number}.html', 'w')
	f.write(f'''<!DOCTYPE html>
<head>
<title>{message}</title>
</head>
<body style="background-color:#ffc0cb">
<div id="main">
<div class="fof">
<h1>Error {number}</h1>
</div>
</div>
</body>
</html>''')


generate_page('OK', 200)
generate_page('CREATED', 201)
generate_page('ACCEPTED', 202)
generate_page('NO_CONTENT', 204)
generate_page('RESET_CONTENT', 205)
generate_page('PARTIAL_CONTENT', 206)

generate_page('MULTIPLE_CHOICES', 300)
generate_page('MOVED_PERMANENTLY', 301)
generate_page('FOUND', 302)
generate_page('SEE_OTHER', 303)
generate_page('NOT_MODIFIED', 304)
generate_page('USE_PROXY', 305)
generate_page('TEMPORARY_REDIRECT', 307)

generate_page('BAD_REQUEST', 400)
generate_page('UNAUTHORIZED', 401)
generate_page('FORBIDDEN', 403)
generate_page('NOT_FOUND', 404)
generate_page('METHOD_NOT_ALLOWED', 405)
generate_page('NOT_ACCEPTABLE', 406)
generate_page('PROXY_AUTHENTICATION_REQUIRED', 407)
generate_page('REQUEST_TIMEOUT', 408)
generate_page('CONFLICT', 409)
generate_page('GONE', 410)
generate_page('LENGTH_REQUIRED', 411)
generate_page('PRECONDITION_FAILED', 412)
generate_page('REQUEST_ENTITY_TOO_LARGE', 413)
generate_page('REQUEST_URI_TOO_LONG', 414)
generate_page('UNSUPPORTED_MEDIA_TYPE', 415)
generate_page('REQUESTED_RANGE_NOT_SATISFIABLE', 416)
generate_page('EXPECTATION_FAILED', 417)

generate_page('INTERNAL_SERVER_ERROR', 500)
generate_page('NOT_IMPLEMENTED', 501)
generate_page('BAD_GATEWAY', 502)
generate_page('SERVICE_UNAVAILABLE', 503)
generate_page('GATEWAY_TIMEOUT', 504)
generate_page('HTTP_VERSION_NOT_SUPPORTED', 505)

