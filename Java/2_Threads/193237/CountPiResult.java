package org.example;


import java.util.LinkedList;

public class CountPiResult implements TaskResult {
    LinkedList<Double> result;
    int iter_depth;
    int taskID;

    CountPiResult(double pi, double percent, int iter_depth, int taskID) {
        result = new LinkedList<>();
        result.push(percent);
        result.push(pi);
        this.iter_depth = iter_depth;
        this.taskID = taskID;
    }

    @Override
    public int getTaskID() {
        return taskID;
    }

    @Override
    public Object getResult() {
        return result;
    }

    @Override
    public Object getData() {
        return iter_depth;
    }

    @Override
    public void updateResult(Object res, Object data) {
        result = (LinkedList<Double>)res;
        iter_depth = (int)data;
    }

    @Override
    public String toString() {
        return "[Task:" + taskID + "] Calculate PI with depth=" + iter_depth + ": " + result.getFirst() + ". Completed " + result.getLast() + "%.";
    }
}
