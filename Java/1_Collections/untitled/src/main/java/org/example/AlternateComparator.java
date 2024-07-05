package org.example;

import java.util.Comparator;

public class AlternateComparator implements Comparator<Mage> {
    @Override
    public int compare(Mage m1, Mage m2) {
        int result = Double.compare(m1.getPower(), m2.getPower());

        if (result == 0) {
            result = Integer.compare(m1.getLevel(), m2.getLevel());;
            if (result == 0) {
                result = m1.getName().compareTo(m2.getName());
            }
        }

        return result;
    }
}
