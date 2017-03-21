#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;

}node;

typedef struct{
	node *front;
	node *rear;
}queue;

void addqueue(queue *q,int x)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=x;
	ptr->next=NULL;

	if(q->rear==NULL)
	{
		q->rear=ptr;
		q->front=ptr;
		

	}
else{
	q->rear->next=ptr;
	q->rear=ptr;

}

}
int deletq(queue *q)
{
	node *ptr;
	int x;
	if(q->front==NULL)
		printf("Empty queue\n");
	else{
		ptr=q->front;
		x=ptr->data;
		q->front=ptr->next;

	}
	if(q->front==NULL)
		q->rear=NULL;

	free(ptr);
	return x;

}
void display(queue q)
{
	node *ptr;
	ptr=q.front;
	while(ptr!=NULL)
	{		
		printf("%d\n",ptr->data);
		ptr=ptr->next;


	}
}

void creatq(queue *q)
{
	q->front=NULL;
	q->rear=NULL;

}
void destroyq(queue *q)
{
	node *ptr;
	ptr=q->front;
	while(ptr!=NULL)
{
	q->front=ptr->next;
	free(ptr);
	ptr=q->front;

}
q->rear=NULL;

}
void main()
{
	int choice,x,y;
	queue q1;
	do{
		printf("Enter the choice\n");
		printf("\n1.creatq\n2.addqueue\n3.delet\n4.display\n5.destroyq\n");
		printf("6.exit\n\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:creatq(&q1);
			break;
			case 2:printf("ENter the element to be added\n");
			scanf("%d",&y);
			addqueue(&q1,y);

		break;
		case 3:y=deletq(&q1);
		printf("Enter element to be added\n");
		break;
		case 4:display(q1);
		break;
		case 5:destroyq(&q1);
		break;
		case 6:break;

		}
	}while(choice!=6);

}