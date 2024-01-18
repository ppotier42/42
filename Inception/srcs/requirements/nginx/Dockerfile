FROM debian:buster

RUN apt update
RUN apt upgrade

RUN apt-get update
RUN	apt-get install nginx -y
RUN apt install openssl -y
RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/ppotier.key -out /etc/ssl/certs/ppotier.crt -subj "/C=CH/ST=Lausanne/L=Lausanne/O=42 School/OU=ppotier/CN=ppotier/";

RUN chmod 755 /var/www/html
RUN mkdir -p /var/www/html && chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html/

COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]