package QuickSort;

public class Stack {
	public class task {
		int low;
		int high;
		task next;
		private task(int low, int high) {
			this.low = low;
			this.high = high;
		}
	}
	task top;
	public Stack() {
		top = null;
	}
	public boolean isEmpty() {
		return top == null;
	}
	public void push(int low, int high) {
		task t = new task(low, high);
		t.next = top;
		top = t;
	}
	public task pop() {
		task t = top;
		top = top.next;
		return t;
	}
}
