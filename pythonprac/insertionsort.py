if __name__ == "__main__":
	num_array = list()
	num = input("Enter how many elements you want:")
	print ('Enter numbers in array: ')
	for i in range(int(num)):
		n = input("num :")
		num_array.append(int(n))
	print ('Array: ',num_array)

	
	for i in range(1,int(num)):
		d=i
		while (d > 0 and num_array[d] < num_array[d-1]):
			t = num_array[d]
			num_array[d] = num_array[d-1]
			num_array[d-1]=t
			d=d-1

		i=i+1

	print("Sorted Array:",num_array)