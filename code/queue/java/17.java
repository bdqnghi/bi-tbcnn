/**
 * Your queue implementation. Don't add any new public methods.
 * 
 * @author Steven Wojcio
 *
 */
public class Queue<T> implements QueueInterface<T> {

	private LinkedListInterface<T> queue = new LinkedList<T>();

	@Override
	public void enqueue(T t) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public T dequeue() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int size() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return false;
	}
	
}
