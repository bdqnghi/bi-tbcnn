package algorithms;

public class Mergesort {
	
	int[] A = {18, 8, 58, 66, 233, 36, 28, 9, 88};
	
	public static void MergeSort() {
		int tmp = 0;
		Mergesort tt = new Mergesort();
		
		mergesort(tt.A, 0, tt.A.length-1);
		for(;tmp < tt.A.length; tmp++) {
			System.out.printf("%d ", tt.A[tmp]);
		}
	}
	
	private static void merge(int[] A, int p, int q, int r) {
		int[] L = new int[q+1-p];
		int[] R = new int[r-q];
		int i = 0;
		int j = 0;
		int k = p;
		for(; i < L.length; i++) {
			L[i] = A[k];
			k++;
		}
		i = 0;
		for(;j < R.length; j ++) {
			R[j] = A[k];
			k++;
		}
		j = 0;
		k = p;
		for(;i < L.length && j < R.length;) {
			if(L[i] < R[j]) {
				A[k] = L[i];
				i++;
				k++;
			} else {
				A[k] = R[j];
				j++;
				k++;
			}
		}
		if(i == L.length) {
			for(;j < R.length;j++) {
				A[k] = R[j];
				k++;
			}
		} else {
			for(;i < L.length;i++) {
				A[k] = L[i];
				k++;
			}
		}
	}
	
	private static void mergesort(int[] A, int p, int r) {
		int q;
		if(r > p) {
			q = (p + r) / 2;
			mergesort(A, p, q);
			mergesort(A, q+1, r);
			merge(A, p, q, r);
		}
	}
}
