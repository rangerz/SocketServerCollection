import java.net.*;
import java.io.*;

public class Server
{
    private static final String HOST = "localhost";
    private static final int PORT = 5000;

    public Server()
    {
        try {
            ServerSocket server = new ServerSocket(PORT);
            System.out.println("Server start...");

            Socket s = server.accept();
            DataInputStream in = new DataInputStream(s.getInputStream());
            DataOutputStream out = new DataOutputStream(s.getOutputStream());

            String msg = in.readUTF();
            System.out.println("Client Message: " + msg);

            out.writeUTF("Hello, I'm Server.");

            in.close();
            out.close();
            s.close();
            server.close();
        } catch (IOException e) {
        }
    }

    public static void main(String args[])
    {
        Server server = new Server();
    }
}