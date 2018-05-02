data = []
n = int(raw_input('Enter how many elements you want: '))
for i in range(0, n):
    x = raw_input('Enter the numbers into the array: ')
    data.append(x)
print(data)
newdata = []
i=0
j=0
m=len(data)*3
n=len(data)
while i < m and j < n :
    newdata.append(data[j])
    if j==n-1:
    	j=-1
    i += 1
    j += 1	

print 'Repeating Three Times'
print ', '.join(newdata)




	

