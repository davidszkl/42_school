FROM debian:buster

RUN apt-get update  -y &&	\
	apt-get upgrade -y &&	\
	apt-get install -y nginx

COPY conf/default /etc/nginx/sites-available/wordpress.conf
COPY conf/certificate.crt /etc/nginx/certificate.crt
COPY conf/private.key /etc/nginx/private.key

RUN cd /etc/nginx/sites-enabled && \
	ln -s ../sites-available/wordpress.conf .

EXPOSE 443

COPY tools/script.sh script.sh

ENTRYPOINT ["/bin/bash", "script.sh"]
