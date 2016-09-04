/*
-Use 2-d array for sorting data
-find max no
-and go through every element of array and if less digits than max add that many zeroes to the start
-then for sorting go through each no and its digits 
-and send to the specific bucket
*/
#include<stdio.h>

void radsort(int a[][],int n,int max,int mndigit);
int findmax(int a[],int n);
int findNoOfDigits(int);
void addZero(int a[],int ndigit,int mndigit);

int main()
{
int n;
int i;

printf("Enter the number of elements to be sorted\n");
scanf("%d",&n);

int a[n][100];
printf("Enter elements\n");

for(i=0;i<n;i++)
{
printf("Element %d:",i+1);
scanf("%d",&a[i]);
}
max=findmax(a,n);
mndigit=findNoOfDigits(max);

radsort(a,n,max,mndigit);

printf("Sorted Elements are:\n");
for(i=0;i<n;i++)
{
	printf("Element %d:",i+1);
	printf("%d\n",a[i]);
}
return 0;
}

int findmax(int a[],int n)
{
	int i;
	int max=a[0];

	for(i=1;i<n;i++)
{
	if(a[i]>max)
	{
		max=a[i];
		continue;
	}
}
return max;
}

int findNoOfDigits(int a){
int q=a/10;
int digit=0;

while(q!=0)
	{		
digit++
q=a/10;
	}
	return digit;
}
void addZero(int a[],int ndigit,int mndigit){
	for (int i = 0; i < count; ++i)
	{
		//adding zero code
	}
}
void radsort(int a[][],int n,int max,int mndigit)
{
int q[10][n];

addZero(a[i],findNoOfDigits,mndigit);

}