# Use the official Python base image
FROM python:3.9-slim

RUN apt-get update && apt-get install -y gcc

COPY flag.txt /flag.txt
# Make the flag file readable only by /readflag
RUN chmod 400 /flag.txt

COPY readflag /tmp/readflag
RUN gcc -o /readflag /tmp/readflag/readflag.c
RUN chmod 4755 readflag

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

WORKDIR /app

RUN useradd -m baby && chown -R baby:baby /app

COPY --chown=baby:baby ./app/requirements.txt /app/requirements.txt

RUN pip install --no-cache-dir -r requirements.txt

COPY --chown=baby:baby ./app /app/

USER baby

EXPOSE 1337

ENTRYPOINT ["/entrypoint.sh"]
