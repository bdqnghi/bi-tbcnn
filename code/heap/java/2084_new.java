package sample;

public class Heap {
	private int[] heap;
	private int size;

	public void push(int x) {
		int i = size++;

		while (i > 0) {
			int p = (i - 1) / 2;

			if (heap[p] <= x)
				break;

			heap[i] = heap[p];
			i = p;
		}
		heap[i] = x;
	}

	public int pop() {
		int result = heap[0];
		int x = heap[--size];
		int i = 0;
		while (i * 2 + 1 < size) {
			int a = i * 2 + 1, b = i * 2 + 2;
			if (b < size && heap[a] > heap[b]) {
				b = a;
			}

			if (x <= heap[a]) {
				break;
			}
			heap[i] = heap[a];
			i = a;
		}
		heap[i] = x;
		return result;
	}
}
