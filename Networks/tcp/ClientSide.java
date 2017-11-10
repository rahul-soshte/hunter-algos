
import java.net.*;
import java.io.*;

class ClientSide{
	public static void main(String[] args) throws Exception
	{
	int ch=0,a,b,c;
	Socket s=new Socket("localhost",1024);
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(s.getOutputStream());
	System.out.println("Please Enter No1");
	a=Integer.parseInt(br.readLine());
	System.out.println("Please Enter No2");
	b=Integer.parseInt(br.readLine());
	System.out.println("Please Enter the Operation to be performed\n");
	System.out.println("1.Add 2.Sub 3.Mul 4.Div 5.Modulo 0.Exit");
	ch=Integer.parseInt(br.readLine());
	ps.println(ch);
	ps.println(a);
	ps.println(b);
	BufferedReader br1=new BufferedReader(new InputStreamReader(s.getInputStream()));
	c=Integer.parseInt(br1.readLine());
	System.out.println("Answer:"+c);
	s.close();
	}
}