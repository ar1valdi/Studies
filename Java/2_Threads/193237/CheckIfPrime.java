package org.example;

import java.util.Random;

public class CheckIfPrime implements Task{
    int data = 0;
    int taskID;

    @Override
    public int getTaskID() {
        return taskID;
    }

    CheckIfPrime(int n, int taskID) {
        data = n;
        this.taskID = taskID;
    }

    @Override
    public TaskResult doTask(TaskSolver solver) throws InterruptedException{
        try {
            Thread.sleep((new Random()).nextInt(501) + 500);
        } catch (IllegalArgumentException ex) {
            throw new RuntimeException(ex);
        }

        if (data == 2) {
            return new CheckIfPrimeResult(true, data, taskID);
        }
        if (data < 2) {
            return new CheckIfPrimeResult(false, data, taskID);
        }

        for (int i = 2; i < Math.sqrt(data); i++) {
            if (data % i == 0) {
                return new CheckIfPrimeResult(false, data, taskID);
            }
        }

        return new CheckIfPrimeResult(true, data, taskID);
    }

    @Override
    public void setData(Object obj) {
        data = (Integer)(obj);
    }
}
