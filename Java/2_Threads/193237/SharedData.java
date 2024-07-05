package org.example;

import java.util.LinkedList;

public class SharedData {
    static private SharedData instance;
    private LinkedList<Task> tasks;
    private LinkedList<TaskResult> results;
    static private Object exit;

    public static void exit() {
        synchronized (exit) {
           exit.notify();
        }
    }

    static SharedData createInstance(Object exitLocker) {
        if (instance == null) {
            instance = new SharedData();
            instance.tasks = new LinkedList<>();
            instance.results = new LinkedList<>();
            exit = exitLocker;
        }
        return instance;
    }
    static SharedData getInstance() {
        return instance;
    }

    static Task getNextTask() throws InterruptedException {
        synchronized (instance) {
            while (areTasksEmpty()) {
                instance.wait();
            }
            return instance.tasks.pop();
        }
    }

    static TaskResult getResult(int id) {
        return instance.results.get(id);
    }

    static void addTask(Task t) {
        synchronized (instance) {
            instance.tasks.push(t);
            instance.notify();
        }
    }

    static synchronized void addResult(TaskResult t) {
        instance.results.push(t);
    }

    static Boolean areTasksEmpty() {
        return instance.tasks.isEmpty();
    }
}
