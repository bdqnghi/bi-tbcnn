import java.util.ArrayList;


public class quicksort{

	public static void partition(int[] a, int begin, int end){
		if(end == begin + 1) return;
		int pivot = a[begin];
		ArrayList<Integer> array = new ArrayList<Integer>();
		array.add(pivot);
		int index = begin;

		for(int i = begin+1; i < end - 1; i++){
			if(a[i] < pivot) {
				array.add(0,a[i]);
				index++;}
			else array.add(a[i]);
		}

		for(int j =0;j<array.size();j++)
			a[j] = array.get(j);

		partition(a,begin,index);
		partition(a,index+1,end);
	}



	public static void quick(int[] a){
		partition(a, 0, a.length-1);

	}

	public static void main(String[] args){
		int[] a = {87,2,245,1,8,3};
		quick(a);

		for(int i = 0; i < a.length; i++){
			System.out.print(a[i]+" ");
		}
	}
}