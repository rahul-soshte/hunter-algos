#include<stdio.h>

int main()
{
		
	int section[48]={0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
//	int section[48]={0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
//	int section[48]={1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0};

    int section1[16];
    int section2[16];

	int checksum[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i;
	int sum;
	int carry=0;

for(i=0;i<2;i++)
{
	for(i=0;<16;i++)
	{

	}
add_section
}
for(i=0;i<16;i++)
{
	printf("%d",checksum[i]);
	
}
return 0;

}

void add_section(int section1[],int section2[],int s1,int s2)
{
for(i=48;i>=32;i--){
		sum=section[i]+section[i-16]+section[i-32]+carry;
		switch(sum)
		{
			case 0:
			checksum[i-32]=0;
			carry=0;
			
			case 1:
			checksum[i-32]=1;
			carry=0;
			
			case 2:
			checksum[i-32]=0;
			carry=1;

			case 3:
			checksum[i-32]=1;
			carry=1;

	}
}
}
