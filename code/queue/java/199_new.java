package MXBean;

import java.util.Date;
import java.util.Queue;

/**
 * User: Chris
 * Date: 6/12/13
 * Time: 2:24 AM
 */
public class QueueSampler implements QueueSamplerMXBean {

    private Queue<String> queue;

    public QueueSampler(Queue<String> queue) {
        this.queue = queue;
    }

    public Sample getSample() {
        synchronized (queue) {
            return new Sample(new Date(), queue.size(), queue.peek());
        }
    }

    public void clearQueue() {
        synchronized (queue) {
            queue.clear();
        }
    }
}