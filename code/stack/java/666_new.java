/**
 * @author Stanley Wong
 *
 */
public class StackDriver {

	public static void main(String[] args) {
		
		Stack<Integer> integerStack = new Stack<Integer>();
		
		integerStack.push(1);
		integerStack.push(2);
		integerStack.push(3);
		integerStack.push(4);

		integerStack.showStack();
		
		
		Stack<String> stringStack = new Stack<String>();
		
		stringStack.push("uno");
		stringStack.push("dos");
		stringStack.push("trace");
		stringStack.push("quttro");

		stringStack.showStack();
		stringStack.clearStack();
		stringStack.showStack();
		

	}

}
