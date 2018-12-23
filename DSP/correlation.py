import numpy
import math

def autocorrelation():
	signaldata=[]
	print("Enter the values of X(n)")
	signaldata = [] # create empty list
	number2 = int(input('Please enter the number of amplitudes: '))

	for i in range(0, number2): # set up loop to run 10 times
		number = int(input('Please enter a number: ')) # prompt user for number
		signaldata.append(number) # append to our_list
	
	origin = int (input("Origin is at position from the total length of 0-" + str(number2-1)+" "))

	signaldatafold=foldsignal(signaldata,origin)

	str1 = ','.join(str(e) for e in signaldata)
	print("X(n)=["+str1+"]")
	str2 = ','.join(str(e) for e in signaldatafold)
	print("X(-n)=["+str2+"]")

	i = len(signaldata)
	
	a = numpy.zeros(shape=(i,i))
	y=[]

	for g in range(0,2*i-1):
		y.append(0)

	for m in range(0,i):
		for j in range(0,i):
			a[j][m]=signaldata[m]*signaldatafold[j]

	for h in range(0,i):
		for o in range(0,i):
				y[h+o] += a[o][h]

	str3 = ','.join(str(e) for e in y)	
	
	print("Correlation coefficient ")		
	print("Y(n)=["+str3+"]")			

def crosscorrelation():
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

	origin = int (input("Origin is at position for 2nd signal from the total length of 0-" + str(number3-1)+" "))
	
	secondsignalfold=foldsignal(my_list2,origin)
	# print("X(n)="+my_list)
	str1 = ','.join(str(e) for e in my_list)
	print("X(n)=["+str1+"]")
	# 'X(n)=[{}]'.format(str1)
	str2 = ','.join(str(e) for e in secondsignalfold)
	print("h(-n)=["+str2+"]")

	a = numpy.zeros(shape=(number3,number2))


	y=[]

	for g in range(0,number2+number3-1):
		y.append(0)

	for m in range(0,number2):
		for j in range(0,number3):
			a[j][m]=my_list[m]*secondsignalfold[j]
	
	for h in range(0,number2):
		for o in range(0,number3):
			y[o+h] += a[o][h]

	str3 = ','.join(str(e) for e in y)
	print("Y(n)=["+str3+"]")


	if(len(my_list)>len(my_list2)):
		bigger=len(my_list)
		flag=1
	elif len(my_list)==len(my_list2):
		bigger=len(my_list2)
		flag=0
	else:
		bigger=len(my_list2)
		flag=2


	if flag==0:
		for i in range(len(my_list),bigger):
			my_list.append(0)
	elif flag==1:
		for i in range(len(my_list2),bigger):
			my_list2.append(0)


	meanX=numpy.mean(my_list)

	meanY=numpy.mean(my_list2)

	print(meanX)

	print(meanY)

	xminusmeansum=[]

	yminusmeansum=[]

	yminusmeansumsquare=0
	
	xminusmeansumsquare=0


	for i in range(0,len(my_list)):
		val=my_list[i] - meanX
		xminusmeansum.append(val)
		xminusmeansumsquare += (val)**2

	for y in range(0,len(my_list2)):
		val2 = my_list2[y] - meanY
		yminusmeansum.append(val2)
		yminusmeansumsquare += (val2)**2

	print(xminusmeansum)
	print(yminusmeansum)
	print(xminusmeansumsquare)
	print(yminusmeansumsquare)
	multipliedoutput=0

	for m in range(0, bigger):
		multipliedoutput += xminusmeansum[m]*yminusmeansum[m]

	print(multipliedoutput)

	rootxminusmeansumsquare=math.sqrt(xminusmeansumsquare)
	rootyminusmeansumsquare=math.sqrt(yminusmeansumsquare)
	denom=rootyminusmeansumsquare*rootxminusmeansumsquare
	r=(multipliedoutput)/denom

	print("Correlation coefficient")
	print(r)



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

	return mergedsignal

if __name__ == "__main__":
	
	option = int(input('Type 1 for auto correlation and 2 for cross correlation '))
	
	if(option==1):
		autocorrelation()
	elif(option==2):
		crosscorrelation()
