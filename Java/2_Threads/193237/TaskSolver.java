package org.example;

public class TaskSolver extends Thread {
    public Boolean stopSolving;

    TaskSolver() {
        stopSolving = false;
    }

    @Override
    public void run() {
        stopSolving = false;

        while (!stopSolving && !Thread.interrupted()) {
            try {
                Task task = SharedData.getNextTask();
                TaskResult tr = task.doTask(this);
                SharedData.addResult(tr);
                System.out.println(Thread.currentThread().getId() + ": " + tr);
            } catch (InterruptedException ex) {
                stopSolving = true;
            }
        }

        System.out.println("Thread [TaskSolver:" + Thread.currentThread().getId() + "] turning off");
    }

    public void stopSolving() {
        stopSolving = true;
    }
}
