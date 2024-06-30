FROM python:2.7-slim

RUN addgroup --system ctf && adduser --system --group ctf

USER ctf
WORKDIR /home/ctf

COPY challenge.py .
COPY flag.txt .
COPY socat .

env PYTHONUNBUFFERED 1

EXPOSE 1337
CMD ["/home/ctf/socat", "-v","TCP-LISTEN:1337,reuseaddr,fork", "EXEC:'python challenge.py'"]
# ENTRYPOINT "bash"
