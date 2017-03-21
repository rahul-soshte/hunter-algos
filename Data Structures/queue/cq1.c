#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int cQueue[SIZE],front=-1,rear=-1;

void main()
{
	int choice,value;
	
	while(1){
		printf("\n***MENU***\n");
		printf("1.Insert\n2.Delete\n3.display\n4.Exit");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value to insert\n");
			scanf("%d",&value);
			enQueue(value);
			break;
			case 2:deQueue();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:printf("\nSelect the correct choice");

		}
	}

}
void  deQueue()
{
	if(front==-1 && rear==-1)
		printf("Circular Queue is Empty!\n");
	else{
		printf("Deleted element is %d\n",cQueue[front++]);

		if(front-1==rear)
			front=rear=-1;
	if(front==SIZE)
			front=0;
	}
}

void enQueue(int value)
{
if(front==0 && rear==SIZE-1 || front==rear+1)
		printf("Circular Queue is Full!\n");
	else{
		if(rear==SIZE-1 && front!=0)
			rear=-1;
	 cQueue[++rear]=value;
		if(front=-1)
			front=0;


	}	
}
void display()
{
	if(front==-1)
		printf("Cq is Empty\n");
	else{
		int i=front;
		printf("Circular elements are:\n");
		if(front<=rear)
		{
			while(i<=rear)
				printf("%d\t",cQueue[i++]);
		}	else{
			while(i<=SIZE-1)
				printf("%d\t",cQueue[i++]);
			i=0;
			while(i<=rear)
				printf("%d\t",cQueue[i++]);
		}
	}
}