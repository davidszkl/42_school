FROM debian:buster

RUN apt-get update  -y &&	\
	apt-get upgrade -y &&	\
	apt-get install -y mariadb-server vim

COPY tools/script.sh script.sh
COPY 50-server.cnf /etc/mysql/mariadb.conf.d/

ENTRYPOINT ["/bin/bash", "-x", "script.sh"]
