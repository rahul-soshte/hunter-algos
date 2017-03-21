#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 5
int empty();

struct queue
{
	int front,rear;
	int items[QUEUESIZE];/*assuming queue containing integers*/

};

struct queue q;

void insert(int x)
{
	if(q.rear==QUEUESIZE-1)
	{
		

		printf("queue Overflow,Cannot Insert\n");
	exit(1);

	}
	else{
		q.items[++(q.rear)]=x;
	if(q.rear==QUEUESIZE-1 && front !=0)
		rear=-1;
	
	}

}
int removes()
{
	if(empty())
	{

		printf("Queue Underflow.Cannot Remove\n");
		exit(1);

	}
	

return (q.items[(q.front)++]);

}
int empty()
{
	if(q.rear<q.front)
		return 1;
	else
		return 0;

}
void show()
{
	int i;
	printf("Queue from front most element is as shown\n");
	for(i=q.front;i<=q.rear;i++)
		printf("%d\n",q.items[i]);

}
void main()
{
	int x,ch;
	q.rear=-1;
	q.front=0;
	do{
		printf("\nMenu:n");
		printf("1.Insert\n");
		printf("2.Remove\n");
		printf("3.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to be inserted\n");
				scanf("%d",&x);
			insert(x);

			show();
			break;
			case 2:
			x=removes();
			printf("Element removed is :%d\n",x );
			show();
			break;

					}
	}while(ch!=3);

}
