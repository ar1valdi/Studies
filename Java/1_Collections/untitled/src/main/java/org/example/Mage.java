package org.example;

import javafx.util.Pair;
import sun.reflect.generics.tree.Tree;

import java.util.*;

import static java.lang.Double.doubleToLongBits;

public class Mage implements Comparable<Mage> {
    public String getName() {
        return name;
    }

    private String name;

    public int getLevel() {
        return level;
    }

    private int level;

    public double getPower() {
        return power;
    }

    public Set<Mage> getApprentices() {
        return apprentices;
    }

    private double power;

    static public void setMode(char mode) {
        Mage.mode = mode;
    }
    static private char mode = 'u';

    private Set<Mage> apprentices;

    @Override
    public int compareTo(Mage m) {
        int result = name.compareTo(m.name);

        if (result == 0) {
            result = Integer.compare(level, m.level);
            if (result == 0) {
                result = Double.compare(power, m.power);
            }
        }

        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Mage{name='");
        sb.append(name);
        sb.append("', level=");
        sb.append(level);
        sb.append("', power=");
        sb.append(power);
        sb.append("}");
        return sb.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }

        Mage converted = (Mage) obj;
        return  this.name.equals(converted.name) &&
                this.level == converted.level &&
                this.power == converted.power &&
                this.apprentices.equals(converted.apprentices);
    }

    @Override
    public int hashCode() {
        long powerBits = doubleToLongBits(power);

        int hash = name.hashCode();
        hash &= level;
        hash &= powerBits;
        hash &= apprentices.hashCode();

        return hash;
    }

    public void addApprentice(Mage newAppr) {
        apprentices.add(newAppr);
    }

    public Mage(String nName, int nLevel, double nPower) {
        name = nName;
        level = nLevel;
        power = nPower;
        if (mode == 'u') {
            apprentices = new HashSet<>();
        } else if (mode == 's') {
            apprentices = new TreeSet<>();
        } else {
            apprentices = new TreeSet(new AlternateComparator());
        }
    }

    public Mage(String nName, int nLevel, double nPower, boolean sortedSet) {
        name = nName;
        level = nLevel;
        power = nPower;
        if (sortedSet) {
            apprentices = new HashSet<>();
        } else {
            apprentices = new TreeSet<>();
        }
    }

    public Mage(String nName, int nLevel, double nPower, AlternateComparator ac) {
        name = nName;
        level = nLevel;
        power = nPower;
        apprentices = new TreeSet<>(ac);
    }

    public String getViewWithApprentices() {
        Stack<MageStackNode> mageStack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        mageStack.push(new MageStackNode(this, "1."));

        while (!mageStack.isEmpty()) {
            MageStackNode ms = mageStack.pop();

            sb.append(ms.prefix);
            sb.append(" Mage{name='");
            sb.append(ms.m.name);
            sb.append("' level='");
            sb.append(ms.m.getLevel());
            sb.append("' power='");
            sb.append(ms.m.getPower());
            sb.append("'}\n");

            Integer counter = ms.m.apprentices.size();
            for (Mage n : ms.m.apprentices) {
                mageStack.push(new MageStackNode(n, "   " + ms.prefix + (counter--).toString() + '.'));
            }
        }

        return sb.toString();
    }

    public Map<Mage, Integer> getApprenticesMap() {
        Map<Mage, Integer> map = mode == 'u' ? new HashMap<>() : new TreeMap<>();
        Pair<Mage, Integer> p = getApprenticesMapRec(this, map);
        map.put(p.getKey(), p.getValue());
        return map;
    }

    private Pair<Mage, Integer> getApprenticesMapRec(Mage start, Map<Mage, Integer> map) {
        if (start.apprentices.isEmpty()) {
            return new Pair<>(start, 0);
        }
        int cumsum = 0;
        for (Mage m : start.apprentices) {
            Pair<Mage, Integer> toAdd = getApprenticesMapRec(m, map);
            map.put(toAdd.getKey(), toAdd.getValue());
            cumsum += toAdd.getValue() + 1;
        }
        return new Pair<>(start, cumsum);
    }
}
