
//stable sort time complex nlogn
//it merge two or more sorted list into one list, dive-and-comquer althgrithm
public class mergesort{
	public static void mergeSort(int[] arrays){
		sort(arrays,0,arrays.length-1);
	}

	public static void sort(int[] arrays,int left,int right){
		if(left >= right){return;}
		int center =(left+right)/2;
		sort(arrays,left,center);//left recursion
		sort(arrays,center+1,right);//right recursion
		merge(arrays,left,center,right);//merge left and right parts
		AtoString(arrays);
	}

	public static void AtoString(int[] array){
        for(int i:array){
            System.out.print(i+"   ");
        }
        System.out.println();
    }

    public static void merge(int[] arrays,int left,int center,int right){
    	int[] tmpA = new int[arrays.length];//temp arrays to store smaller elements
    	int mid = center+1;
    	int third = left;
    	int tmp = left;

    	while(left <= center && mid <=right){//pick the smaller one into temp list
    		if(arrays[left] <= arrays[mid])
    			tmpA[third++] =arrays[left++];
    		else{
    			tmpA[third++] = arrays[mid++];
    		}
    	}

    	while(mid <= right){//the left elements add to the tmp list
    		tmpA[third++] = arrays[mid++];
    	}
    	while(left <= center){
    		tmpA[third++] =arrays[left++];
    	}

    	while (tmp <= right) {  
            arrays[tmp] = tmpA[tmp++];  
        }  

    }

	public static void main(String[] args) {

		 int[] data = new int[] { 5, 3, 6, 2, 1, 9, 4, 8, 7 };  
        AtoString(data);  
        mergeSort(data);  
        System.out.println("after sout:");  
        AtoString(data); 
	}
}