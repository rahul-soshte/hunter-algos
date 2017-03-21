#include<stdio.h>



#include<stdlib.h>

typedef struct node

{

int data;

struct node *next;

} node;

void display(node *ptr)

{printf("\nelements are\n");

while(ptr!=NULL)

{

printf("%d ",ptr->data);

ptr=ptr->next;

}

}

void count(node *ptr)

{ int i=0;

while(ptr!=NULL)

{i++;

ptr=ptr->next;

}

printf("no of nodes are %d \n",i);

}

node *copy(node *ptr,int n)

{  node *start1,*ptr1;

start1=(node*)malloc(sizeof(node));

int i;

start1->data=ptr->data;

start1->next=NULL;

ptr1=start1;

for(i=1;i<n;i++)

  {   ptr1->next=(node*)malloc(sizeof(node));

      ptr1=ptr1->next;

       ptr=ptr->next;

     ptr1->data=ptr->data;

     ptr1->next= NULL;

}

display(start1);

}

 

int search(node *ptr)

{   int s,c=1;

node *p;

p=ptr;

printf("enter the element to  be search\n ");

scanf("%d",&s);

while(p!=NULL)

{ if((p->data)==s)

   return c;

   else

{p=p->next;

c++;

}

}

return -1;

}

 

node *reverse(node *ptr)

{ node *p,*q,*r;

q=ptr;

p=NULL;

r=q->next;

while(q!=NULL)

{

   q->next=p;

   p=q;

   q=r;

   if(r!=NULL)

        r=r->next;

}

return(p);

}

node *split(node *ptr,int n)

{ int i=0;

  node *ptr1,*start;

  start=ptr;

  while(i!=n/2)

  {

      ptr=ptr->next;

      i++;

      ptr1=ptr->next;

  }

  ptr->next=NULL;

printf("first half\n");

display(start);

 

printf("\nsecond half\n");

display(ptr1);

}

node *create(int n)

{  int i;

node *start,*ptr;

start=(node*)malloc(sizeof(node));

if(n==0)

start=NULL;

else

{

printf("enter the elements");

scanf("%d\n",&(start->data));

start->next=NULL;

ptr=start;

for(i=1;i<n;i++)

{

ptr->next=(node*)malloc(sizeof(node));

ptr=ptr->next;

scanf("%d",&(ptr->data));

ptr->next=NULL;

}

return start;

}

}

node *concatenate(node *start,node *start1)

{

node *ptr;

/*if(start==NULL)

display(start1);

if(start1==NULL)

display(start);*/

ptr=start;

while(ptr->next!=NULL)

{

ptr=ptr->next;

}

ptr->next=start1;

display(start);

}

void main()

{ node *start;

int i,n,c;

do

{

printf("\nenter no of terms");

scanf("%d",&n);

printf("ENTER YOUR CHOICE \n1 COUNT NO OF NODES \n 2 REVERSE \n 3 COPY\n 4SEARCH\n 5.SPLIT\n 6.CONCATENATE\n 7 QUIT\n");

scanf("%d",&c);

switch(c)

{

case 1 :

      {

     start=create(n);

     count(start);

      break;

      }

case 4:

     {  int s;

      start=create(n);

         s=search(start);

if(s==-1)

    printf("number not found\n");

else

    printf("number found position=%d\n",s);

     break;}

case 2:

    { start=create(n);

    start=reverse(start);

     display(start);

      break;}

case 3:

    {      start=create(n);

          copy(start,n);

          break;

    }

case 5:

    {    start=create(n);

        split(start,n);

        break;

    }

case 6:

    { node *start1;

    start=create(n);

    int n;

    printf("enter no of terms");

    scanf("%d",&n);

     start1=create(n);

     concatenate(start,start1);

    }

 

case 7:

    {

     break;

    }

}

}while(c!=7);

}