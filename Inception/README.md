# Inception

System administration project aimed at learning docker, you have to setup a complete docker network with the following services:
- nginx with https on port 443
- mariadb
- wordpress + php-fpm
- a volume for mariadb and one for nginx and wordpress to share data

Since images can't be pulled from dockerhub they are re-written from debian or alpine

Concepts learned:
- Docker
- docker-compose
- configuration
- network troubleshooting
