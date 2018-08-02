def encryptMessage(msg):
	
	a = 17
	b = 20
	
	cipher = ""

	for i in range(0,len(msg)):

		if(msg[i] != ' '):
			cipher = cipher + chr(((( a * ( ord( msg[i] ) - ord('A')) ) + b) % 26 ) + ord('A'));
		else:
			cipher += msg[i]

	return cipher

def decryptCipher(cipherText):
	msg=""
	a_inv = 0
	flag = 0
	a = 17
	b = 20

	for i in range(0,26):
		flag = (a * i) % 26
		if flag == 1:
			a_inv = i

	for i in range(0, len(cipherText)):
		if( cipherText[i] != ' '):
			msg = msg + chr((((a_inv * ((ord(cipherText[i])+ord('A') - b)) % 26)) + ord('A')))
		else:
			msg += cipherText[i]

	return msg

if __name__ == "__main__":
	msg = "AFFINE CIPHER"
	cipherText = encryptMessage(msg);
	print(cipherText)
	decipheredtext = decryptCipher(cipherText)
	print(decipheredtext)