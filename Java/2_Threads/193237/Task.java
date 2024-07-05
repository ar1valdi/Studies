package org.example;

public interface Task {

    TaskResult doTask(TaskSolver solver) throws InterruptedException;

    public void setData(Object obj);
    public int getTaskID();
}