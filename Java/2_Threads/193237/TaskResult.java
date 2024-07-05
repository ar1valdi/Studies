package org.example;

public interface TaskResult {
    public Object getResult();
    public Object getData();
    public void updateResult(Object res, Object data);
    public int getTaskID();
}
