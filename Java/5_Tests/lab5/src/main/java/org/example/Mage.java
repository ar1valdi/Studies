package org.example;

public class Mage {

    public String name;
    public int level;

    Mage(String name, int level) {
        this.name = name;
        this.level = level;
    }

    public String getPrimaryKey() {
        return name;
    }

    @Override
    public int hashCode() {
        return getPrimaryKey().hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Mage mage = (Mage) obj;
        return getPrimaryKey().equals(mage.getPrimaryKey());
    }

    @Override
    public String toString() {
        return "MAGE{name='" + name + "', level=" + level + "}";
    }
}
