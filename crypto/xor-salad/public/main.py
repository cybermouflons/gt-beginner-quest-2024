from Crypto.Util.number import bytes_to_long as b2l
from secret import FLAG,A,B,C
FLAG=b2l(FLAG)
assert A == b2l('🥒🥒🥒🥒🥒🥒🥒🥒🥒🥒🥒🥒🥒🥒🥒🥒'.encode())

assert B ^ A == b2l('🧅🧅🧅🧅🧅🧅🧅🧅🧅🧅🧅🧅🧅🧅🧅🧅'.encode()) ^ b2l('🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅'.encode())

assert B ^ C == b2l('🍋🍋🍋🍋🍋🍋🍋🍋🍋🍋🍋🍋🍋🍋🍋🍋'.encode())

salad = A ^ B ^ C ^ FLAG

print(salad)

#32044748876454659761763649612745889488449687984965417070150788708113761729751415887526854769841329766223092305434872099365412876811500785218456935012