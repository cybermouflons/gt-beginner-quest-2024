FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat python3 python3-pip

RUN mkdir /app
WORKDIR /app

COPY requirements.txt /app/
RUN pip install -r requirements.txt

COPY secret.py/ /app/
COPY server.py/ /app/

EXPOSE 1337
CMD ["socat", "-v","TCP-LISTEN:1337,reuseaddr,fork", "EXEC:'python3 /app/server.py'"]