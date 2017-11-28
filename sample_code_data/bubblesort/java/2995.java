package java7finalproject.Holder;

public class Bubblesort implements Sortable {
    @Override
    public void sort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int temp = 0;
            if (array[i - 1] > array[i]) {
                temp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = temp;
            }
        }

    }

    @Override
    public String getName() {
        return "Bubblesort";
    }
}
