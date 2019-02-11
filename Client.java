import java.net.*;
import java.io.*;

public class Client
{
    private static final String HOST = "localhost";
    private static final int PORT = 5000;

    public Client()
    {
        try {
            Socket s = new Socket(HOST, PORT);
            DataInputStream in = new DataInputStream(s.getInputStream());
            DataOutputStream out = new DataOutputStream(s.getOutputStream());
            System.out.println("Connected");

            out.writeUTF("Hello, I'm Client.");

            String msg = in.readUTF();
            System.out.println("Received: " + msg);

            in.close();
            out.close();
            s.close();
        } catch (IOException i) {
        }
    }

    public static void main(String args[])
    {
        Client client = new Client();
    }
}