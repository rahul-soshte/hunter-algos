if __name__ == "__main__":

	p=5
	g=3

	a = int(input("Enter a private key for Alice: "))
	b = int(input("Enter a private key for Bob: "))

	x = (g**a)%p
	y = (g**b)%p

	bobreceived=x
	alicereceived=y

	print("Computation of symmetric keys:")
	ka=(alicereceived**a) % p
	kb=(bobreceived**b) % p 

	print("Shared secret key is {}".format(ka))
	print("Shared secret key is {}".format(kb))

	print("Primitive Roots:")
	for i in range(1,p):
		print("{} {}" .format(i , (g**i) % p ))