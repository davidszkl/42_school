FROM debian:buster

RUN apt-get update -y  && \
	apt-get upgrade -y && \
	apt-get install -y wget vim gnupg2

RUN wget -q https://packages.sury.org/php/apt.gpg -O- |		\
	apt-key add - && 										\
	echo "deb https://packages.sury.org/php/ buster main" |	\
	tee /etc/apt/sources.list.d/php.list &&					\
	apt-get update -y &&									\
	apt-get install -y php php-fpm php8.1-mysql &&			\
	apt-get install -y mariadb-client

RUN mkdir -p /var/www/html/wordpress/public_html

RUN cd /var/www/html/wordpress/public_html && \
wget https://wordpress.org/latest.tar.gz && \
tar -zxvf latest.tar.gz && \
mv wordpress/* . && \
rm -rf wordpress

COPY conf/wp-config.php /var/www/html/wordpress/public_html/wp-config.php
COPY conf/www.conf /etc/php/8.1/fpm/pool.d/www.conf

RUN cd /var/www/html/wordpress/public_html &&	\
	chown -R www-data:www-data * &&				\
	chmod -R 755 *

RUN apt-get install curl -y && \
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp && \
	wp --info


COPY tools/script.sh script.sh
ENTRYPOINT ["/bin/bash", "-x", "script.sh"]
