package org.example;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.HashMap;
import java.util.LinkedHashMap;

public class Storage {
    volatile private HashMap<String, Item> storage;
    private final int capacity;
    volatile private int itemsHeld;
    boolean logging;
    final Object getWaiter, addWaiter;

    public Storage(int capacity) {
        this.capacity = capacity;
        this.itemsHeld = 0;
        storage = new HashMap<>();
        logging = false;
        getWaiter = new Object();
        addWaiter = new Object();
    }

    public int getCurrItemsHeld() {
        return itemsHeld;
    }

    public Item getItems(Item name) {
        System.out.println("Waiting on sync getWaiter " + name.name + Thread.currentThread().getName());
        synchronized (getWaiter) {
            while (!storage.containsKey(name.name) || storage.get(name.name).quantity < name.quantity) {
                try {
                    System.out.println("Waiting on wait() getWaiter " + name.name + " " + Thread.currentThread().getName());
                    getWaiter.wait();
                } catch (InterruptedException e) {
                    Item i = new Item(name);
                    i.quantity = 0;
                    Thread.currentThread().interrupt();
                    return i;
                }
            }
            System.out.println("Passed wait() on getWaiter " + name.name + " " + Thread.currentThread().getName());

            Item i = storage.get(name.name);
            i.addItems(-name.quantity);
            itemsHeld -= name.quantity;
        }

        synchronized (addWaiter) {
            addWaiter.notify();
        }

        return new Item(name);
    }

    synchronized public boolean canFit(int quantity) {
        return itemsHeld + quantity <= capacity;
    }

    public boolean addItems(Item item) {
        synchronized (addWaiter) {
            while (!canFit(item.quantity)) {
                try {
                    addWaiter.wait();
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    return false;
                }
            }

            if (storage.containsKey(item.name)) {
                storage.get(item.name).addItems(item.quantity);
            } else {
                storage.put(item.name, item);
            }
            itemsHeld += item.quantity;
        }

        synchronized(getWaiter) {
            getWaiter.notify();
        }

        System.out.println(this);
        return true;
    }

    synchronized public int getItemsHeld() {
        return itemsHeld;
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder("Storage state\n");
        res.append(itemsHeld);
        res.append("\\");
        res.append(capacity);
        res.append("\n");
        for (var i : storage.entrySet()) {
            res.append(i.getValue());
            res.append("\n");
        }
        return res.toString();
    }
}
