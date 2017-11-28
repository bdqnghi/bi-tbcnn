package ch.fhnw.algd1.mergesort;

public class Mergesort {
	public <T extends Comparable<? super T>> void mergesort(T[] a) {
		// TODO implement header method to start recursive sorting
		
	}

	private <T extends Comparable<? super T>> void sort(T[] a, int beg, int end) {
		// TODO implement recursive sorting with merge sort strategy
	}

	// Merges sequence a[beg...m-1] with a[m...end-1] into a[beg...end-1]
	private <T extends Comparable<? super T>> void merge(T[] a, int beg, int m, int end) {
		@SuppressWarnings("unchecked")
		T[] b = (T[])new Comparable[end - beg];
		// TODO copy elements from a[beg...m-1] and a[m...end-1] to b[0...]
		// TODO copy all elements from b[0...] to a[beg...]
	}
}
