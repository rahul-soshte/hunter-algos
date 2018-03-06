#include<stdio.h>

int main()
{
	int n;
printf("Enter the number of terms\n");
scanf(" %d",&n);
int a[n];
int h=n*3;
int b[h];
printf("Enter the terms ");
for(int i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}

int m;
int l;

for(m=0,l=0;m<h,l<n;m++,l++)
{
b[m]=a[l];

if(l==n-1)
{
	l=-1;
}

}
int u;

for(u=0;u<h;u++)
{
	printf("%d ",b[u]);
}

return 0;

}