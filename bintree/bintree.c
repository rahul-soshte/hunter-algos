#include<stdio.h>
#include<stdlib.h>
typedef struct treenode{
	int data;
	struct treenode *left;
	struct treenode *right;

}treenode;

void inorder(treenode *root)
{
		if(root!=NULL)
		{
			inorder(root->left);
			printf("%d\n",root->data);
			inorder(root->right);

		}
	}

void insertion(treenode **root,int x)
{
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

void treedeletion(treenode **root,int x)
{
	treenode *prev,*p,*s,*rp,*f;
	p=*root;
	prev=NULL;
	while(p!=NULL)
	{
		if(x==p->data)
			break;
		else
		{
			prev=p;
			if(x<p->data)
				p=p->left;
			else
				p=p->right;

		}
	}
	if(p==NULL)
	{
		printf("Not found\n");
		return;

	}//Checking for childs(left/right/both)
	if(p->left==NULL)
		rp=p->right;
	else if(p->right==NULL)
			rp=p->left;
	else {
		f=p;
		rp=p->right;
		s=rp->left;
		while(s!=NULL)
		{
			f=rp;
			rp=s;
			s=rp->left;

		}
		if(f!=p)
		{
			f->left=rp->right;
			rp->right=p->right;

		}
		rp->left=p->left;

	}
if(prev==NULL)
	*root=rp;
else if(prev->left==p)
	prev->left=rp;
else 
	prev->right=rp;
free(p);

}

void main()
{
	int a[100],n,i,x,y,z;
	int option;
	
	treenode *root;
	root=NULL;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("Enter the elements\n");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
	insertion(&root,a[i]);

}
do{
	printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
	printf("Enter the option\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:printf("Enter the Elements to be inserted\n");
		scanf("%d",&y);
		insertion(&root,y);
		break;
		case 2:printf("Enter the element to Be deleted\n");
		scanf("%d",&z);
		treedeletion(&root,z);
		break;
		case 3:
		inorder(root);
		case 4:break;

         }
     }
while(option!=4);
}