package org.example;


import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Mage.setMode(args[0].charAt(0));

        Mage m1 = new Mage("Janek", 10, 10);
        Mage m2 = new Mage("Janek2", 12, 10);
        Mage m3 = new Mage("Janek3", 103, 10);
        Mage m4 = new Mage("Janek4", 103, 10);
        Mage m5 = new Mage("Janek5", 103, 11);
        Mage m6 = new Mage("Janek6", 103, 12);
        Mage m7 = new Mage("Janek7", 103, 13);
        Mage m8 = new Mage("Janek8", 103, 14);
        Mage m9 = new Mage("Janek9", 103, 15);
        Mage m10 = new Mage("Janek10", 103, 16);
        Mage m11 = new Mage("Janek11", 103, 17);

        m1.addApprentice(m2);
        m1.addApprentice(m3);
        m2.addApprentice(m4);
        m2.addApprentice(m5);
        m3.addApprentice(m6);
        m3.addApprentice(m7);
        m4.addApprentice(m8);
        m4.addApprentice(m9);
        m5.addApprentice(m10);
        m5.addApprentice(m11);

        System.out.println(m1.getViewWithApprentices());

        Map<Mage, Integer> map = m1.getApprenticesMap();
        for (Mage m : map.keySet()) {
            System.out.println(m.toString() + ": " + map.get(m));
        }
    }
}
// imie level moc
// moc level imie