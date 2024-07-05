package org.example;

import java.util.Collection;
import java.util.HashSet;
import java.util.Optional;

public class MageRepository {
    private Collection<Mage> collection;

    public MageRepository() {
        collection = new HashSet<Mage>();
    }

    public Optional<Mage> find(String name) {
        if (collection.contains(new Mage(name, 0))) {
            for (Mage m : collection) {
                if (m.getPrimaryKey().equals(name)) {
                    return Optional.of(m);
                }
            }
        }
        return Optional.empty();
    }

    public void delete(String name) throws IllegalArgumentException {
        if (!collection.remove(new Mage(name, 0))) {
            throw new IllegalArgumentException();
        }
    }

    public void save(Mage mage) throws IllegalArgumentException {
        if (collection.contains(mage)) {
            throw new IllegalArgumentException();
        }
        collection.add(mage);
    }
}
