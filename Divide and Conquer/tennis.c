//TennisTournamentScheduling
#include<stdio.h>
int days;
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
days=n;

	int schedule[players][days];


mid=(low+high)/2;
int set1[mid][mid];
int set2[hig-mid][hig-mid];

	
	for(i=0;i<players;i++)
	{
		for(j=0;j<days;j++)
		{
			schedule[i][j]=-1;
			
		}
	
	}
		
	tennis(schedule,set1,set2,playerset1,playerset2,daylowset1,daylowset2,dayhighset1,dayhighset2);
	
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

void tennis(schedule,set1,set2,playerlowset1,playerhighset1,playerlowset2,playerhighset1,days)
{
	
	if((playerhighset1-playerlowset1)==2)
	{
		set1[playerlowset1][days]=playerhighset1;
		set1[playerhighset1][days]=playerlowset1;
		
	}
	if((playerhighset2-playerlowset2)==2)
	{
		set1[playerlowset2][days]=playerhighset2;
		set1[playerhighset2][days]=playerlowset2;
		
	}
	
	
}
