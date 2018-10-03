package com.borqs.server.platform.util.sender;


import com.borqs.server.platform.mq.QueueName;

public abstract class AbstractQueueSender<T> implements AsyncSender<T> {
    protected QueueName queue;

    protected AbstractQueueSender() {
    }

    public QueueName getQueue() {
        return queue;
    }

    public void setQueue(QueueName queue) {
        this.queue = queue;
    }

    @Override
    public void asyncSend(T o) {
        if (o != null)
            queue.getQueue().send(queue.getName(), o);
    }
}
