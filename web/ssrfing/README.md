# SSRFing

[![Try in PWD](https://raw.githubusercontent.com/play-with-docker/stacks/master/assets/images/button.png)](https://labs.play-with-docker.com/?stack=https://raw.githubusercontent.com/cybermouflons/gt-beginner-quest-2024/master/web/ssrfing/docker-compose.yml)


**Category**: web

**Author**: Evangelospro

## Description

I've heard about this cool new way of surfing the web, it's called SSRFing! I've set up a server for you to try it out. Can you find the flag behind the admin portal?



## Run locally

Launch challenge:
```
curl -sSL https://raw.githubusercontent.com/cybermouflons/gt-beginner-quest-2024/master/web/ssrfing/docker-compose.yml | docker compose -f - up -d
```

Shutdown challenge:
```
curl -sSL https://raw.githubusercontent.com/cybermouflons/gt-beginner-quest-2024/master/web/ssrfing/docker-compose.yml | docker compose -f - down
```
