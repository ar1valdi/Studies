package org.example;

import java.util.concurrent.ThreadLocalRandom;

public class ActorX implements Runnable {
    private final int id;
    private final int timeDelay;
    private final int maxQuantity;
    private final Storage s;
    private final String name;
    private final String itemName;

    public ActorX(String name, int id, Storage s, int maxQuantity, int timeDelay, String itemName) {
        this.id = id;
        this.itemName = itemName;
        this.s = s;
        this.maxQuantity = maxQuantity;
        this.timeDelay = timeDelay;
        this.name = name;
    }

    @Override
    public void run() {
        System.out.println("Starting producent" + id);
        while (!Thread.interrupted()) {
            try {
                int q = ThreadLocalRandom.current().nextInt(1, maxQuantity + 1);
                Item item = new Item(itemName, q);
                if (s.addItems(item)) {
                    System.out.println(name + " " + id + ": delivered {" + item + "}");
                } else {
                    System.out.println(name + " " + id + ": stopping production");
                    Thread.sleep(timeDelay);
                }
                Thread.sleep(timeDelay);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }
        System.out.println(name + " " + id + ": closed");
    }
}
