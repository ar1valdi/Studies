package org.example;

public class CheckIfPrimeResult implements TaskResult {
    Boolean res;
    Integer data;
    int taskID;
    public int getTaskID() {
        return taskID;
    }

    CheckIfPrimeResult(Boolean b, Integer d, int taskID) {
        res = b;
        data = d;
        this.taskID = taskID;
    }

    @Override
    public Object getResult() {
        return res;
    }

    @Override
    public Object getData() {
        return data;
    }

    @Override
    public void updateResult(Object res, Object data) {
        res = (Boolean)(res);
        data = (Integer)(data);
    }

    @Override
    public String toString() {
        return "[Task:" + taskID + "] Is " + data.toString() + " prime: " + res.toString();
    }
}
