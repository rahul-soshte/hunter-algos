#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *left;
struct node *right;

}node;

typedef struct dequeue{
node *l,*r;
}dequeue;

void addleft(dequeue *q,int x)
{
node *ptr;
ptr=(node*)malloc(sizeof(node));
ptr->data=x;
ptr->left=ptr->right=NULL;
if(q->l==NULL)
{
q->l=ptr;
q->r=ptr;
}
else{
ptr->right=q->l;
q->l->left=ptr;
q->l=ptr;

}
}
void addright(dequeue *q,int x)
{
node *ptr;
ptr=(node*)malloc(sizeof(node));
ptr->data=x;
ptr->left=ptr->right=NULL;
if(q->r==NULL)
{
q->r==ptr;
q->l=ptr;
}
else{
ptr->left=q->r;
q->r->right=ptr;
q->r=ptr;

}
}


int deleteleft(dequeue *q)
{
	int x;
	node *ptr;
	if(q->l==NULL)
		printf("empty dequeue");
	else{
		ptr=q->l;
		x=ptr->data;
		q->l=ptr->right;
		
		
	}
	if(q->l==NULL)
		q->r=NULL;
	else 
		q->l->left=NULL;
	free(ptr);
	return x;
	
}
int deleteright(dequeue *q)
{
	int x;
	node *ptr;
	if(q->r==NULL)
		printf("empty dequeue");
	else{
		ptr=q->r;
		x=ptr->data;
		q->r=ptr->left;
		
	}
	if(q->r==NULL)
		q->l=NULL;
		else
			q->r->right=NULL;
		free(ptr);
		return x;
		
	
}

void creat(dequeue *q)
{
	q->l=NULL;
	q->r=NULL;
	
}

void fwdisplay(dequeue *q)
{
	node *ptr;
	ptr=q->l;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->right;
		
	}
}

void revdisplay(dequeue *q)
{
	node *ptr;
	ptr=q->r;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->left;
		
	}
}

void main()
{
	int x,choice;
	dequeue q;
	do{
		printf("Enter the choice\n1.create\n2.addleft\n3.addright\n");
		printf("4.deleteleft\n5.deleterigh\n6.fwdisplay\n7.revdisplay\n38.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:creat(&q);
			break;
			case 2:printf("enter the element to be added");
			scanf("%d",&x);
			addleft(&q,x);
			break;
			case 3:printf("enter element to be added");
			scanf("%d",&x);
			addright(&q,x);
			break;
			case 4:x=deleteleft(&q);
			printf("delete element is %d\n",x);
			break;
			case 5:
			x=deleteright(&q);
			printf("delete element is %d\n",x);
			case 6:fwdisplay(&q);
			break;
			
		}
	}while(choice!=8);
		
}
