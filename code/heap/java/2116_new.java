package algorithms.sort;

/**
 * 堆排序，不稳定，最差时间复杂度O(n*logn)，最优时间复杂度O(n*logn)，平均时间复杂度O(n*logn)，需要辅助空间O(1)
 * http://www.cnblogs.com/developerY/p/3319618.html
 * 
 * @author liuduo
 *
 */
public class HeapSort extends Sort {

	@Override
	public void sort(int[] a) {
		MaxHeap mh = new MaxHeap(a);
		mh.buildMaxHeap();
		mh.heapSort();
	}

	public static void main(String[] args) {
		new HeapSort().sort();
	}
}

class MaxHeap {
	int[] heap;
	int heapSize;

	public MaxHeap(int[] heap) {
		this.heap = heap;
		this.heapSize = heap.length;
	}

	public int parent(int i) {
		return (i - 1) / 2;
	}

	public int left(int i) {
		return 2 * i + 1;
	}

	public int right(int i) {
		return 2 * i + 2;
	}

	private void maxify(int i) {
		int l = left(i);
		int r = right(i);
		int largest = l < heapSize && heap[l] > heap[i] ? l : i;
		if (r < heapSize && heap[r] > heap[largest])
			largest = r;
		if (largest == i)
			return;
		int t = heap[i];
		heap[i] = heap[largest];
		heap[largest] = t;
		maxify(largest);
	}

	public void buildMaxHeap() {
		for (int i = heapSize / 2 - 1; i >= 0; i--)
			maxify(i);
	}

	public void heapSort() {
		for (int i = 0; i < heap.length - 1; i++) {
			int t = heap[0];
			heap[0] = heap[heapSize - 1];
			heap[heapSize - 1] = t;
			heapSize--;
			maxify(0);
		}
	}
}
