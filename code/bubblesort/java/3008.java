
public class Bubblesort {
public static void main(String[] args) {
	int arr[]= {5, 12, 14, 6, 78, 19, 1, 23, 26, 35, 37, 7, 52, 86, 47};
	int i=0,j=0,temp,len;
	len=arr.length;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	System.out.println("sorted array is: ");
	for(i=0;i<len;i++)
	{
		System.out.println(arr[i]);
	}
}
}
