package org.example;


import java.util.LinkedList;

public class Main {
    public static final Object exitLocker = new Object();

    public static void waitForNotify() {
        synchronized (exitLocker) {
            try {
                exitLocker.wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void main(String[] args) {
        final int SOLVER_NUM = Integer.parseInt(args[0]);

        SharedData.createInstance(exitLocker);
        LinkedList<Thread> threadGroup = new LinkedList<>();

        for (int i = 0; i < SOLVER_NUM; i++) {
            TaskSolver thread = new TaskSolver();
            threadGroup.push(thread);
            thread.start();
        }

        InputInterpreter input = new InputInterpreter();
        threadGroup.push(input);
        input.start();

        waitForNotify();

        for (Thread th : threadGroup) {
            th.interrupt();
        }

        System.out.println("Thread [Main:" + Thread.currentThread().getId() + "] turning off");
    }
}