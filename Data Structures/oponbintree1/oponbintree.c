#include<stdio.h>
#include<stdlib.h>


typedef struct{
	int data;
	struct treenode *left,*right;

}treenode;

int nodecount(treenode *root)
{
	int l,r;
	if(root==NULL)
	return 0;
	l=nodecount(root->left);
	r=nodecount(root->right);
	return l+r+1;

}
int leafcount(treenode *root)
{
	int l,r;
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	l=leafcount(root->left);
	r=leafcount(root->right);
	return l+r;

}

void order(treenode *root)
{
	if(root!=NULL)
	{
		order(root->left);
		printf("%d ",root->data);
		order(root->right);

	}
}
treenode *copy(treenode *root)
{
	treenode *ptr,*l,*r;
	ptr=NULL;
	if(root!=NULL)
	{
		l=copy(root->left);
		r=copy(root->right);
		ptr=(treenode*)malloc(sizeof(treenode));
		ptr->data=root->data;
		ptr->left=l;
		ptr->right=r;
		return ptr;

	}
	}
treenode *mirror(treenode *root)
{
	treenode *ptr,*l,*r;
	ptr=NULL;
if(root!=NULL)
{
	l=mirror(root->left);
	r=mirror(root->right);
	ptr=(treenode*)malloc(sizeof(treenode));
	ptr->data=root->data;
	ptr->left=r;
	ptr->right=l;
	return ptr;

}
}

void insertion(treenode **root,int x){
	treenode *p,*ptr,*prev;
	ptr=(treenode*)malloc(sizeof(treenode));
ptr->data=x;
ptr->left=ptr->right=NULL;
p=*root;
prev=NULL;
while(p!=NULL)
{
	prev=p;
	if(x<p->data)
		p=p->left;
	else
		p=p->right;
}
if(prev==NULL)
*root=ptr;
else
if(x<prev->data)
	prev->left=ptr;
else
	prev->right=ptr;
}

void main()
{
	int choice,y,x,i;
	struct treenode *root,*root1;
	root=NULL;

	do{
		printf("Enter UR choice\n1.insertion\n2.nodecount\n3.leafcount\n4.copy\n");
		printf("5.mirror\n6.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the no of element to be inserted\n");
			scanf("%d",&y);
			for(i=0;i<y;i++)
			{
				scanf("%d",&x);
				insertion(&root,x);

			}
			order(root);
			break;
			case 2:printf("node count of binary tree is %d",nodecount(root));
			break;
			case 3:printf("Leaf count of binary tree is %d",leafcount(root));
			break;
			case 4:root1=copy(root);
			printf("the copied bst is \n");
			order(root1);
			break;
			case 5:root1=mirror(root);
			printf("the mirror of bst is\n");
			order(root1);
			break;
			case 6:break;

		}
	}while(choice!=6);


}