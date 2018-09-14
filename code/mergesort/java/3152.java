
public class Mergesort {

	public static void main(String[] args) {
		Mergesort qs = new Mergesort();
		qs.sort(qs.arr);
		for (int i = 0; i < qs.arr.length; i++) {
			System.out.print(qs.arr[i] + ",");
		}
	}

	private int[] arr = { 23, 8, 9, 3, 0, 24, 5, 7, 9, 123 };
//	private int[] arr = { 23, 8, 9};
	private int[] helpArr;

	private int arrLength;

	public void sort(int[] arr) {
		this.arr = arr; // use the specific plus generic term.
		arrLength = arr.length;
		this.helpArr = new int[arrLength];
		mergeSort(0, arrLength - 1);
	}

	private void mergeSort(int lo, int hi) {
		// check if lo is smaller then hi, if not then the array is sorted
		// SPLIT TO ONLY 1 ELEMENT
        // How come this become lower than hi value ?
			int mid = lo + (hi - lo) / 2;
		if (lo < hi) {
			// Get the index of the element which is in the mid, why is this ?
			// Sort the left side of the array
            // how does the recurrsive happen?
			mergeSort(lo, mid);
			// Sort the right side of the array
			mergeSort(mid + 1, hi);
			// Combine them both
			merge(lo, mid, hi);
		}
	}

	private void merge(int lo, int mid, int hi) {

		// Copy both parts into the helpArr array
		//HELPER ARRAY. 
		for (int i = lo; i <= hi; i++) {
			helpArr[i] = arr[i];
		}

		int helpLo = lo;
		int helpMid = mid;
		int oriLo = lo; // beloning,specific, and generic.
		// Copy the smallest values from either the left or the right side back
		// to the original array
		
		
		//COMPARE AND SWITCH
        // can use while to simulate 2 variable loop.
        // how to decide the boundary value.

        while (helpLo <= mid-1 && helpMid <= hi) {
            if (helpArr[helpLo] <= helpArr[helpMid]) {
                // copy back to original array.
				arr[oriLo] = helpArr[helpLo];
                // how to increment this one? copied, then put in original array.
				helpLo++;
			} else {
				arr[oriLo] = helpArr[helpMid];
                // copied, then put in the original array and increment the number.
				helpMid++;
			}
			oriLo++;
		}
		//COPY LFET. 

        while (helpLo <= mid-1) {
			arr[oriLo] = helpArr[helpLo];
			oriLo++;
			helpLo++;
		}
		// Copy the rest of the left side of the array into the target array
		
		//
		// senario 1:  9,8,7,4,3,2,1  ,  1,2,3,4, then stop, still need to copy left side
		// senario 2:  1,2,3,9,5,6,0. All right is move, but one left is still pending.
		
		


	}
}