//ShellSort
#include<stdio.h>

void shellsort(int a[],int n);

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
shellsort(a,n);

printf("Sorted Elements are:\n");
for(i=0;i<n;i++)
{
	printf("Element %d:",i+1);
	printf("%d\n",a[i]);
}
return 0;
}

void shellsort(int a[],int n)
{
int gap;//increment
gap=n/2;
int *end;
int temp;

for(i=0;i<n;i++)
{
if(a[i]>a[i+gap])
{
temp=a[i];
a[i]=a[i+gap];
a[i+gap]=temp;

}
}

}
