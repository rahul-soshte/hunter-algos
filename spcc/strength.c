#include<stdio.h>

void main(){
	int num,x,y,i,a,res2;
	float res1;
	printf("Enter the number\n");
	printf("1-> Multiplication converted to addition\n");
	printf("2-> Power Converted to multiplication\n");
	printf("3-> Division Converted to multiplication\n");
	scanf("%d",&a);
	if(a==1) //Multiplication converted to addition
	{
		printf("Enter the number\n");
		scanf("%d",&x);
		printf("Enter the multiplicaton factor\n");
		scanf("%d",&y);
		printf("When %d is multiplied by %d result is\n",x,y);
		printf("%d",x);
		for(i=0;i<y-1;i++){
			printf("+%d",x);
			}
	}
	else if(a==2) {
		printf("Enter the number\n");
		scanf("%d",&x);
		printf("Enter the Power factor\n");
		scanf("%d",&y);
		res2=1;
		printf("When %d is raised to power %d result is\n",x,y);
		printf("%d",x);
		for(i=0;i<y-1;i++){
			printf("*%d",x);
			}
	}
	else if(a==3) {
		printf("Enter the number\n");
		scanf("%d",&x);
		printf("Enter the Division factor\n");
		scanf("%d",&y);
		res2=1;
		printf("When %d is divided by %d result is\n",x,y);
		res1=(float)1/y;
		printf("%d*%.2f",x,res1);
	}
	else{
		printf("Wrong option");
	}
}