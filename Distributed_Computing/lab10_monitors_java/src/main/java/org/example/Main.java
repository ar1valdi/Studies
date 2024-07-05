package org.example;

import java.util.Scanner;
import java.util.stream.Stream;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    static Storage sA, sB;
    static Thread[][] threads;
    static Thread threadLogger;
    static Logger logger;

    public static void main(String[] args) {
        sA = new Storage(Config.aCapacity);
        sB = new Storage(Config.bCapacity);

        createThreads();
        startThreads();
        Scanner s = new Scanner(System.in);
        s.nextLine();
        stopThreads();
        System.out.println("Main thread end");
        s.close();
    }

    private static void createThreads() {
        logger = new Logger("logs.csv", Config.logFreq, sA, sB);

        threads = new Thread[3][];
        threads[0] = new Thread[Config.xNum];
        threads[1] = new Thread[Config.yNum];
        threads[2] = new Thread[Config.zNum];
        threadLogger = new Thread(logger);

        for (int i = 0; i < threads[0].length; i++) {
            ActorX x = new ActorX("X", i, sA, Config.xMaxQuantityProd, Config.xDelay, "A");
            threads[0][i] = new Thread(x);
        }
        for (int i = 0; i < threads[1].length; i++) {
            ActorY y = new ActorY(i, sA, sB, Config.yMaxQuantityCons,
                    Config.yMaxQuantityProd, Config.yDelayProd, Config.yDelayCons, "B", "A");
            threads[1][i] = new Thread(y);
        }
        for (int i = 0; i < threads[2].length; i++) {
            ActorZ z = new ActorZ("Z", i, Config.zDelay, Config.zMaxQuantityCons, sB, "B");
            threads[2][i] = new Thread(z);
        }
    }

    private static void startThreads() {
        for (Thread[] thr : threads) {
            for (Thread t : thr) {
                t.start();
            }
        }
        threadLogger.start();
    }

    private static void stopThreads() {
        for (Thread[] thr : threads) {
            for (Thread t : thr) {
                t.interrupt();
            }
        }
        threadLogger.interrupt();
    }
}