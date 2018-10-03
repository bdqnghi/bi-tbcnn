package simulator;

/**
 * This class simulates the car wash. The
 * 
 * @author emmacarlsson, sophiacaspar, malinross
 * 
 */
public class Simulator {

	private EventQueue eventQueue;

	/**
	 * The constructor.
	 * 
	 * @param eventQueue
	 *            Creates the queue.
	 */
	public Simulator(EventQueue eventQueue) {
		setEventQueue(eventQueue);
	}

	/**
	 * Stars the queue.
	 */
	public void run() {
		do {
			Event event = eventQueue.first();
			eventQueue.removeFirst();
			event.execute();

		} while (!eventQueue.isEmpty());
	}

	/**
	 * 
	 * @param eventQueue
	 *            Initiates the queue.
	 */
	public void setEventQueue(EventQueue eventQueue) {
		this.eventQueue = eventQueue;
	}

}
