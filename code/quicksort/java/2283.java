import java.util.*;

public class Quicksort {
	
	static void quickSort(int[] nums){
		ArrayList<Integer> elements = new ArrayList<Integer>();
		for(int el : nums){
			elements.add(el);
		}
		partition(elements);
	}
	
	static ArrayList<Integer> partition(ArrayList<Integer> nums){
		if(nums.size() <= 1){//this is sorted
			return nums;
		}
		
		int pivot = nums.get(0);
		ArrayList<Integer> left = new ArrayList<Integer>();
		ArrayList<Integer> equal = new ArrayList<Integer>();
		ArrayList<Integer> right = new ArrayList<Integer>();
		
		for(int el : nums){
			if(el < pivot){
				left.add(el);
			} else if(el == pivot){
				equal.add(el);
			} else{
				right.add(el);
			}
		}
		
		ArrayList<Integer> out = catenate(partition(left), partition(equal), partition(right));
		printArray(out);
		return out;
	}
	
	/**
	 * Put together the less than, equal and greater array bits in order
	 * @param left ArrayList of elements less than pivot
	 * @param equal ArrayList of elements equal to pivot
	 * @param right ArrayList of elements greater than pivot
	 * @return int[] of the elements in the order strung together
	 */
	static ArrayList<Integer> catenate(ArrayList<Integer> left, ArrayList<Integer> equal, ArrayList<Integer> right){
		ArrayList<Integer> out = new ArrayList<Integer>();

		for(int el : left){
			out.add(el);
		}
		for(int el : equal){
			out.add(el);
		}
		for(int el : right){
			out.add(el);
		}
		
		return out;
	}
	
	static void printArray(ArrayList<Integer> ar) {
		for(int n: ar){
			System.out.print(n+" ");
		}
		System.out.println("");
	}
	   
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] ar = new int[n];
		for(int i=0;i<n;i++){
			ar[i]=in.nextInt(); 
		}
		quickSort(ar);
		in.close();
	}    

}
