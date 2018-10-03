package myclasses.demos.ds.link.priorityqueue.q1;

import java.awt.DisplayMode;

// TODO: Auto-generated Javadoc
/**
 * The Class PriorityQueueApp.
 */
public class PriorityQueueApp {

/**
 * The main method.
 *
 * @param args the arguments
 */
public static void main(String[] args) {
	PriorityQueue priorityQueue = new PriorityQueue();
	priorityQueue.enQueue(3);
	priorityQueue.enQueue(2);
	priorityQueue.enQueue(1);
	priorityQueue.enQueue(4);
	priorityQueue.enQueue(5);
	priorityQueue.display();
	priorityQueue.deQueue();
	priorityQueue.deQueue();
	priorityQueue.display();
}
}
