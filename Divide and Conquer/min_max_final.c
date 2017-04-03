#include<stdio.h>
struct pair
{
	int max;
	int min;
}pair;
int i=0;
struct pair find_min_max(int numbers[],int low,int high)
{
	
    struct pair s;
    struct pair s1;
	struct pair s2;

if(low==high)
	{
s.max=numbers[low];
s.min=numbers[high];
printf("Level %d-----------\n",i);
printf("Max=%d\n",s.max);
printf("Min=%d\n",s.min);
return s;
	}
	if(low==high+1)
	{
		if(numbers[low]>numbers[high])
		{
			s.min=numbers[high];
			s.max=numbers[low];
		}
		else{
			s.min=numbers[low];
			s.max=numbers[high];
			

		}
		printf("Level %d-----------\n",i);
		printf("Max=%d\n",s.max);
        printf("Min=%d\n",s.min);
		return s;
	}

int mid;	
mid=(low+high)/2;
s1=find_min_max(numbers,low,mid);
s2=find_min_max(numbers,mid+1,high);
{
if(s1.max>s2.max)
{
	s.max=s1.max;

}
else
{
	s.max=s2.max;
}
if(s1.min<s2.min)
{
	s.min=s1.min;

}
else 
{
	s.min=s2.min;

}
printf("Level %d-----------\n",i++);
printf("Max=%d\n",s.max);
printf("Min=%d\n",s.min);
return s;
}

}


int main()
{
	struct pair s;

	int i;

	int n;
	printf("Enter the no of Elements");
	scanf("%d",&n);
	int numbers[n];
int low=0;
int high=n-1;

for(i=0;i<n;i++)
{	
	scanf("%d",&numbers[i]);
}
s=find_min_max(numbers,low,high);
printf("The Maximum of the Array is %d\n",s.max);
printf("The Minimum of Array is %d",s.min);
}