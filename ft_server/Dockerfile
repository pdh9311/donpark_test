FROM	debian:buster

LABEL	maintainer="donpark@student.42seoul.kr"

RUN	apt-get update && \
	apt-get -y install \
	vim \
	wget \
	nginx \
	openssl \
	mariadb-server \
	php-mysql \
	php-mbstring \
	php7.3-fpm

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE	80 443

CMD 	bash run.sh
