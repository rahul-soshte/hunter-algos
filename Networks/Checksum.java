import java.util.*;

class Checksum{
	public static void main(String args[]){
	int section[48]={0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
	int checksum[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i;
	int sum;
	int carry=0;
	
for(i=0;i<16;i++){
		sum=section[i]+section[i+16]+section[i+32]+carry;
		switch(sum)
		{
			case 0:
			checksum[i]=0;
			carry=0;
			
			case 1:
			checksum[i]=1;
			carry=0;
			
			case 2:
			checksum[i]=1;
			carry=1;
	}
}
for(i=0;i<16;i++)
{
	System.out.print(checksum[i]);
	
}
}
}
