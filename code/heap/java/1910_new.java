package HeapSort;

public class HeapSort {
	public void buildHeap(int[] arr) {
		for(int i = 0; i < arr.length; i++) {
			siftUp(arr, i);
		}
	}
	public void siftUp(int[] heap, int c) {
		int p = (c - 1)/2;
		while(!(c == 0)) {
			if(heap[p] < heap[c]) {
				int temp = heap[p];
				heap[p] = heap[c];
				heap[c] = temp;
			} else {
				return;
			}
			c = p;
			p = (c - 1)/2;
		}
	}
	public void deleteMin(int[] heap) {
		System.out.println(heap);
	}
	public void siftDown(int[] heap, int size) {
		int p = 0, c = 1;
		while(c < size) {
			if(heap[c] < heap[c+1] && c + 1 < size) {
				c = c+1;
			}
			if(heap[p] < heap[c]) {
				int temp = heap[c];
				heap[c] = heap[p];
				heap[p] = temp;
			}
			p = c;
			c = 2*p + 1;
		}
	}
	public void sort(int[] heap) {
		for(int i = heap.length - 1; i >= 0; i--) {
			int temp = heap[0];
			heap[0] = heap[i];
			heap[i] = temp;
			siftDown(heap, i);
		}
	}
	public static void main(String[] args) {
		int[] arr = {3,2,4,6,2};
		HeapSort heap = new HeapSort();
		heap.buildHeap(arr);
		for(Integer i: arr) {
			System.out.print(i + " ");
		}
		System.out.println();
		heap.sort(arr);
		for(Integer i: arr) {
			System.out.print(i + " ");
		}
	}

}
