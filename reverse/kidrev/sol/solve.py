from ctypes import CDLL
libc = CDLL("libc.so.6")
libc.srand(1337)
out='1c66 211e 1105 46e0 b90 607b 1862 74d4 190 2a11 30e0 2ce0 2667 305d 3378 2080 208c 11e 2c55 2554 2f2a 32a0'.split()
for o in out:
    x=libc.rand()%255
    print(chr((int(o,16)^x)//x),end='')