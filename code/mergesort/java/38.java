
public class Mergesort implements Sort{

	private void sort(int[] a, int[] aux, int lo, int hi) {
		if (lo >= hi)
			return;
		int mid = lo + (hi-lo)/2;
		sort(a, aux, lo, mid);
		sort(a, aux, mid+1, hi);
		merge(a, aux, lo, mid, hi);
	}

	private void merge(int[]a, int[] aux, int lo, int mid, int hi) {
		for(int i = lo; i <= hi; i++) {
			aux[i] = a[i];
		}

		int firstHalf = lo;
		int secondHalf = mid+1;
		for(int i = lo; i <= hi; i++) {
			if(firstHalf > mid) a[i] = aux[secondHalf++];
			else if(secondHalf > hi) a[i] = aux[firstHalf++];
			else if(aux[secondHalf] < aux[firstHalf]) a[i] = aux[secondHalf++];
			else a[i] = aux[firstHalf++];
		}
	}

	@Override
	public void sort(int[] a) {
		int[] aux = new int[a.length];
		sort(a, aux, 0, a.length-1);
	}
}


