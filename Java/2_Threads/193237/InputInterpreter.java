package org.example;

import java.util.Scanner;

public class InputInterpreter extends Thread {
    Scanner scanner;
    boolean exit = false;
    int taskCounter = 0;

    InputInterpreter(java.io.InputStream in) {
        scanner = new Scanner(in);
    }

    InputInterpreter() {
        scanner = new Scanner(System.in);
    }

    private void handleCommand(String comm) {
        int num = comm.indexOf(' ');
        num = num == -1 ? comm.length() : num;
        String commName = comm.substring(0, num);
        String s;
        switch (commName) {
            case "prime":
                s = comm.substring(comm.indexOf(' ') + 1);
                num = Integer.parseInt(s);
                SharedData.addTask(new CheckIfPrime(num, taskCounter++));
                break;
            case "exit":
                SharedData.exit();
                exit = true;
                break;
            case "pi":
                s = comm.substring(comm.indexOf(' ') + 1);
                num = Integer.parseInt(s);
                SharedData.addTask(new CountPi(num, taskCounter++));
                break;
            default:
                System.out.println("Unknown command");
        }
    }

    @Override
    public void run() {
        while (!exit) {
            String input = scanner.nextLine();

            try {
                handleCommand(input);
            } catch (NumberFormatException ex){
                System.out.println("Invalid data");
            }
        }

        System.out.println("Thread [InputInterpreter:" + Thread.currentThread().getId() + "] turning off");
    }
}
