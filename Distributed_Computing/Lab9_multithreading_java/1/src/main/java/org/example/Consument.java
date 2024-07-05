package org.example;

public class Consument implements Runnable {
    private final int id;
    private final int timeDelay;
    private final int maxQuantity;
    private final Storage s;
    private final RandomItemGenerator r;

    public Consument(int id, int timeDelay, int maxQuantity, Storage s, RandomItemGenerator r) {
        this.id = id;
        this.timeDelay = timeDelay;
        this.maxQuantity = maxQuantity;
        this.s = s;
        this.r = r;
    }

    @Override
    public void run() {
        System.out.println("Starting consument" + id);
        while (!Thread.interrupted()) {
            try {
                Item item = r.getRandomItem();
                Item retItem = s.getItems(item);
                if (retItem.quantity != 0) {
                    System.out.println("Consumer " + id + ": got {" + retItem + "}. Asked for " + item.quantity);
                } else {
                    System.out.println("Consumer " + id + ": no {" + item + "} in storage");
                }
                Thread.sleep(timeDelay);
            } catch (InterruptedException e) {
                break;
            }
        }
        System.out.println("Consumer " + id + ": closed");
    }
}
