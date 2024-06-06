# Use the official Python base image
FROM python:3.9-slim

RUN apt-get update && apt-get install -y gcc

COPY flag.txt /flag.txt
# Make the flag file readable only by /readflag
RUN chmod 400 /flag.txt

COPY readflag /tmp/readflag
RUN gcc -o /readflag /tmp/readflag/readflag.c
RUN chmod 4755 readflag


WORKDIR /app

RUN useradd -m master && chown -R master:master /app

COPY --chown=master:master ./app/requirements.txt /app/requirements.txt

RUN pip install --no-cache-dir -r requirements.txt

COPY --chown=master:master ./app /app/

USER master

EXPOSE 1337

CMD ["python", "/app/app.py"]
