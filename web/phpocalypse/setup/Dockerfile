FROM php:7.4-apache

WORKDIR /var/www/html

COPY css css
COPY images images
COPY uploads uploads
COPY index.php index.php
COPY upload.php upload.php

RUN chown -R www-data:www-data /var/www/html

COPY flag.txt /flag.txt


