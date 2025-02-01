import java.io.*;
import java.net.*;

public class ServerApp {
	public static void main(String[] args){

		try{
			ServerSocket objServerSocket=new ServerSocket(4007);
			Socket objSocket=objServerSocket.accept();//establishes connection 

			DataInputStream objDataInputStream=new DataInputStream(objSocket.getInputStream());

			String	str=(String)objDataInputStream.readUTF();
			System.out.println("Received message = "+str);

			objServerSocket.close();

		}catch(Exception ex){
			System.out.println("Service Exception"+ex);
		}
	}
}