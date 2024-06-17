from pwn import remote
import base64
import codecs

conn = remote('localhost', 1337)

conn.recvlines(3)

operations2 = ['add', 'mul', 'div', 'sub', 'mod']

operations2 = {
    'add': lambda x, y: x+y,
    'sub': lambda x, y: x-y,
    'mul': lambda x, y: x*y,
    'div': lambda x, y: x//y,
    'mod': lambda x, y: x % y,
}

for _ in range(1000):
    conn.recvline()
    q = conn.recvuntil(b'=').decode().split('(')
    operation = q[0]
    if operation in operations2.keys():
        x, y = map(int, q[1].split(')')[0].split(','))
        ans = str(operations2[operation](x, y))
    else:
        x = q[1].split(')')[0]
        if operation == 'b64e':
            ans = base64.b64encode(x.encode()).decode()
        elif operation == 'b64d':
            ans = base64.b64decode(x.encode()).decode()
        else:
            ans = codecs.encode(x, 'rot13')
    conn.sendline(ans.encode())

conn.interactive()
