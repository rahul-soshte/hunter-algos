#include<stdio.h>

void interpolation(int a[],int n,int val);
int bin_search(int a[],int i,int j,int key);
void interpolation(int a[],int n,int val);
void index1(int a[],int n,int val);
void lin_search(int a[],int n,int val);

int main()
{
	int found;
	int n,i,val;
	int s;
	int choice;

	printf("Enter how many elements");
	scanf("%d",&n);
	int a[n];
	printf("Enter all elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to be searched\n");
scanf("%d",&val);
do{
	printf("Enter your choice1.Interpolation\n2.Binary\n3.Index Sequential\n4.Linear Search\n5.Exit\n");
scanf("%d",&s);
switch(s)
{
	case 1:printf("Interpolation\n");
	interpolation(a,n,val);
	break;
	case 2:printf("Binary Search\n");
	found=bin_search(a,0,n,val);
	if(found!=-1)
		printf("element found at %d\n",found+1);
	else
		printf("element not found\n");
	break;


	case 3:printf("Index Sequential Search\n");
	index1(a,n,val);
	break;

	case 4:printf("Linear Search\n");
	lin_search(a,n,val);
	break;



}

}while(choice!=5);


}

void interpolation(int a[],int n,int val)
{
	int mid,low,high,pos;
	low=0;
	high=(n-1);
	pos=-1;
	while(low<=high)
	{
		mid=low+((high-low)*(val-a[low]))/(a[high]-a[low]);
		if(a[mid]==val)
		{
			pos=mid;
			printf("Position=%d\n",pos+1);
			break;

		}
		else if(a[mid]<val)
			low=mid+1;
		else high=mid-1;

	}

if(pos==-1)
	printf("Value not present in list\n");
}
int bin_search(int a[],int i,int j,int key)
{
	int c;
	c=(i+j)/2;
while(a[c]!=key && i<=j)
{
	if(key>a[c])
		i=c+1;
	else j=c-1;

	c=(i+j)/2;

}
if(i<=j)
return c;

return -1;

}
void index1(int a[],int n,int val)
{
	int kid[10],pid[10],i,s,j=0,low=0,high=n,pos=-1,k;
	printf("Index file\n");
	for(i=0;i<n;i=i+5)
	{
		kid[j]=a[i];
		pid[j]=i;
		j++;

	}


	for ( s = 0; s < j; ++s)
	{
		printf("%d\t%d\n", pid[s],kid[s]);

	}
	if(val<kid[0]){
		printf("elements not found\n");
return;



	}
/*
	if(val<kid[j]){
		for(i=j;i<n;i++)
		{
			if(a[i]==val)
			{
				pos=i;

			}
		}

}
*/
/*for(i = 1; i < j;i++)
{
	if(a[k]==val)
	{
		pos=k;
		break;

	}
}
*/
else{
	for(i=1;i<j;i++)
		if(val<kid[i])
		{
high=pid[i];

low=pid[i-1];
	
break;

}


for(k=low;k<=high;k++)
{

	if(a[k]==val)
	{
		pos=k;
		break;

	}
}
}
if(pos==-1)
	printf("element not found\n");
else printf("element found at position %d\n",++pos);


}

void lin_search(int a[],int n,int b)
{
	int c=0;
	int i;

	for(i=0;i<=9 && c==0;i++)
	{
		if(a[i]==b)
		{
			printf("No is at position %d\n",i+1);
			c=1;
			break;

		}

	}

	if(c==0)
	{
		printf("No not found\n");
	}
}