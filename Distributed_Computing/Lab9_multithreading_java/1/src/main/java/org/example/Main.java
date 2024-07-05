package org.example;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    public static void main(String[] args) {
        final int prodNum = 5;
        final int consNum = 5;
        ExecutorService esProd = Executors.newFixedThreadPool(prodNum);
        ExecutorService esCons = Executors.newFixedThreadPool(consNum);

        Storage s = new Storage(100);
        RandomItemGenerator r = new RandomItemGenerator(10);
        ArrayList<Producent> producents = new ArrayList<>(prodNum);
        ArrayList<Consument> consuments = new ArrayList<>(consNum);

        for (int i = 0; i < prodNum; i++) {
            producents.add(i, new Producent(i+1, s, 10, 1000*(i+2), r));
            esProd.submit(producents.get(i));
        }

        for (int i = 0; i < consNum; i++) {
            consuments.add(i, new Consument(i+1, 500*(i+2), 10, s, r));
            esCons.submit(consuments.get(i));
        }

        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        esProd.shutdownNow();
        esCons.shutdownNow();
        scanner.close();
    }
}