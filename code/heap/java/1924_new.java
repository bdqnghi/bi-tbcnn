package Heaps;

public class Binary implements ListOperator {

    private int[] heap;
    private int heap_size;

    public Binary(int[] heap, int heap_size) {
        this.heap = heap;
        this.heap_size = heap_size;
    }

    public int[] getHeap() {
        return heap;
    }

    public void setHeap(int[] heap) {
        this.heap = heap;
    }

    public int getHeap_size() {
        return heap_size;
    }

    public void setHeap_size(int heap_size) {
        this.heap_size = heap_size;
    }

    public int getMin() {
        return heap[1];
    }

    public void dec_key(int i, int newk) {
        if (i > heap_size) {
            return;
        }
        if (newk < heap[i]) {
            heap[i] = newk;
            while (i > 1 && heap[parent(i)] > heap[i]) {
                heap[i] = heap[parent(i)];
                i = parent(i);
            }
            heap[i] = newk;
        }
    }

    public void insert(int k) {
        setHeap_size(heap_size + 1);
        if (heap == null || heap.length == 2) {
            if (heap == null) {
                heap = new int[2];
            }
            heap[1] = k;
            return;
        }
        if (heap_size >= heap.length) {
            moreLength();
        }
        int i = heap_size;
        while (i > 1 && heap[parent(i)] > k) {
            heap[i] = heap[parent(i)];
            i = parent(i);
        }
        heap[i] = k;

    }

    public int del_min() {
        int min = getMin();
        heap[1] = heap[heap_size];
        heap[heap_size] = Integer.MAX_VALUE;
        heapify(1);
        setHeap_size(heap_size - 1);
        return min;
    }

    public void heapify(int i) {
        if (i == heap_size) {
            return;
        }
        int l = left(i);
        int r = right(i);
        int min = 0;
        if (r < heap_size + 1) {
            if (heap[l] < heap[r]) {
                min = l;
            } else {
                min = r;
            }
            if (heap[i] > heap[min]) {
                int temp = heap[i];
                heap[i] = heap[min];
                heap[min] = temp;
                heapify(min);
            }
        } else if (l == heap_size && heap[l] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[l];
            heap[l] = temp;
        }
    }

    public void merge(Binary b) {
        int[] b_heap = b.getHeap();
        int b_heap_size = b.getHeap_size();

        boolean same = false;
        for (int i = 1; i <= b_heap_size; i++) {
            for (int j = 1; j < heap_size + 1; j++) {
                if (heap[j] == b_heap[i]) {
                    same = true;
                    break;
                }
            }
            if (!same) {
                insert(b_heap[i]);
            }
            same = false;
        }
    }


    public int parent(int i) {
        return i / 2;
    }

    public int left(int i) {
        return 2 * i;
    }

    public int right(int i) {
        return 2 * i + 1;
    }

    @Override
    public void moreLength() {
        int new_size = heap.length + (heap.length / 2);
        int[] new_heap = initializeHeap(new int[new_size]);
        System.arraycopy(heap, 0, new_heap, 0, heap.length);
        setHeap(new_heap);
    }

    public int[] initializeHeap(int[] h) {
        for (int i = 0; i < h.length; i++) {
            h[i] = Integer.MAX_VALUE;
        }
        return h;
    }
}
