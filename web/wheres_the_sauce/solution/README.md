
Reading the `routes/index.js` file we can find all web application routes.

Here the challenger notices three endpoints:
 - GET / 
 - GET /flag-endpoint-1
 - OPTIONS /flag-endpoint-2


Further reading the source code shows the flag is split into two strings.

To reveal the first part of the flag, the challenger must do the following:
 - make a GET request to the `/flag-endpoint-1` 
 - Add the `secret_param1` query parameter equal to 1337
 - Add the `secret_param2` query parameter equal to 7331
 - Add the `give_me` header equal to `my_flag_please`

E.g:
```
curl -H "give_me: my_flag_please" "http://localhost:3000/flag-endpoint-1?secret_param1=1337&secret_param2=7331"
```

To reveal the second part of the flag, the challenger must do the following:
- make an OPTIONS request to `/flag-endpoint-2`

E.g:
```
curl -X OPTIONS "http://localhost:3000/flag-endpoint-2"
```
