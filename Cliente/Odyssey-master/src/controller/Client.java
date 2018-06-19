package controller;

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {

    String host;
    int port;

    Client(String host, int port) {

        this.host = host;
        this.port = port;
    }

    public String sendData(String msg) {
        try {
            String serverHostname = new String("127.0.0.1");

            System.out.println("Connecting to host " + serverHostname + " on port " + port + ".");

            Socket echoSocket = null;
            PrintWriter out = null;
            BufferedReader in = null;

            try {
                echoSocket = new Socket(serverHostname, 8081);
                out = new PrintWriter(echoSocket.getOutputStream(), true);
                in = new BufferedReader(new InputStreamReader(echoSocket.getInputStream()));
            } catch (UnknownHostException e) {
                System.err.println("Unknown host: " + serverHostname);
                System.exit(1);
            } catch (IOException e) {
                System.err.println("Unable to get streams from server");
                System.exit(1);
            }

            /** {@link UnknownHost} object used to read from console */
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));

            char buffer[] = {};

            String str = "";

            String line;

            while (true) {
                String userInput = msg;


                out.println(userInput);
                long length = 0;
                //  (line = in.readLine()) != null
                line = in.readLine();

                break;
            }

            /** Closing all the resources */
            out.close();
            in.close();
            stdIn.close();
            echoSocket.close();
            return line;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }



}