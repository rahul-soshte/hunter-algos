import os
import ast

def string2bits(s=""):
	return [bin(ord(x))[2:].zfill(8) for x in s]

def bit2strings(b=None):
	return ''.join([chr(int(x,2)) for x in b])


f = open("exampleFile.txt", "r")
if not os.path.exists('exampleFile_8_binary.txt'):
    f1 = open("exampleFile_8_binary.txt", "x")
else:
	os.remove("exampleFile_8_binary.txt")

f1 = open("exampleFile_8_binary.txt", "a")

for x in f:
  f1.write(str(string2bits(x)))

f1.close()
f3 = open("exampleFile_8_binary.txt", "r")
res = ast.literal_eval(f3.read()) 
f4 = open("exampleFile_8_binary_converted_back.txt", "w")
f4.write(bit2strings(res))
f4.close()