import java.io.*;

public class CSCAN{
	public static void main(String[] args) throws IOException{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	int a,b,c,d=1,i,hm=0,head,temp;
	int anarray[]=new int[30];

	System.out.println("\n\n Program Name:CSCAN Disk Scheduling\n");
	System.out.println("\n\nEnter number of process:");
	a=Integer.parseInt(br.readLine());
	System.out.println("Initial Head Position:");
	b=Integer.parseInt(br.readLine());
	System.out.println("\n");
	anarray[0]=0;
	for(c=1;c<=a;c++)
	{
		System.out.printl("Request #"+d+":");
		anarray[c]=Integer.parseInt(br.readLine());
		d++;

	}
	anarray[c]=199;
	c++;
	anarray[c]=b;
	for(c=0;c<a+2;c++)
	{
		for
	}
	}

}