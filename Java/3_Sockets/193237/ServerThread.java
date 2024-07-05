package org.example;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.SocketException;
import java.util.LinkedList;
import java.util.logging.Logger;
import java.net.Socket;

public class ServerThread extends Thread {
    int clientID;
    private static final Logger logger = Logger.getLogger("Server thread " + ServerThread.currentThread().getId());
    Socket clientSocket;

    ServerThread(Socket clientSocket, int clientID) {
        this.clientID = clientID;
        this.clientSocket = clientSocket;
    }

    @Override
    public void run() {
        try {
            ObjectOutputStream out = new ObjectOutputStream(clientSocket.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(clientSocket.getInputStream());

            out.writeObject(new Message(0, "ready"));
            logger.info("sent to client " + clientID + ": ready");

            Message msg = (Message) in.readObject();
            logger.info("received from client " + clientID + ": " + msg.toString());
            int reps = Integer.parseInt(msg.toString());

            out.writeObject(new Message(0, "ready for messages"));
            logger.info("sent to client " + clientID + ": ready for messages");


            LinkedList<Message> reqs = new LinkedList<>();
            for (int i = 0; i < reps; i++) {
                msg = (Message)in.readObject();
                logger.info("received from client " + clientID + ": " + msg.toString());
                reqs.push(msg);
            }
            out.writeObject(new Message(0, "finished"));
            logger.info("sent to client " + clientID + ": finished");

            in.close();
            out.close();
            clientSocket.close();
            System.out.println();
            System.out.println("Disconnected client " + clientID);
        } catch (SocketException e) {
            System.out.println("Lost connection with client " + clientID);
        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
