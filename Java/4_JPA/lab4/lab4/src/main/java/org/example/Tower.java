package org.example;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;

import java.util.LinkedList;
import java.util.List;

@Entity
public class Tower {
    @Id
    private String name;
    private int height;
    @OneToMany(mappedBy="tower", cascade=CascadeType.REMOVE)
    private List<Mage> mages;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public List<Mage> getMages() {
        return mages;
    }

    public void setMages(List<Mage> mages) {
        this.mages = mages;
    }

    Tower(String name, int height) {
        this.name = name;
        this.height = height;
        mages = new LinkedList<>();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(name);
        sb.append("{ ");
        for (Mage m : mages) {
            sb.append(m);
            sb.append(", ");
        }
        sb.append(" }");
        return sb.toString();
    }
}
