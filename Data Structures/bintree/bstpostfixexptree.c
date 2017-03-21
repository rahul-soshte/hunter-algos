#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define STACKSIZE 50

struct node
{
	char data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct stack
{
	int top;
	struct node* items[STACKSIZE];
};
void createtree(char e[]);
int isoperand(char c);
struct node* pop(struct stack *ps);
void push(struct stack *ps,struct node* root);
void preorder(struct node *root);
void inorder(struct node *root);

void main()
{
	char e[50];
	printf("Enter the expression in postfix form\n");
	gets(e);
	createtree(e);
	printf("expression in prefix form is :");
	preorder(root);
	printf("\n");
	printf("expression in infix form\n");
inorder(root);
printf("\n");


}
void createtree(char e[])
{
	int i;
	struct node *pnode,*op1,*op2;
	struct stack s;
	s.top=-1;

op1=NULL;
op2=NULL;


	for(i=0;e[i]!='\0';i++){
		if(isoperand(e[i]))
		{
			pnode=(struct node*)malloc(sizeof(struct node));
			pnode->data=e[i];
			pnode->left=NULL;
			pnode->right=NULL;
			push(&s,pnode);

		}
		else{
			op1=pop(&s);
			op2=pop(&s);
			pnode=(struct node*)malloc(sizeof(struct node));
			pnode->data=e[i];
			pnode->left=op2;
			pnode->right=op1;
			push(&s,pnode);

		}
	}
	root=pop(&s);
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%c",root->data);
		preorder(root->left);
		preorder(root->right);

	}

}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);

	}
}
int isoperand(char c)
{
	if(c>='0' && c<='9' || c>='A' && c<='Z' || c>='a' && c<='z')
		return 1;
	else
		return 0;

}

struct node* pop(struct stack *ps)
{
	return(ps->items[ps->top--]);
}

void push(struct stack *ps,struct node *x)
{
	ps->items[++(ps->top)]=x;

}