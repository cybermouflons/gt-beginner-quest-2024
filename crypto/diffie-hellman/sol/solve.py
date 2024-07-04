#!/usr/bin/env python3
import os
import secrets

from telnetlib import Telnet

from Crypto.Protocol.KDF import HKDF
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from Crypto.Hash import SHA256
from Crypto.Util.number import long_to_bytes


def solve(tn: Telnet):
    # Read p
    tn.read_until(b"p=")
    p = int((tn.read_until(b"\n")[:-1]))

    # Read q
    tn.read_until(b"q=")
    q = int((tn.read_until(b"\n")[:-1]))

    # Read g
    tn.read_until(b"g=")
    g = int((tn.read_until(b"\n")[:-1]))

    # Read Alice's public A
    tn.read_until(b"Bob A is ")
    A = int((tn.read_until(b"\n")[:-1]))
    
    # chose random b
    b = secrets.randbelow(q) + 1
    # compute Bob's public B
    B = pow(g, b, p)
    # send public B
    tn.read_until(b"Alice B is ")
    tn.write(str(B).encode() + b"\n")
    
    # Read encrypted flag
    tn.read_until(b"Bob the encrypted flag (in hex) is ")
    c = bytes.fromhex(tn.read_until(b" ")[:-1].decode())
    
    # Read IV
    tn.read_until(b"with IV ")
    IV = bytes.fromhex(tn.read_until(b"\n")[:-1].decode())
    
    # Until here it can be done manually, i.e., extract info from server responses
    S = pow(A, b, p)
    K = HKDF(long_to_bytes(S), 16, "", SHA256)

    cipher = AES.new(K, AES.MODE_CBC, IV)
    flag = unpad(cipher.decrypt(c), AES.block_size)
    print(flag)

if __name__ == "__main__":
    if "REMOTE" in os.environ:
        HOSTNAME = ""
    else:
        HOSTNAME = "localhost"
    PORT = 1337
    with Telnet(HOSTNAME, PORT) as tn:
        solve(tn)
