# Use the official Python base image
FROM python:3.9-slim

RUN apt update && apt install -y nmap

WORKDIR /app

COPY ./app/requirements.txt /app/requirements.txt

RUN pip install --no-cache-dir -r requirements.txt

COPY ./app /app/

COPY flag.txt /flag.txt
RUN mv /flag.txt /flag-$(tr -dc A-Za-z0-9 </dev/urandom | head -c 13 ; echo '').txt

EXPOSE 80

ENTRYPOINT ["python3", "/app/app.py"]
