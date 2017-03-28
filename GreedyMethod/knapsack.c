//KnapSack
#include<stdio.h>
void knapsack(float profits[],float weights[],int capacity,int n){
float x[20],tp=0;
int i,j,u;
u=capacity;

 for (i = 0; i < n; i++)
      x[i] = 0.0;

for (i = 0; i < n; i++) {
      if (weights[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profits[i];
         u = u - weights[i];   
      }
   }

   if (i < n)
      x[i] = u / weights[i];

    tp=tp+(x[i]*profits[i]);

printf("The total profit is %f",tp);
}

int main()
{
 int n;
int j;
int i;
int capacity;
int temp;

 printf("Enter the no of objects");
 scanf("%d",&n);
 printf("Enter the capacity");
 scanf("%d",&capacity);

 float profits[n],weights[n];
 printf("\nEnter the wts and profits of each object:- ");
   for (i = 0; i < n; i++) {
    scanf("%f %f", &weights[i], &profits[i]);
   }
 float prof2weight[n];

for(i=0;i<n;i++)
 {
prof2weight[i]=profits[i]/weights[i];
 }

for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
    if(prof2weight[i]<prof2weight[j])
    {
    temp=prof2weight[j];
    prof2weight[j]=prof2weight[i];
    prof2weight[i]=temp;

    temp=profits[j];
    profits[j]=profits[i];
    profits[i]=temp;

    temp=weights[j];
    weights[j]=weights[i];
    weights[i]=temp;
    }
}

}
knapsack(profits,weights,capacity,n);
return 0;
}
