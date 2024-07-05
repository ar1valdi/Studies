package org.example;

public class Producent implements Runnable {
    private final int id;
    private final int timeDelay;
    private final int maxQuantity;
    private final Storage s;
    private final RandomItemGenerator r;

    public Producent(int id, Storage s, int maxQuantity, int timeDelay, RandomItemGenerator r) {
        this.id = id;
        this.s = s;
        this.maxQuantity = maxQuantity;
        this.timeDelay = timeDelay;
        this.r = r;
    }

    @Override
    public void run() {
        System.out.println("Starting producent" + id);
        while (!Thread.interrupted()) {
            try {
                Item item = r.getRandomItem();
                if (s.addItems(item)) {
                    System.out.println("Producent " + id + ": delivered {" + item + "}");
                } else {
                    System.out.println("Producent " + id + ": stopping production");
                    Thread.sleep(timeDelay);
                }
                Thread.sleep(timeDelay);
            } catch (InterruptedException e) {
                break;
            }
        }
        System.out.println("Producent " + id + ": closed");
    }
}
