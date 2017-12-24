import java.util.Stack;

public class StackStack<T> {

	private Stack<T> elementsStack;
	private Stack<Integer> counterStack;

	public StackStack() {
		elementsStack = new Stack<T>();
		counterStack = new Stack<Integer>();
	}

	public T peek() {
		if(!counterStack.empty()) {
			return elementsStack.peek();
		} else {
			return null;
		}
	}

	public void begin() {
		counterStack.push(0);
	}

	public void push(T el) {
		int count = counterStack.pop();
		counterStack.push(count + 1);
		elementsStack.push(el);
	}

	public T pop() {
		if(!counterStack.empty()) {
			int count = counterStack.pop();
			counterStack.push(count - 1);
			return elementsStack.pop();
		} else {
			return null;
		}
	}

	public void end() {
		if(!counterStack.empty()) {
			counterStack.pop();
		}
	}

	public String toString() {
		int aux, tabs = 0;
		boolean end = false;
		T el;

		while(!end) {
			aux = counterStack.pop();
			while(aux > 0) {
				el = elementsStack.pop();
				for(int i = 0; i < tabs * 2; i += 1) {
					System.out.print(".");
				}
				System.out.println(el);
				aux -= 1;
			}
			tabs += 1;
			if(elementsStack.empty()) {
				end = true;
			}
		}
		return "";
	}

	public int size() {
		if(counterStack.empty()) {
			return 0;
		}
		int count = counterStack.pop();
		counterStack.push(count);

		return count;
	}

	public boolean empty() {
		return counterStack.empty();
	}

}