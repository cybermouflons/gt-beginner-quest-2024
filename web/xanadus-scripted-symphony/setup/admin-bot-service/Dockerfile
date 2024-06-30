# Use an official Node.js runtime as a parent image
FROM node:18

WORKDIR /app

ADD . /app

COPY flag.txt /flag.txt

RUN apt-get update && apt-get install -y \
    libasound2 \
    libatk1.0-0 \
    libc6 \
    libcairo2 \
    libcups2 \
    libdbus-1-3 \
    libexpat1 \
    libfontconfig1 \
    libgcc1 \
    libgconf-2-4 \
    libgdk-pixbuf2.0-0 \
    libglib2.0-0 \
    libgbm1 \
    libgtk-3-0 \
    libnss3

RUN npm install

EXPOSE 3000

CMD ["node", "index.js"]