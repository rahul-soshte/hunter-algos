import os
import ast

def string2bits(s=""):
	return [bin(ord(x))[2:].zfill(8) for x in s]

def bit2strings(b=None):
	return ''.join([chr(int(x,2)) for x in b])

#s= "Hello"
#b=string2bits(s)
#convertedback=bit2strings(b)
#print(b)
#print(convertedback)

f = open("exampleFile.txt", "r")
# print(f.read())
# f1 = open("exampleFile_8_binary.txt", "x")

if not os.path.exists('exampleFile_8_binary.txt'):
    f1 = open("exampleFile_8_binary.txt", "x")
else:
	os.remove("exampleFile_8_binary.txt")

f1 = open("exampleFile_8_binary.txt", "a")

# f = open("demofile.txt", "r")
for x in f:
  f1.write(str(string2bits(x)))

f1.close()

f2 = open("exampleFile_8_binary.txt", "r")
print(f2.read())


if not os.path.exists('exampleFile_8_binary_converted_back.txt'):
    f4 = open("exampleFile_8_binary_converted_back.txt", "x")
else:
	os.remove("exampleFile_8_binary_converted_back.txt")

f4 = open("exampleFile_8_binary_converted_back.txt", "a")


def Convert(string): 
    li = list(string.split(" ")) 
    return li 
f3 = open("exampleFile_8_binary.txt", "r")

# print ("initial string", ini_list) 
# print (type(ini_list)) 
  
# Converting string to list 
# res = f3.read().strip('][').split(',') 
res = ast.literal_eval(f3.read()) 
 
# print ("final list", res) 
print(bit2strings(res))

# if not os.path.exists('exampleFile_8_binary_converted_back.txt'):
#     f4 = open("exampleFile_8_binary_converted_back.txt", "x")
# else:
# 	os.remove("exampleFile_8_binary_converted_back.txt")

f4 = open("exampleFile_8_binary_converted_back.txt", "w")
f4.write(bit2strings(res))