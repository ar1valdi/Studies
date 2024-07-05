package org.example;

public class CountPi implements Task {
    int data;
    int taskID;

    @Override
    public int getTaskID() {
        return taskID;
    }

    CountPi(int n, int taskID) {
        data = n;
        this.taskID = taskID;
    }

    @Override
    public TaskResult doTask(TaskSolver solver) throws InterruptedException {
        int iter = 1;
        double sum = 0;
        double n = data;

        for (; iter < data; iter++) {
            sum += Math.pow(-1, iter - 1) / (2 * iter - 1);

            if (Thread.interrupted()) {
                solver.stopSolving = true;
                break;
            }
        }
        sum *= 4;
        double percent = iter / n * 100;
        return new CountPiResult(sum, percent, data, taskID);
    }

    @Override
    public void setData(Object obj) {
        data = (Integer)obj;
    }
}
