import secrets
from secret import FLAG
from Crypto.Protocol.KDF import HKDF
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Hash import SHA256
from Crypto.Util.number import long_to_bytes

class DiffieHellman:
    def __init__(self) -> None:
        # Diffie-Hellman group (2048-bit MODP Group)
        self.p = 0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AACAA68FFFFFFFFFFFFFFFF
        self.q = (self.p-1)//2 # group order
        self.g = 2 # group generator

    def start(self):
        print("""
=============================================================
|                                                           |
|                Diffie-Hellman Key Exchange:               |
|             Derive a secret to decrypt the flag           |
|                                                           |
=============================================================
|                          (p,q,g)                          |
|                                                           |
|       Alice                                  Bob (you)    |
|         O                                       O         |
|        /|\                                     /|\        |
|        / \                                     / \        |
| flag                                                      |
|                                                           |
| chose random a in [1,q]                                   |
| A = g^a mod p                                             |
|                                                           |
|                             A                             |
|                  ---------------------->                  |
|                                                           |
|                                   chose random b in [1,q] |
|                                             S = A^b mod p |
|                                             B = g^b mod p |
|                                                           |
|                             B                             |
|                  <----------------------                  |
|                                                           |
| S = B^a mod p                                             |
| K = HKDF-SHA256(S, 16, "")                                |
|                                                           |
|                  c, IV = AES-CBC(K, flag)                 |
|                  ---------------------->                  |
=============================================================""")
        
        print(f"(Info) p={self.p}")
        print(f"(Info) q={self.q}")
        print(f"(Info) g={self.g}")
        
        a = secrets.randbelow(self.q) + 1 # Alice's secret value
        A = pow(self.g, a, self.p) # Alice's public group member
        print(f"(Alice) Bob A is {A}")
        try:
            B = int(input("(Bob) Alice B is "))
        except:
            print("(Error) B is an integer value member of the group (mod p)")
            return

        if pow(B, self.q, self.p) != 1:
            print("(Error) B is not in the group (mod p)")
            return
        
        S = pow(B, a, self.p)
        K = HKDF(long_to_bytes(S), 16, "", SHA256)

        cipher = AES.new(K, AES.MODE_CBC)
        c = cipher.encrypt(pad(FLAG, AES.block_size))
        
        print(f"(Alice) Bob the encrypted flag (in hex) is {c.hex()} with IV {cipher.iv.hex()}")

        
dhke = DiffieHellman()
dhke.start()
