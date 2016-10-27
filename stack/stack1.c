#include<stdio.h>

void push(int[],int *top,int x,int n);
int pop(int a[],int *top);
void display(int a[],int top);

int main()
{
	int a[50],x,i,n=50;
	int top=-1;
	int choice;
	printf("Stack is empty,Enter your choice");
	do{
	printf("Enter your choice\n1.push\n2.pop\n3.display\n4.Exit");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:printf("Enter the element to be push ");
	scanf("%d",&x);
	push(a,&top,x,n);
	break;
	case 2:x=pop(a,&top);
	printf("the popped element is %d\n",x);
	break;
	case 3:display(a,top);
	break;
	case 4:break;
	}

	}while(choice!=4);

return 0;

}


void push(int a[],int *top,int x,int n)
{
	if(*top==49)
	printf("Stack is full");
	else{
	*top=*top+1;
	a[*top]=x;

	}
}

int pop(int a[],int *top)
{
	int x;
	if(*top<0)
	{
	printf("Stack is empty");
	return -1;
	}
	else{
	x=a[*top];
	*top=*top-1;
	return x;

	}
}


void display(int a[],int top)
{
int i;

for(i=top;i>=0;i--)
{
	printf("%d\n",a[i]);

}
}
