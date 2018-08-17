
import operator

if __name__ == "__main__":
	val=[]
	keystream=[]
	ciphertext=[]
	autokeykey=7
	text  = "the house is being sold tonight"
	# text  = "hello"
	for c in text:
		if c==' ':
			# val.append("blank")
			pass
		else:
			val.append(ord(c)-ord('a'))

	keystream.append(autokeykey)

	keystream = keystream + val[:-1]

	for i in range(0, len(val)):
			val2 = (val[i] + keystream[i]) % 26
			ciphertext.append(val2)


	for m in range(0, len(ciphertext)):
		ciphertext[m]=chr( ciphertext[m] + ord('A'))


	# ciphertext=list(map(operator.add,val,keystream))



	print(val)
	print(keystream)
	print(ciphertext)
