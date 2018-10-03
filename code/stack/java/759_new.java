package collections;

public class TransparentStackSwapper implements StackSwapper {

	private TransparentObjectStack stackA;
	private TransparentObjectStack stackB;
	
	public TransparentStackSwapper(TransparentObjectStack stackA, TransparentObjectStack stackB) {
		this.stackA = stackA;
		this.stackB = stackB;
	}
	
	public TransparentObjectStack getStackA() {
		return stackA;
	}
	
	public TransparentObjectStack getStackB() {
		return stackB;
	}
	
	public void swapAToB() {
		if(!stackB.isFull() && stackA.size() > 1) {
			stackB.push(stackA.peek());
			stackA.pop();
		}
	}
	
	public void swapBToA() {
		if(!stackA.isFull() && stackB.size() > 1) {
			stackA.push(stackB.peek());
			stackB.pop();
		}
	}
}