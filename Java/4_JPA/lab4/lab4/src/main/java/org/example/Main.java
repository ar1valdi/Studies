package org.example;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import org.hibernate.query.SyntaxException;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static EntityManager em;

    public static void addToDB(Object o) {
        try {
            em.getTransaction().begin();
            em.persist(o);
            em.getTransaction().commit();
            System.out.println(o + " added");
        } catch (Exception e) {
            em.getTransaction().rollback();
            System.out.println(o + " not added due to exception: " + e);
        }
    }

    public static void removeMageFromDB(String name) {
        removeMageFromDB(em.find(Mage.class, name));
    }

    public static void removeMageFromDB(Mage m) {
        try {
            em.getTransaction().begin();
            em.remove(m);
            em.getTransaction().commit();

            if (m.getTower() != null) {
                m.getTower().getMages().remove(m);
            }

            System.out.println(m + " removed");
        } catch (Exception e) {
            em.getTransaction().rollback();
            System.out.println(m + " not removed due to exception: " + e);
        }
    }

    public static void removeTowerFromDB(String name) {
        removeTowerFromDB(em.find(Tower.class, name));
    }

    public static void removeTowerFromDB(Tower t) {
        try {
            em.getTransaction().begin();
            em.remove(t);
            em.getTransaction().commit();

            System.out.println(t + " removed");
        } catch (Exception e) {
            em.getTransaction().rollback();
            System.out.println(t + " not removed due to exception: " + e);
        }
    }

    public static void printMagesAndTowers() {
        printQuery("SELECT t FROM Tower t");
        printQuery("SELECT m FROM Mage m");
    }

    public static void printQuery(String s) {
        try {
            int i = 1;
            List<Object> towers = new LinkedList<Object>(em.createQuery(s).getResultList());
            for (Object t : towers) {
                System.out.println(i++ + ": " + t);
            }
        }
        catch(Exception ex) {
            System.out.println("Wrong query: " + ex);
        }
    }

    public static void connect(Mage m, Tower t) {
        t.getMages().add(m);
        if (m.getTower() != null) {
            m.getTower().getMages().remove(m);
        }
        m.setTower(t);
    }

    public static void loadDefDB() {
        Mage mage1 = new Mage("Gandalf", 100);
        Mage mage2 = new Mage("Voldemort", 101);
        Mage mage3 = new Mage("Harry", 15);

        Tower tower1 = new Tower("Wieza1", 10);
        Tower tower2 = new Tower("Wieza2", 10);
        Tower tower3 = new Tower("Wieza3", 10);

        addToDB(mage1);
        addToDB(mage2);
        addToDB(mage3);
        addToDB(tower1);
        addToDB(tower2);
        addToDB(tower3);

        connect(mage1, tower1);
        connect(mage2, tower2);
        connect(mage3, tower3);
    }

    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("MagesDB");
        em = emf.createEntityManager();

        loadDefDB();
        printMagesAndTowers();

        String comm = "-1";
        Scanner scanner = new Scanner(System.in);
        while (!comm.equals("8")) {
            System.out.println("=======================================");
            System.out.println("1. Add Mage");
            System.out.println("2. Add Tower");
            System.out.println("3. Remove Mage");
            System.out.println("4. Remove Tower");
            System.out.println("5. Print query");
            System.out.println("6. Print database");
            System.out.println("7. Print mage above x level from certain tower");
            System.out.println("8. Exit");
            System.out.println("=======================================");
            comm = scanner.nextLine();
            switch (comm) {
                case "1": addMage(); break;
                case "2": addTower(); break;
                case "3": removeMage(); break;
                case "4": removeTower(); break;
                case "5": printQuery(); break;
                case "6": printMagesAndTowers(); break;
                case "7": printMagesFromTowerAboveLevel(); break;
                default: break;
            }
        }

        scanner.close();
        em.close();
        emf.close();
    }

    public static void addMage() {
        Scanner scanner = new Scanner(System.in);
        Mage m = new Mage("", 0);
        System.out.println("Name: ");
        m.setName(scanner.nextLine());
        System.out.println("Level: ");
        m.setLevel(Integer.parseInt(scanner.nextLine()));
        System.out.println("Tower: ");
        connect(m, em.find(Tower.class, scanner.nextLine()));
        addToDB(m);
    }
    public static void addTower() {
        Scanner scanner = new Scanner(System.in);
        Tower t = new Tower("", 0);
        System.out.println("Name: ");
        t.setName(scanner.nextLine());
        System.out.println("Height: ");
        t.setHeight(Integer.parseInt(scanner.nextLine()));
        addToDB(t);
    }
    public static void removeMage() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Name: ");
        removeMageFromDB(scanner.nextLine());
    }
    public static void removeTower() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Name: ");
        removeTowerFromDB(scanner.nextLine());
    }
    public static void printQuery() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Query: ");
        printQuery(scanner.nextLine());
    }

    public static void printMagesFromTowerAboveLevel() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Tower name: ");
        String towerName = scanner.nextLine();
        System.out.println("Min level inclusive: ");
        int level = Integer.parseInt(scanner.nextLine());
        Tower tower = em.find(Tower.class, towerName);
        for (Mage m : tower.getMages()) {
            if (m.getLevel() >= level) {
                System.out.println(m);
            }
        }
    }
}