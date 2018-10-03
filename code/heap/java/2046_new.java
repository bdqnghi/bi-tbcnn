package gerasimenko.sortings.benchmarking.algorithms;

/**
 * Michael Gerasimenko
 * Date: 04.09.11
 * Time: 22:32
 */
public class HeapSort extends AbstractSort {
    int heapSize;
    long[] heap;
    public HeapSort() {
        sortingName = "Heap sort";
    }

    @Override
    protected long[] sort1(long[] a) {
        heap = a;
        heapSize = heap.length;
        for (int i = heapSize / 2; i >= 0; i--) heapify(i);
        long t;
        for (int i = heapSize - 1; i > 0; i--) {
            t = heap[0];
            heap[0] = heap[i];
            heap[i] = t;
            heapSize--;
            heapify(0);
        }

        return heap;
    }

    private void heapify(int current) {
        long x = heap[current];
        //left child
        int child = (current << 1) + 1;
        //right child
        if ((child < heapSize - 1) && (heap[child] < heap[child + 1])) child++;
        while ((child < heapSize) && (x < heap[child])) {
            heap[current] = heap[child];
            current = child;
            child = (current << 1) + 1;
            if ((child < heapSize - 1) && (heap[child] < heap[child + 1])) child++;
        }
        heap[current] = x;
    }

}
