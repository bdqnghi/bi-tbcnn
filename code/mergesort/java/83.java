public class mergesort{
	public static int[] merge(int[] array1, int[] array2){
		int[] result = new int[array1.length+array2.length];
		int r=0;
		int i=0;
		int j=0;

		while(i<array1.length && j<array2.length){
			if(array1[i] > array2[j]){
				result[r] = array2[j];
				r++;
				j++;
			} else {
				result[r] = array1[i];
				r++;
				i++;
			}
		}

		while(i<array1.length){
			result[r] = array1[i];
			r++;
			i++;
		}

		while(j<array2.length){
			result[r] = array2[j];
			r++;
			j++;
		}

		return result;
	}

	public static int[] mergeSort(int[] array, int left, int right){
		if(right == left){
			int[] array1 = {array[left]};
			return array1;
		}

		int mid = (right + left)/2;
		int[] array1 = mergeSort(array, left, mid);
		int[] array2 = mergeSort(array, mid+1, right);
		return merge(array1,array2);	
	}

	public static void main(String[] args){
		int[] a = {10,9,8,7,6,5,4,3,2,1};
		int[] b = mergeSort(a,0,a.length-1);

		for(int i = 0; i < b.length; i++){
			System.out.print(b[i]+" ");
		}
	}
}