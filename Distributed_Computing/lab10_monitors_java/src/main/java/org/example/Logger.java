package org.example;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Logger implements Runnable {
    private final Storage sA, sB;
    private final int timeDelay;
    private final String filePath;

    public Logger(String filePath, int timeDelay, Storage sA, Storage sB) {
        this.filePath = filePath;
        this.timeDelay = timeDelay;
        this.sA = sA;
        this.sB = sB;
    }

    @Override
    public void run() {
        BufferedWriter writer;

        while (!Thread.interrupted()) {
            try {
                Thread.sleep(timeDelay);
                int numA = sA.getItemsHeld();
                int numB = sB.getItemsHeld();
                String toLog = numA + "," + numB + '\n';
                writer = new BufferedWriter(new FileWriter(filePath, true));
                writer.write(toLog);
                writer.close();
                System.out.println("------------------Logged: " + numA + "," + numB);
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                break;
            }
        }
        System.out.println("Logger closed");
    }
}
