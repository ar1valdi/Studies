package org.example;

public class Item {
    String name;
    int quantity;

    public Item(String n, int quantity) {
        name = n;
        this.quantity = quantity;
    }
    public Item() {
        name = "";
        quantity = 0;
    }
    public Item(Item i) {
        name = i.name;
        quantity = i.quantity;
    }

    void addItems(int i) {
        quantity += i;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    @Override
    public int hashCode() {
        return name.hashCode();
    }
    @Override
    public String toString() {
        return name + ": " + quantity;
    }
}
