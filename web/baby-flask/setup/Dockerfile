# Use the official Python base image
FROM python:3.9-slim

RUN apt-get update && apt-get install -y curl gcc nginx supervisor

COPY flag.txt /flag.txt
COPY entrypoint.sh /entrypoint.sh
RUN bash /entrypoint.sh

WORKDIR /app

COPY ./app/requirements.txt /app/requirements.txt

RUN pip install --no-cache-dir -r requirements.txt

COPY ./app /app/

EXPOSE 80

RUN rm /etc/nginx/sites-enabled/default
COPY conf/app.conf /etc/nginx/sites-enabled/app

COPY supervisor.conf /etc/supervisor/conf.d/supervisor.conf

ENTRYPOINT ["/usr/bin/supervisord", "-c", "/etc/supervisor/conf.d/supervisor.conf"]
