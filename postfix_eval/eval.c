#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct{
	int a[100],top;

}stack;

void push(stack *s,int x)
{
	if(s->top==99)
	printf("full");
	else{
	s->a[++s->top]=x;
	}
}
int pop(stack *s)
{
	int x;
	if(s->top<0)
		printf("Empty\n");
	else{
x=s->a[s->top--];
return x;
	}
}
int operation(char c1,int p1,int p2)
{
	switch(c1)
	{
	case '+':return p1+p2;	
	case '-':return p1-p2;
case '*':return p1*p2;
case '/':return p1/p2;
default:return -1;

		}
}

int eval(char post[])
{
	stack s;
	int i,p1,p2,p;
	s.top=-1;
	for(i=0;post[i]!='\0';++i)
	{
		if(isdigit(post[i]))
			push(&s,post[i]-'0');
		else
		{
			p2=pop(&s);
			p1=pop(&s);
			p=operation(post[i],p1,p2);
			push(&s,p);

	}
}
return pop(&s);
}
void main()
{
char postfix[20];
printf("Enter a postfix exp to be evaluated");
gets(postfix);
printf("The eval is %d",eval(postfix));

}