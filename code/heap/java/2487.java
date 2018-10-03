import java.util.*;

public class Heap<T extends Comparable<T>> {
    
    private ArrayList<T> arr = new ArrayList<T>();
    private int heapSize = 0;

    public void add(T data) {
        arr.add(data);
        increaseValue(heapSize, data);
        heapSize++;
    }

    private int getParentIndex(int index) {
        if (index == 0) return -1;
        return ((index-1) >> 1);
    }

    private void increaseValue(int index, T value) {
        if (index <= 0) {
            return;
        }
        int parentIndex = getParentIndex(index);

        T parentVal = arr.get(parentIndex);
        if (parentVal.compareTo(value) < 0) {
            swap(arr, parentIndex, index);
            increaseValue(parentIndex, value);
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Heap array: " + arr.toString());
        sb.append("\nTree looks like:\n");
        for (int i = 0, pow=1; i < heapSize; i++) {
            sb.append(arr.get(i) + " ");
            if (i == ((int) Math.pow(2, pow) - 2)) {
                sb.append("\n");
                pow++;
            }
        }
        sb.append("\n");
        return sb.toString();
    }

    private void swap(ArrayList<T> arr, int i, int j) {
        T temp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, temp);
    }
}
