
import operator

if __name__ == "__main__":
	val=[]
	keystream=[]
	ciphertext=[]
	autokeykey=7

	text  = "the house is being sold tonight"

	for c in text:
		if c==' ':
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

	ciphertextstring=''.join(ciphertext)
	
	print(ciphertextstring)

	plaintext=[]
	
	for m in range(0, len(ciphertext)):
		val3= ((ord(ciphertext[m])-ord('A')) - keystream[m]) % 26
		plaintext.append(val3)

	print(plaintext)
	
	for m in range(0, len(plaintext)):
		plaintext[m]=chr( plaintext[m] + ord('A'))	

	plaintextstring=''.join(plaintext)

	print(plaintextstring)



