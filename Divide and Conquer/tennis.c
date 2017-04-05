//TennisTournamentScheduling
#include<stdio.h>
int highdays;
int players;

int main()
{
	int flag;
	int j;
	int i;
	
	int low,high;
	
	int n;
	//Take input of no of players
	scanf("%d",&n);
if(n%2!=0)
{
	flag=1;
	printf("Player %d is a dummy\n",n+1);
	
	n++;
	
}

low=0;
high=n-1;
players=n;
highdays=n-1;

	int schedule[players][days];


mid=(low+high)/2;
int set1[players][days];

	
	for(i=0;i<players;i++)
	{
		for(j=0;j<days;j++)
		{
			schedule[i][j]=-1;	
		}
	
	}
		
	tennis(schedule,set1,set2,playerset1,playerset2,days);
	
	for(i=0;i<players;i++)
	{
		for(j=0;j<days;j++)
		{
			printf("%d",schedule[i][j]);
			
		}
		printf("\n");
	}
	//Even no of Players
	//Divide the players into 2 sets
	//Recursively till 2 people remain
	//Each set takes n/2-1 days
}

void tennis(schedule,set1,playerlowset1,playerhighset1,lowdays,highdays)
{
	for(i=lowdays;i<(highdays-1);i++)
	{
	int mid;
	
		
	if((playerhighset1-playerlowset1)==2)
	{
		schedule[playerlowset1][lowdays]=playerhighset1;
		schedule[playerhighset1][lowdays]=playerlowset1;
		return;
	}
	
	mid=(playerlowset1+playerhighset1)/2;
	tennis(schedule,set1,playerlowset1,mid,lowdays,highdays)
	tennis(schedule,set1,mid+1,playerhighset1,lowdays,highdays);
	merge_tennis(schedule,playerlowset1,mid,playerhighset1,lowdays,highdays);
	lowdays++;
	
	}
	
}

void merge_tennis(int schedule[][],int playerlowset1,int mid,int playerhighset1,int lowdays,int highdays)
{
	
}