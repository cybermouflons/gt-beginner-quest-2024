# Diffie-Hellman

[![Try in PWD](https://raw.githubusercontent.com/play-with-docker/stacks/master/assets/images/button.png)](https://labs.play-with-docker.com/?stack=https://raw.githubusercontent.com/cybermouflons/gt-beginner-quest-2024/master/crypto/diffie-hellman/docker-compose.yml)


**Category**: crypto

**Author**: feltf

## Description

Play the role of Bob (one of the two parties) in the Diffie-Hellman key
exchange algorithm to obtain the shared secret!

Then decrypt the encrypted flag that Alice will send to you!

You don't have to implement the cryptographic algorithms from scratch. Take a look at the
python crypto library [PyCryptodome](https://pycryptodome.readthedocs.io/en/latest/),
it will help you to decrypt the flag. 



## Run locally

Launch challenge:
```
curl -sSL https://raw.githubusercontent.com/cybermouflons/gt-beginner-quest-2024/master/crypto/diffie-hellman/docker-compose.yml | docker compose -f - up -d
```

Shutdown challenge:
```
curl -sSL https://raw.githubusercontent.com/cybermouflons/gt-beginner-quest-2024/master/crypto/diffie-hellman/docker-compose.yml | docker compose -f - down
```
