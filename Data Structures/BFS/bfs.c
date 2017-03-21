#include<stdio.h>

char que[20];
int front=0,rear=0,n;
char arr[20];
int bfs(int);
char ajMat[20][20];
char b[20];
void display();
int p=0;

int main()
{
	char v;
	int i,j;
	printf("Enter the number of nodes in a graph");
	scanf("%d",&n);
	printf("Enter the value of node of graph");
	for(i=0;i<n;i++)
	{
		scanf("%s",&b[i]);

	}
printf("Enter the value of adajancy of matrix in 'y' or 'n'\n");
printf("If there exists  an edge between two vertices than 'y' otherwise 'n'\n");
for(i=0;i<n;i++)
printf("%c\t",b[i]);

for(i=0;i<n;i++)
{
	printf("%c",b[i]);
	for(j=0;j<n;j++)
	{
		scanf("%c",&v);
		ajMat[i][j]=v;

	}
	printf("\n");
}
for(i=0;i<n;i++)
bfs(i);

display();

}

void display()
{
	int i;
	printf("BFS of graph\n");
	for(i=0;i<n;i++)
	printf("%c",arr[i]);
}

void insert(char val)
{
	que[front]=val;
	front++;

}


char del()
{
	rear=rear+1;
	return que[rear-1];

}
int unVisit(char val)
{
	int i;
	for(i=0;i<front;i++)
	{
		if(val==que[i])
			return 0;
	}
return 1;

}

int bfs(int i)
{
	char m;
	int j;
	if(front==0)
	{
		insert(b[i]);

	}
for(j=0;j<n;j++)
{
	if(ajMat[i][j]=='y')
	{
		if(unVisit(b[i]))
		{
			insert(b[j]);

		}
	}
}
m=del();
arr[p]=m;
p++;
return 0;
}
