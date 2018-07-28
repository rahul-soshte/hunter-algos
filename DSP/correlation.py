import numpy

def start():
	print("Enter the values of X(n)")
	our_list = [] # create empty list
	number2 = int(input('Please enter the number of amplitudes: '))

	for i in range(0, number2): # set up loop to run 10 times
		number = int(input('Please enter a number: ')) # prompt user for number
		our_list.append(number) # append to our_list
	print(our_list)
	origin = int (input("Origin is at position from the total length of 0-" + str(number2-1) ))
	return our_list,origin

def autocorrelateoutput(signaldata,origin):
	signaldatafold=signaldata[::-1]
	print(signaldatafold)
	i = len(signaldata)
	a = numpy.zeros(shape=(i,i))
	y=[]

	for g in range(0,2*i-1):
		y.append(0)

	for m in range(0,i):
		for j in range(0,i):
			a[j][m]=signaldata[m]*signaldatafold[j]

	for f in range(0,2*i-1):
		for h in range(0,i):
			for o in range(0,i):
				if(h + o == f):
					y[f] = y[f]+a[o][h]

	return y


def crosscorrelateoutput():
	my_list = []
	my_list2 = []

	number2 = int(input('Please enter the number of amplitudes for 1st signal: '))

	for i in range(0, number2): # set up loop to run 10 times
		number = int(input('Please enter a number: ')) # prompt user for number
		my_list.append(number) # append to our_list

	number3 = int(input('Please enter the number of amplitudes for 2nd signal: '))
	
	for i in range(0, number3): # set up loop to run 10 times
		number1 = int(input('Please enter a number: ')) # prompt user for number
		my_list2.append(number1) # append to our_list

	secondsignalfold = my_list2[::-1]

	a = numpy.zeros(shape=(number3,number2))
	print(a)
	y=[]

	for g in range(0,number2+number3-1):
		y.append(0)

	for m in range(0,number2):
		for j in range(0,number3):
			a[j][m]=my_list[m]*secondsignalfold[j]

	print(a)
	for f in range(0,number2+number3-1):
		for h in range(0,number2):
			for o in range(0,number3):
				if(h + o == f):
					y[f] = y[f]+a[o][h]
	return y

def foldsignal(signaldata,origin):
	my_list4=[]
	my_list5=[]

	for i in range(0, len(signaldata)):
		if(i<origin):
			my_list4.append(signaldata[i])
		else:
			my_list5.append(signaldata[i])

	my_list6=my_list4[::-1]
	my_list7=my_list5[::-1]
	mergedsignal=my_list7 + my_list6
	print(mergedsignal)

if __name__ == "__main__":
	# signaldata, origin=start()
	# print(signaldata)
	# foldedsignal=foldsignal(signaldata,origin)
	# output=autocorrelateoutput(signaldata,origin)
	# print(output)
	output2=crosscorrelateoutput()
	print(output2)