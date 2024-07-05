FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat gcc-multilib

RUN addgroup --system ctf && adduser --system --group ctf

COPY ./challenge /home/ctf
COPY ./flag.txt /home/ctf

RUN chmod +x /home/ctf/challenge
RUN chmod +r /home/ctf/flag.txt

USER ctf
WORKDIR /home/ctf

EXPOSE 1337
CMD ["socat", "-v","TCP-LISTEN:1337,reuseaddr,fork", "EXEC:'./challenge'"]
