package org.example;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.net.Socket;
import java.net.SocketException;
import java.util.Scanner;
import java.util.logging.Logger;
import java.util.stream.Stream;

public class Client{
    static final int port = 12345;
    static final String ip = "localhost";
    private static final Logger logger = Logger.getLogger("Client " + Thread.currentThread().getId());

    public static void main(String[] args) {

        try {
            Socket socket = new Socket(ip, port);
            Scanner scanner = new Scanner(System.in);

            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

            Message recv = (Message) in.readObject();
            logger.info("received from server: " + recv.toString());

            Integer reps = Integer.parseInt(scanner.nextLine());
            out.writeObject(new Message(0, reps.toString()));
            logger.info("sent to server: " + reps.toString());
            recv = (Message) in.readObject();
            logger.info("received from server: " + recv.toString());

            for (int i = 0; i < reps; i++) {
                Message msg = new Message(0, scanner.nextLine());
                out.writeObject(new Message(0, msg.toString()));
                logger.info("sent to server: " + msg.toString());
            }

            recv = (Message) in.readObject();
            logger.info("received from server: " + recv.toString());

            socket.close();
            scanner.close();
        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
