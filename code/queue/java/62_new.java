package myclasses.demos.ds.link.doublelinkedlist.queue;

// TODO: Auto-generated Javadoc
/**
 * The Class LinkQueueApp.
 */
public class LinkQueueApp {
	
	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		LinkQueue queue = new LinkQueue();
		queue.enQueue(1);
		queue.enQueue(2);
		queue.enQueue(3);
		queue.enQueue(4);
		queue.enQueue(5);
		Link peek = queue.peek();
		System.out.println("peek: " + peek.iData);
		queue.display();
		queue.deQueue();
		queue.deQueue();
		queue.display();
		Link peek1 = queue.peek();
		System.out.println("peek1: " + peek1.iData);
		queue.deQueue();
		queue.deQueue();
		queue.deQueue();
		queue.enQueue(6);
		queue.enQueue(7);
		queue.enQueue(8);
		queue.display();
		

	}
}
