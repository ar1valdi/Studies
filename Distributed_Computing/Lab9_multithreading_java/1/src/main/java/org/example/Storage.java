package org.example;

import java.util.HashMap;
import java.util.LinkedHashMap;

public class Storage {
    volatile private HashMap<String, Item> storage;
    private final int capacity;
    volatile private int itemsHeld;

    public Storage(int capacity) {
        this.capacity = capacity;
        this.itemsHeld = 0;
        storage = new HashMap<>();
    }

    public int getCurrItemsHeld() {
        return itemsHeld;
    }

    synchronized public Item getItems(Item name) {
        int itemsGot = 0;
        if (storage.containsKey(name.name)) {
            Item i = storage.get(name.name);
            if (i.quantity >= name.quantity) {
                i.addItems(-name.quantity);
                itemsHeld -= name.quantity;
                itemsGot = name.quantity;
            } else if (i.quantity > 0) {
                itemsGot = i.quantity;
                i.quantity = 0;
                itemsHeld -= i.quantity;
            }
        }
        Item toRet = new Item(name);
        toRet.quantity = itemsGot;
        return toRet;
    }

    synchronized public boolean canFit(int quantity) {
        return itemsHeld + quantity <= capacity;
    }

    synchronized public boolean addItems(Item item) {
        if (!canFit(item.quantity)) {
            return false;
        }
        if (storage.containsKey(item.name)) {
            storage.get(item.name).addItems(item.quantity);
        } else {
            storage.put(item.name, item);
        }
        itemsHeld += item.quantity;

        System.out.println(this);
        return true;
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
