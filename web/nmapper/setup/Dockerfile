# Use the official Python base image
FROM python:3.9-slim

RUN apt update && apt install -y nmap

WORKDIR /app

COPY ./app/requirements.txt /app/requirements.txt

RUN pip install --no-cache-dir -r requirements.txt

COPY ./app /app/

EXPOSE 80

ENTRYPOINT ["python3", "/app/app.py"]
