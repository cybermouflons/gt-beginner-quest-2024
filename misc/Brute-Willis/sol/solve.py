from Cryptodome.Cipher import AES
from Cryptodome.Util.Padding import pad
from Cryptodome.Util.number import long_to_bytes
from hashlib import sha256

# From given output:
ciphertext = b'pZ\x06\xa9\x1a\xbe\xbb\xbb\xc1\xa0>\xcfI\xf3\xe2\xc5\xbai\xf5pYi\xf3~1?\xe7\xf3M3e\x17\x1e\xa0\xa7\xccb_\xbd/\x9a\xb4\xab{\xea|\xfc\xbd'


for pin in range(100000,999999):
    hash = sha256()
    hash.update(str(pin).encode())

    key = hash.digest()[16:32]
    iv = b'Brute_Willis_ftw'
    cipher = AES.new(key, AES.MODE_CBC, iv)

    flag = cipher.decrypt(ciphertext)
    if str(flag)[2:-1].startswith("GTBQ{"):
        print(pin,flag)
        exit(0)
    elif pin%100==0:
        print(pin)
