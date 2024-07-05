package org.example;

import java.util.ArrayList;
import java.util.Random;

import static java.lang.Math.abs;

public class RandomItemGenerator {
    private final ArrayList<Item> availableItems;
    private final Random random;
    private final int maxQuantity;

    synchronized public Item getRandomItem() {
        int idx = abs(random.nextInt()) % availableItems.size();
        int q = abs(random.nextInt()) % maxQuantity;
        Item i = availableItems.get(idx);
        i.setQuantity(q);
        return new Item(i);
    }

    public RandomItemGenerator(int maxQuantity) {
        random = new Random();
        this.maxQuantity = maxQuantity;
        ArrayList<Item> toInit = new ArrayList<>();
        toInit.add(new Item("A", 1));
        toInit.add(new Item("Battery", 1));
        toInit.add(new Item("Monitor", 1));
        toInit.add(new Item("Smartphone", 1));
        toInit.add(new Item("Washing machine", 1));
        toInit.add(new Item("Freezer", 1));
        toInit.add(new Item("TV", 1));
        toInit.add(new Item("Charger", 1));
        toInit.add(new Item("Microwave", 1));
        availableItems = new ArrayList<>(toInit);
    }
}
