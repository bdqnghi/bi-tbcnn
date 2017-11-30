package sorting;

public class Bubblesort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[] = {3,7,1,8,2,4,3,7,5};
		int temp;
		for(int i=0; i<a.length; i++)
		{
		  for(int j=0; j<a.length-i-1; j++)
		  {
		    if( a[j] > a[j+1])
		    {
		      temp = a[j];
		      a[j] = a[j+1];
		      a[j+1] = temp;
		    } 
		  }
		}
		for(int i=0;i<a.length;i++)
			System.out.println(a[i]);
		
	}
}
