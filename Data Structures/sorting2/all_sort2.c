#include<stdio.h>
 
 
  int partation(int [],int,int);

  void quick_sort(int [],int,int);
    
  void merge_sort(int [],int,int);

 void merge(int [],int ,int,int);

  void heap(int [],int);

 void heap_sort(int [],int );

 void swap(int *,int *);

void main()

{ int a[50],n,m,i,choise;

   printf("enter the no. of element");

  scanf("%d",&n);

   for(i=0;i<=n-1;i++)

  { printf("enter the no.");

   scanf("%d",&a[i]);

  }

  printf("enter yor choise\n1:quick\n2:merge\n3:heap sorts");

  scanf("%d",&choise);

  switch(choise)

   { case 1: quick_sort(a,0,n);

      break;

  case 2:merge_sort(a,0,n);

    break;

  case 3:

    heap_sort(a,n);

    break;

  }

   for(i=0;i<=n-1;i++)

  { printf("%d\t\a",a[i]);

  }

 

 

}

int partation(int a[],int lb,int ub)

{ int down=lb,up=ub,x,temp;

  x=a[lb];

  while(down<up)

 { while(a[down]<=x)

    {down++;

    }

    while(a[up]>x)

    {up--;

    }

    if(down<up)

    { temp=a[down];

      a[down]=a[up];

      a[up]=temp;

    }

}

  a[lb]=a[up];

  a[up]=x;

  return up;

}

void quick_sort(int a[],int lb,int ub)

{int j;

 if(lb<ub)

   {  j=partation(a,lb,ub);

      quick_sort(a,lb,j-1);

      quick_sort(a,j+1,ub);

  }

}

 

void merge(int a[],int low,int mid,int high)

{ int b[100],i,j,k;

  i=low;

  j=mid+1;

  k=low;

  while(i<=mid && j<=high)

  { if(a[i]<a[j])

     b[k++]=a[i++];

     else

     b[k++]=a[j++];

   }

  while(i<=mid)

  { b[k++]=a[i++];

  }

  while(j<=high)

  {b[k++]=a[j++];

  }

  for(i=low;i<=high;++i)

  { a[i]=b[i];

  }

}

 

void merge_sort(int a[],int low,int high)

{   int mid;

    if(low<high)

    { mid=(low+high)/2;

    merge_sort(a,low,mid);

    merge_sort(a,mid+1,high);

    merge(a,low,mid,high);

    }

}

 

void heap(int a[],int n)
 
{  int s,f,i;

    for(i=1;i<n;++i)

    {   s=i;

f=(i-1)/2;

     while(a[f]<a[s])

     { swap(&a[s],&a[f]);

       s=f;

       if(s==0)

break;

       f=(s-1)/2;

     }  }

}

 

void heap_sort(int a[],int n)

{  int i;

   heap(a,n);

     for(i=n-1;i>=1;--i)

     {  swap(&a[0],&a[i]);

      heap(a,i);

     }}

 

void swap(int *x,int *y)

{int temp;

     temp=*x;

     *x=*y;

     *y=temp;

}