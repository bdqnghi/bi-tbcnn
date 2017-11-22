package bubblesort;
import java.util.Scanner;

public class bubblesort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner s = new Scanner(System.in);
        System.out.println("Enter no. of  elements to sort");
        int n = s.nextInt();
        System.out.println("Input "+n+"  nos.");
        int[] num = new int[n];
        for (int i = 0; i< n; i++) {
        	System.out.println("Enter no. "+(i+1)+": ");
        	int ntemp = s.nextInt();
        	num[i] = ntemp;
        }
        num = bubbleSort (num);
        for (int i =0; i< num.length; i++) {
        	System.out.println(num[i]);
        }
	}
    public static int[] bubbleSort(int[] arr){
    	for(int i =0; i< arr.length; i++) {
    		for(int j = arr.length-1; j<arr.length;j--){
    			if(arr[j]<arr[j-1]){
    				int temp = arr[j];
    				arr[j] = arr[j-1];
    				arr[j-1] = temp;
    			}
    		}
    	}
    	return arr;
    }  
}
