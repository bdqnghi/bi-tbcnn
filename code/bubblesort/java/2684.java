package SortingAlgoithim;

public class bubblesort {
	public static void main(String[] args){
		int [] shuzu = {16,7,10,9,14,8,3,2,4,1};
		bubblesort(shuzu);
		for(int i=0;i<shuzu.length;i++)
			System.out.println("index��"+i+" "+"shuzhi��"+shuzu[i]);
		}
	public static void bubblesort(int[] a){
		for(int j = 0;j<a.length;j++)
			for(int i = 0;i<a.length-1-j;i++){
				if(a[i]>a[i+1]){
					int temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
				}
			}
	}
}
