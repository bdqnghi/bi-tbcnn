package heap;

public class MaxHeap {

	int cap;
	int len;
	int[] heap;

	MaxHeap(int cap) {
		this.cap = cap;
		this.len = 0;
		this.heap = new int[cap];
	}

	void push(int val) {
		if (len < cap) {
			heap[len++] = val;
			up(len - 1);
		} else {
			if (val < heap[0]) {
				heap[0] = val;
				down(0);
			}
		}
	}

	int pop() {
		int ret = heap[0];
		heap[0] = heap[--len];
		down(0);
		return ret;
	}

	int peek() {
		return heap[0];
	}

	void down(int i) {
		int tmp = heap[i];
		for (int child = i * 2 + 1; child < len; child = i * 2 + 1) {
			if (child + 1 < len && heap[child + 1] > heap[child]) {
				++child;
			}
			if (tmp < heap[child]) {
				heap[i] = heap[child];
				i = child;
			} else {
				break;
			}
		}
		heap[i] = tmp;
	}

	void up(int i) {
		int tmp = heap[i];
		while (i > 0) {
			int parent = (i - 1) / 2;
			if (tmp > heap[parent]) {
				heap[i] = heap[parent];
				i = parent;
			} else {
				break;
			}
		}
		heap[i] = tmp;
	}

}
