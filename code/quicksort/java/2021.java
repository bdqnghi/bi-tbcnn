
package temp;

public class Quicksort {
	
	public static void sort(int a[]){
		sort(a,0,a.length-1);
	}
	
	private static void sort(int a[], int low , int high){
		if ( low >= high){return;}
		int j = partition(a,low,high) ;
		sort(a,low,j-1);
		sort(a,j+1,high);
	}
	
	private static int partition(int a[],int low,int high){
		
		int N=low;
		int i=low;
		int j=high+1;
		
	while (true){
		
		
		while (a[N] > a[++i] ) { 
			if ( i == high ) { break;}
			}
		while (a[N] < a[--j]){			
		}
		
		if ( i >= j) { break;}
		
		int swap = a[j];
		a[j]=a[i];
		a[i]=swap;
		
	}
	
	int swap = a[j];
	a[j]=a[N];
	a[N]=swap;
	
	return j;
	
	}		
		

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] a = {5,4,6,3,7,8,2,10,1,0,20,40,15,2,3};
		Quicksort.sort(a);
		
		for ( int i=0; i< a.length;i++){ System.out.println(a[i]);
		}
	}

}

