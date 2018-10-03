public class MyHeap {
    private MyHeapGenerics<Integer> heap;
    private boolean maxHeap;
    public MyHeap(boolean a) {
	heap = new MyHeapGenerics(a);
	maxHeap = a;
    }

    public MyHeap() {
	heap = new MyHeapGenerics();
    }

    public String toString() {
	return heap.toString();
    }

    public int remove() {
	return heap.remove();
    }

    public void add(int a) {
	heap.add(a);
    }

    public int peek() {
	if (heap.peek() == null) {
	    if (maxHeap) {
		return Integer.MIN_VALUE;
	    }
	    else {
		return Integer.MAX_VALUE;
	    }
	}
	else {
	    return heap.peek();
	}
    }
}