import java.util.ArrayList;

public class MyQueue {

	ArrayList<Integer> myQueue;
	
	MyQueue() {
		myQueue = new ArrayList<Integer>();
	}
	int DeQueue() {

		if(myQueue.size()==0)
			return -1;
		
		int val;
		val = myQueue.get(0);
		myQueue.remove(0);
		return val;
	}
	
	void EnQueue(int val) {
		myQueue.add(val);
	}
	
	void Display() {
		System.out.println("Queue : ");
		for(int i=0; i<myQueue.size(); i++)
			System.out.print(myQueue.get(i)+" ");
		System.out.println();
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		MyQueue queue = new MyQueue();
		queue.EnQueue(1);
		queue.EnQueue(2);
		queue.EnQueue(3);
		queue.EnQueue(4);
		queue.Display();
		
		queue.DeQueue();
		queue.DeQueue();
		queue.Display();
	}
}
