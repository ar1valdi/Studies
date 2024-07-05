package org.example;

import java.util.Optional;

public class MageController {
    private final MageRepository repository;

    public MageController(MageRepository repository) {
        this.repository = repository;
    }

    public String find(String name) {
        Mage foundMage = repository.find(name).orElse(null);
        if (foundMage == null) {
            return "not found";
        }
        return foundMage.toString();
    }

    public String delete(String name) {
        try {
            repository.delete(name);
            return "done";
        } catch (IllegalArgumentException ex) {
            return "not found";
        }
    }

    public String save(String name, String level) {
        try {
            repository.save(new Mage(name, Integer.parseInt(level)));
            return "done";
        } catch (IllegalArgumentException ex) {
            return "bad request";
        }
    }
}