compose_file=srcs/docker-compose.yml

up: images
	sudo docker-compose -f $(compose_file) up -d

down:
	sudo docker-compose -f $(compose_file) down

images: .mariadb .wp .nginx

.wp:
	sudo docker build -t wordpress_im srcs/requirements/wordpress/
	touch $@

.mariadb:
	sudo docker build -t mariadb_im srcs/requirements/mariadb/
	touch $@

.nginx:
	sudo docker build -t nginx_im srcs/requirements/nginx/
	touch $@

clean: down
	rm -rf .nginx .wp .mariadb
	docker volume rm $(shell docker volume ls -q)
	rm -rf /home/dszklarz/data/wordpress_volume/*
	rm -rf /home/dszklarz/data/mariadb_volume/*

volumes:
	mkdir -p /home/dszklarz/data/mariadb_volume
	mkdir -p /home/dszklarz/data/wordpress_volume

re: clean build

.PHONY: clean re images up down volumes
