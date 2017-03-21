#include<stdio.h>

void shell_sort(int a[],int n);
void insertion(int a[],int n);
void radix_sort(int a[],int n,int m);

void main()
{
	int a[50],n,m,i,choice;
printf("Enter the no of elements");
scanf("%d",&n);
for(i=0;i<=n-1;i++)
{
	printf("Enter the no");
	scanf("%d",&a[i]);

}
printf("Enter your choice\n.1:insertion\n2:shell sort\n3:radix_sort\n");
scanf("%d",&choice);
switch(choice)
{
	case 1:insertion(a,n);
	break;
	case 2:shell_sort(a,n);
	break;
	case 3:printf("Enter the no of max digits\n");
	scanf("%d",&m);
	radix_sort(a,n,m);
	break;

}
for(i=0;i<=n-1;i++)
{
	printf("%d\t",a[i]);
}
}


void shell_sort(int a[],int n){
	int i,j,step;
	int temp;
	for(step=n/2;step>0;step=step/2)
{
	for(i=step;i<n;i++)
	{
		temp=a[i];
		for(j=i;j>=step;j=j-step)
		{
			if(temp<a[j-step])
				a[j]=a[j-step];
			else
				 break;

						}
		a[j]=temp;
	}
}

}


void insertion(int ar[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=ar[i];
		for(j=i-1;j>=0 && ar[j]>temp;j--)
		{
			ar[j+1]=ar[j];

		}
		ar[j+1]=temp;

	}
}

void radix_sort(int a[],int n,int m){
	int q[10][30],rear[10],i,j,k=1,l,s,d;
	for ( i = 0; i < m; ++i)
	{
		for(j=0;j<10;j++)
		{
			rear[j]=-1;

		}
		for(j=0;j<n;++j)
		{
			d=(a[j]/k)%10;
			q[d][++rear[d]]=a[j];

		}
		s=0;
		for ( j= 0; j < n; ++j)
		{for(l=0;l<=rear[j];++l)
			{
				a[s++]=q[j][l];

			}
		
	}
	k=k*10;

	}

}