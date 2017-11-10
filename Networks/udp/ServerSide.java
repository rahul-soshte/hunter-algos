import java.io.*;
import java.util.*;
import java.net.*;

class ServerSide{
	public static void main(String args[]) throws IOException
	{
		DatagramSocket ss=new DatagramSocket(2100);
		byte[] sendData=new byte[1024];
		byte[] recData=new byte[1024];
		while(true)
		{
			DatagramPacket dp=new DatagramPacket(recData,recData.length);
			ss.receive(dp);
		String input=new String(dp.getData());
			if(input=="end")
			break;

		InetAddress ip=dp.getAddress();
		System.out.println("Received input:"+input);
		String output="Hello ";
		int port=dp.getPort();
		output=output.concat(input);
		sendData=output.getBytes();
		DatagramPacket dp1=new DatagramPacket(sendData,sendData.length,ip,port);
		ss.send(dp1);
			}
			ss.close();

		}
}