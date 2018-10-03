/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.example.tutorial;

/**
 *
 * @author Masudul Haque
 */

import java.util.Date;
import java.util.Queue;

public class QueueSampler// implements QueueSamplerMXBean 
{

    private Queue<String> queue;

    public QueueSampler(Queue<String> queue) {
        this.queue = queue;
    }

    public QueueSample getQueueSample() {
        synchronized (queue) {
            return null;// new QueueSample(new Date(), queue.size(), queue.peek());
        }
    }

    public void clearQueue() {
        synchronized (queue) {
            queue.clear();
        }
    }
}
