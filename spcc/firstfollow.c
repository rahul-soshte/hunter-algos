//Implement First and Follow in C
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char production[25][25];
//char firstfound[100][100];
int productionfound[100];
int productionfoundforfollow[100];
int firstcount=0;
char follow[100];
int followcount=0;
//int elementforfirstfoundcount=0;
int bufferproductionfound[100];
int episolonfound=0;
int episolontempfound=0;

/**
Return an array of indexes of production ofg the given non terminal.

Here char c is the non terminal
int n is the total number of productions
**/
int findProduction(char c,int n){
int flag=0;
int elementforfirstfoundcount=0;
	for(int i=0;i<n;i++){
		if(production[i][0]==c){
			//printf("%d\n",i);
		    productionfound[elementforfirstfoundcount]=i;
			elementforfirstfoundcount++;
			flag=1;	
		}

	}

	if(flag==1){
		return elementforfirstfoundcount;
	}
	else if (flag==0){
		return -1;
	}

	return -1;
}


void first(char c,int n)
{
if(islower(c))
{
	printf("Non Terminal dont have a first");
}
else{
	int index=findProduction(c,n);
	//findProduction(c,n);
	//parseproduciton(index);
//	if(result == -1){
//		//printf("Bye Bye");
//		return;
//	}

if (index!=-1){

for(int m=0;m<index;m++)
{
	for(int i=1;i<strlen(production[productionfound[m]]);i++)
	{
		if(production[productionfound[m]][i] =='-' || production[productionfound[m]][i]=='>')
		{
		 continue;
		}
		if(production[productionfound[m]][i] == '!'){
		episolonfound=1;
		break;
	    }

        if(islower(production[productionfound[m]][i]))
		{
		  printf("First is %c\n",production[productionfound[m]][i]);
		  break;
		}
		else{
			for(int h=0;h<index;h++){
				episolontempfound=episolonfound;
				bufferproductionfound[h]=productionfound[h];
			}

			first(production[productionfound[m]][i],n);
		
			for(int y=0;y<index;y++)
			    {	
				episolonfound=episolontempfound;
				productionfound[y]=bufferproductionfound[y];
				}

			}

if(!episolonfound){
				break;
			}
			else{
                  continue;
			}

	}			
		
		}

 }

}

}



int main()
{
	int n;
    char c;


	/*Take INput of No of productions*/
printf("Enter the number of Production(Input<25)");
scanf("%d",&n);

/*Create a loop to take in the productions*/
for(int i=0;i<n;i++)
{
	printf("Enter production [%d]\n",i);
	//gets(production[i]);
	scanf("%s",production[i]);
	//fgets(production[i],25, stdin);
	printf("%s\n", production[i]);
}


	printf("Enter Non Terminal to find First and Follow of!");

	scanf(" %c",&c);

    //printf("First of %c is :\n",c);

    first(c,n);

//follow(c);

	return 0;

}
