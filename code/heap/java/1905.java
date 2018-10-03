class Node
{
	public int data;
	public Node(int key) {
		data = key;
	}
} 
public class Heap {
	private int currentSize = 0;

	public int getCurrentSize() {
		return currentSize;
	}
	public void insert(int i, Node[] H) {
		siftUp(H, getCurrentSize());
		currentSize++;
	}
	public void siftUp(Node[] heap, int c) {
		int p = (c - 1)/2;
		while(!(c == 0)) {
			if(heap[p].data < heap[c].data) {
				int temp = heap[p].data;
				heap[p].data = heap[c].data;
				heap[c].data = temp;
			} else {
				return;
			}
			c = p;
			p = (c - 1)/2;
		}
	}
	public void deleteMin(Node[] H) {
		H[0] = H[getCurrentSize() - 1];
		siftDown(H, getCurrentSize());
		currentSize--;
	}
	public void siftDown(Node[] heap, int size) {
		int p = 0, c = 1;
		while(c < size) {
			if(heap[c].data < heap[c+1].data && c + 1 < size) {
				c = c+1;
			}
			if(heap[p].data < heap[c].data) {
				int temp = heap[c].data;
				heap[c].data = heap[p].data;
				heap[p].data = temp;
			}
			p = c;
			c = 2*p + 1;
		}
	}
	public static void main(String[] args) {

	}
}
