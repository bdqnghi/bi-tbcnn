package org.stringtree.jms;

import javax.jms.Queue;
import javax.jms.QueueReceiver;

public class InMemoryQueueReciever extends InMemoryMessageConsumer implements QueueReceiver {

    private InMemoryQueue queue;

    public InMemoryQueueReciever(Queue queue, String selector, boolean running) {
        super(selector, running);
        this.queue = (InMemoryQueue) queue;
        this.queue.setListener(this);
    }

    public InMemoryQueueReciever(Queue queue, boolean running) {
        this(queue, null, running);
    }

    public Queue getQueue() {
        return queue;
    }
}
