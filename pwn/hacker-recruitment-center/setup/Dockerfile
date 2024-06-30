FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat gcc-multilib

RUN addgroup --system ctf && adduser --system --group ctf

USER ctf
WORKDIR /home/ctf

COPY ./challenge .
COPY ./wrap.sh .
COPY ./flag.txt .

# RUN chmod +x ./wrap.sh ./challenge

EXPOSE 1337
CMD ["socat", "-v","TCP-LISTEN:1337,reuseaddr,fork", "EXEC:'./wrap.sh'"]
