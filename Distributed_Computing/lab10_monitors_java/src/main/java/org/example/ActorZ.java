package org.example;

import java.util.concurrent.ThreadLocalRandom;

public class ActorZ implements Runnable {
    private final int id;
    private final int timeDelay;
    private final int maxQuantity;
    private final Storage s;
    private final String name;
    private final String itemName;

    public ActorZ(String name, int id, int timeDelay, int maxQuantity, Storage s, String itemName) {
        this.id = id;
        this.name = name;
        this.timeDelay = timeDelay;
        this.maxQuantity = maxQuantity;
        this.s = s;
        this.itemName = itemName;
    }

    @Override
    public void run() {
        System.out.println("Starting consument" + id);
        while (!Thread.interrupted()) {
            try {
                int quantity = ThreadLocalRandom.current().nextInt(1, maxQuantity + 1);
                Item item = new Item(itemName, quantity);
                Item retItem = s.getItems(item);
                if (retItem.quantity != 0) {
                    System.out.println(name + " " + id + ": got {" + retItem + "}. Asked for " + item.quantity);
                } else {
                    System.out.println(name + " " + id + ": no {" + item + "} in storage");
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
