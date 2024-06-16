from Cryptodome.Cipher import AES
from Cryptodome.Util.Padding import pad
from Cryptodome.Util.number import long_to_bytes
from hashlib import sha256

from secret import pin, FLAG

hash = sha256()
hash.update(str(pin).encode())

key = hash.digest()[16:32]
iv = b'Brute_Willis_ftw'
cipher = AES.new(key, AES.MODE_CBC, iv)

encrypted = cipher.encrypt(pad(FLAG, 16))
print(encrypted)
