//Insertion Sort
#include<stdio.h>

void insort(int a[],int n);

int main()
{ 
int n;
int i;

printf("Enter the number of elements to be sorted\n");
scanf("%d",&n);

int a[n];
printf("Enter elements\n");

for(i=0;i<n;i++)
{
printf("Element %d:",i+1);
scanf("%d",&a[i]);
}
insort(a,n);
printf("Sorted Elements are:\n");
for(i=0;i<n;i++)
{
	printf("Element %d:",i+1);
	printf("%d\n",a[i]);
}
return 0;

}
//i-whole array
//j-unsorted array
//k-sorted array
void insort(int a[],int n){
int temp;
int i,j,k;
int x;

for(i=1;i<n;i++)
{
x=a[i];
for(k=i-1;k>=0;--k){
if(x>a[k])
{
a[k+1]=x;
break;
}
else{
temp=a[k];
a[k]=a[k+1];
a[k+1]=temp;	
}

}}}