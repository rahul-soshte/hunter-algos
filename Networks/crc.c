#include<stdio.h>

 int main()
 {
   int k;
   int m;
   int size_of_dividend=8;
   int size_of_divisor=4; 
   int a[11]={1,0,0,0,1,0,0,1};
   int b[4]={1,0,0,1};
   int i;
   int c[5];
   int no_of_zeroes_to_appended=4-1;//Number of bits of divisor-1
   
printf("*****CRC******\n");

  printf("Value of Divisor:");
      for(i=0;i<size_of_divisor;i++)
      {
   printf("%d",b[i]);
      } 
//Append zeroes
      for(i=8;i<11;i++)
      {
        a[i]=0;
      }
     
     printf("\nValue of Dividend:");
     for(i=0;i<size_of_dividend;i++)
      {
	 printf("%d",a[i]);
      }

printf("\n");

	
int initial;
int steps;
steps=size_of_divisor;
for(k=0;k<size_of_dividend;k++){
initial=k;
for(i=0;i<size_of_divisor;i++){

   if(a[initial]==b[0])
	  {
	  c[i]=(a[initial+i]+b[i])%2;
	  }
  if(a[initial]!=b[0]){
    c[i]=a[initial+i];
   }
}

c[4]=a[initial+4];
initial++;
for(i=1;i<5;i++,initial++)
      {
    a[initial]=c[i];
       }

       }


/*
      if(c[1]==b[0])
      {
       for(i=0;i<n;i++)
       {
	  c[i]=(c[i]+b[i])%2;
       }

      }
*/

printf("\n");
printf("Remainder is \n");
     for(i=0;i<4;i++)
     {
     printf("%d",c[i]);
     }

return 0;
   }







































































































