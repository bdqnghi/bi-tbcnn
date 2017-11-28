package Algorithms;

public class Mergesort {
	public static void mergeSort(int[] a) {
		int[] helper = new int[a.length];
		mergeSort(a, helper, 0, a.length - 1);
	}
	
	public static void mergeSort(int[] a, int[] helper, int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;
			mergeSort(a, helper, low, mid);
			mergeSort(a, helper, mid + 1, high);
			merge(a, helper, low, mid, high);
		}
	}
	
	public static void merge(int[] a, int[] helper, int low, int mid, int high) {
		for (int i = low; i <= high; i++)
			helper[i] = a[i];
		
		int helperLeft = low;
		int helperRight = mid + 1;
		int current = low;
		
		while (helperLeft <= mid && helperRight <= high) {
			if (a[helperLeft] <= helper[helperRight]) {
				a[current] = helper[helperLeft];
				helperLeft++;
			} else {
				a[current] = helper[helperRight];
				helperRight++;
			}
			
			current++;
		}
		
		int remaining = mid - helperLeft;
		
		for (int i = 0; i <= remaining; i++)
			a[current + i] = helper[helperLeft + i];
	}
}