package org.example;

import java.util.concurrent.ThreadLocalRandom;

public class ActorY implements Runnable{
    private final int id;
    private final int timeDelayProd;
    private final int timeDelayCons;
    private final int maxQuantityA;
    private final int maxQuantityB;
    private final Storage sA;
    private final Storage sB;
    private final String prodItemName;
    private final String consItemName;


    public ActorY(int id, Storage sA, Storage sB, int maxQuantityA, int maxQuantityB,
                  int timeDelayC, int timeDelayP, String prodItemName, String consItemName) {
        this.id = id;
        this.sA = sA;
        this.sB = sB;
        this.maxQuantityA = maxQuantityA;
        this.maxQuantityB = maxQuantityB;
        this.timeDelayProd = timeDelayP;
        this.timeDelayCons = timeDelayC;
        this.prodItemName = prodItemName;
        this.consItemName = consItemName;
    }

    @Override
    public void run() {
        System.out.println("Starting producent" + id);

        ActorX prod = new ActorX("Y", 0, sB, maxQuantityB, timeDelayProd, prodItemName);
        ActorZ cons = new ActorZ("Y", 0, timeDelayCons, maxQuantityA, sA, consItemName);
        Thread prodThread = new Thread(prod);
        Thread consThread = new Thread(cons);
        prodThread.start();
        consThread.start();

        while (!Thread.interrupted()) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                break;
            }
        }

        prodThread.interrupt();
        consThread.interrupt();
        try {
            prodThread.join();
            consThread.join();
        } catch (InterruptedException e) {
            throw new RuntimeException("Interrupted twice");
        }

        System.out.println("Y " + id + ": closed");
    }

    private void produceB() throws InterruptedException{
        int q = ThreadLocalRandom.current().nextInt(1, maxQuantityB + 1);
        Item item = new Item("B", q);
        if (sB.addItems(item)) {
            System.out.println("Y " + id + ": delivered {" + item + "}");
        } else {
            System.out.println("Y " + id + ": stopping production");
        }
    }

    private void consumeA() throws InterruptedException {
        int quantity = ThreadLocalRandom.current().nextInt(1, maxQuantityA + 1);
        Item item = new Item("A", quantity);
        Item retItem = sA.getItems(item);
        if (retItem.quantity != 0) {
            System.out.println("Y " + id + ": got {" + retItem + "}. Asked for " + item.quantity);
        } else {
            System.out.println("Y " + id + ": no {" + item + "} in storage");
        }
    }
}
