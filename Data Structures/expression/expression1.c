#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree{
	char data;
	struct tree *left,*right;

}

int top=-1;
struct tree *stack[20];
struct tree *node;

void push(struct tree* node)
{
	stack[++top]=node;
}

struct tree *pop()
{
	return(stack[top--]);

}

void inorder(struct tree *node)
{
	
}if(node!=NULL)