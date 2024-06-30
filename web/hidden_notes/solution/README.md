
Challengers should notice when visiting their notes the first note starts with `6`

From this, they should understand there must be a previous value `1`, which they should check

This shows the object ID generation is weak since it is easily guessable, but also due to the lack of access controls 
the attacker can read the administrator's note.

Visiting the URL:
```
http://<URL>/notes/3
```

Reveals the flag