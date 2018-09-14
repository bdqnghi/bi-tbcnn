import java.util.*;
class BubbleSort{
	public static void main(String[] args) {
		int[] arr={90,8,57,89,45};
		int n=arr.length;
		for(int i=0;i<arr.length-1;i++){	//n-1 passes
			for(int j=0;j<n-i-1;j++){
				if(arr[j]>arr[j+1]){
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		for(int i=0;i<arr.length;i++)
			System.out.println(arr[i]);
	}
}