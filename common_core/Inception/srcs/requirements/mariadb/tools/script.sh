#!/bin/bash

service mysql start

if [ ! -d /var/lib/mysql/wordpress_db ] ; then

mysql --no-defaults -u root -e " \
	CREATE DATABASE wordpress_db; \
	GRANT ALL ON wordpress_db.* TO 'wpuser'@'%' \
	IDENTIFIED BY \"$MARIADB_WPUSER_PASSWD\" WITH GRANT OPTION; \
	ALTER USER 'root'@'localhost' IDENTIFIED BY '$MARIADB_ROOT_PASSWD'; \
	FLUSH PRIVILEGES;"

mysqladmin -p$MARIADB_ROOT_PASSWD shutdown;
fi
mysqld_safe