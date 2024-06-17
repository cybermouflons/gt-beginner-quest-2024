import codecs


message = ""
with open("key_x.txt") as f:
    message = f.read()
    
r1 = codecs.decode(message, 'hex')
r2 = codecs.decode(r1, 'base64')
r3 = str(codecs.decode(r2, 'base64')).replace(" ","")[2:-1]
r4 = str(codecs.decode(r3, 'hex'))[2:-1]
r5 = codecs.decode(str(r4), 'rot-13')
print(r5)