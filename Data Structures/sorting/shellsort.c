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
int gap=n/2;//increment
int temp;
int x;
int k;
int *end;
int i;
int j;
while(gap>=1)
{
for (int i = gap; i < n; i=i+gap)
{
	/* code */
	//In place of 1 there should be gap
x=a[i];
	for(k=i-gap;k>=0;k=k-gap)
	{
		if(x>a[k])
		{
			a[k+gap]=x;
			break;
		}
		e lse
		{
			temp=a[k];
			a[k]=a[k+gap];
			a[k+gap]=temp;
			}

	}

}
gap=gap/2;

}
}
