#include<stdio.h>
void radsort(int a[],int n);

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
radsort(a,n);

printf("Sorted Elements are:\n");
for(i=0;i<n;i++)
{
	printf("Element %d:",i+1);
	printf("%d\n",a[i]);
}
return 0;
}

void radsort(int a[],int n)
{
	
}