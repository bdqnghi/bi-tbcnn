
/**
 * http://www.java2novice.com/java-sorting-algorithms/quick-sort/
 */
public class Quicksort {

	private int length;
	private int pivot;

	public void sort(int[] inputArr) {

		if (inputArr == null || inputArr.length == 0) {
			return;
		}
		int array[] = inputArr;
		length = inputArr.length;
		pivot = array.length - 1;
		quickSort(array, length - 1);
	}

	private void quickSort(int array[], int higherIndex) {

		int i = 0;

		if (array[i] > pivot) {
			int temp = array[i];
			for (int a = i; a < pivot; a++) {
				array[a] = array[a + 1];
				pivot = a;
			}
			array[array.length - 1] = temp;
			i++;
		}

		if (0 < i) {
			int newArray[] = new int[array.length - 2];
			for (int a = 1; a < array.length; a++) {
				newArray[a - 1] = array[a];
			}
			quickSort(newArray, higherIndex);
		} else {
			int newArray[] = new int[array.length - 2];
			for (int a = 1; a < array.length; a++) {
				newArray[a - 1] = array[a];
			}
			quickSort(array, higherIndex);
		}
	}

	public static void main(String a[]) {

		Quicksort sorter = new Quicksort();
		int[] input = { 24, 2, 45, 20, 56, 75, 2, 56, 99, 53, 12 };
		sorter.sort(input);
		for (int i : input) {
			System.out.print(i);
			System.out.print(" ");
		}
	}
}