package org.example;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;
import java.util.logging.Logger;

public class Server {
    final static int port = 12345;
    static int clientCount = 0;

    public static void main(String[] args) {
        LinkedList<ServerThread> serverThreads = new LinkedList<>();
        Logger logger = Logger.getLogger("Server");

        try {
            ServerSocket serverSocket = new ServerSocket(port);
            logger.info("Server listening on port " + port);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                logger.info("New client connected. ID=" + clientSocket.getInetAddress());
                ServerThread serverThread = new ServerThread(clientSocket, clientCount++);
                serverThreads.push(serverThread);
                serverThread.start();
            }

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            for (Thread t : serverThreads) {
                t.interrupt();
            }
        }
    }
}
