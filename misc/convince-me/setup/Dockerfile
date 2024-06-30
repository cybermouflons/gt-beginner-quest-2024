FROM ubuntu:latest

RUN apt-get update && apt-get install -y socat python3 python3-requests

WORKDIR /app
COPY server.py .

EXPOSE 1337
CMD ["socat", "-v","TCP-LISTEN:1337,reuseaddr,fork", "EXEC:'/app/server.py'"]
