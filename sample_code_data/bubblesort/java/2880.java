package Sort;

public class Bubblesort  {
    public  static  void sort(int [] array){
    	int temp;
    	int len = array.length;
    	for(int i=0;i<len-1;i++){
    		for(int j=0;j<len-1-i;j++){
    			if(array[j]<array[j+1]){
    				temp=array[j];
    				array[j] = array[j+1];
    				array[j+1] = temp;
    			}
    		}
    	}
    }
	public static void main(String[] args) {
		int[] testarray = {1,2,3,4,5,6,7,8,9,10};
		ShowArray.show(testarray);
        sort(testarray);
        ShowArray.show(testarray);
	}

}
