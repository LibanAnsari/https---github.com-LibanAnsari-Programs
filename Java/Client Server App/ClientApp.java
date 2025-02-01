import java.io.*;
import java.net.*;

public class ClientApp {
	public static void main(String[] args) {

		try{	
			Socket socketObj=new Socket("localhost",4007);
	
			DataOutputStream outStreamObj=new DataOutputStream(socketObj.getOutputStream());

			outStreamObj.writeUTF("Hi, This is my First Message");
			outStreamObj.flush();

			outStreamObj.close();
			socketObj.close();

		}catch(Exception ex){
			System.out.println("Socket Excpetion"+ex);
		}
	}
}