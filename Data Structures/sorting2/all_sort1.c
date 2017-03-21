#include<stdio.h>

void heap_sort(int a[],int n);
void swap(int *x,int *y);
void quick_sort(int a[],int low,int high);
int partition(int a[],int low,int high);
void merge_sort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);


void main()
{
	int sort,a[30],n,high,low;
	int i;
printf("Enter the size of ur array\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Enter the element\n");
	scanf("%d",&a[i]);

}
printf("Your entered array is\n");
for(i=0;i<n;i++)
	printf("%d ",a[i]);

low=0;
high=n;
printf("Enter Your Choice:\n1.heap_sort\n2.merge_sort\n3.quick_sort\n");
scanf("%d",&sort);

switch(sort)
{
case 1:
heap_sort(a,n);
break;
case 2:
merge_sort(a,low,high);
break;
case 3:
quick_sort(a,low,high);
break;

}
printf("Your sorted array is \n");
for(i=0;i<n;i++)
	printf("%d ",a[i]);

}

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;

}

void heap(int a[],int n)
{
	int i,s,f;
	for(i=1;i<n;i++)
	{
		s=i;
		f=(i-1)/2;
		while(a[f]<a[s])
		{
			swap(&a[s],&a[f]);
			s=f;
			if(s==0) break;
			f=(s-1)/2;

		}
	}
}

void heap_sort(int a[],int n)
{
	int i;
	heap(a,n);
	for(i=n-1;i>=1;--i)
	{
		swap(&a[0],&a[i]);
		heap(a,i);

	}
}
void merge_sort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);

	}

}

void merge(int a[],int low,int mid,int high)
{
	int b[100],i,j,k;
	i=low;
	j=mid+1;
	k=low;

	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
b[k++]=a[i++];

else b[k++]=a[j++];
	}

	while(i<=mid)
	{
		b[k++]=a[i++];

	}

	while(j<=high)
	{
		b[k++]=a[j++];

	}

	for(i=low;i<=high;i++)
		a[i]=b[i];

}

void quick_sort(int a[],int low,int high){
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);

	}
}

int partition(int a[],int low,int high)
{
	int down,up,x,temp;
	down=low;
	up=high;
	x=a[low];
	while(down<up)
	{
		while(a[down]<=x && down<high)
			down++;
while(a[up]>x)
up--;

if(down<up)
{
	temp=a[down];
	a[down]=a[up];
	a[up]=temp;

}	

}

a[low]=a[up];
a[up]=x;
return up;

}