package eclipsepackage;

import java.util.Arrays;
public class bubblesort {
	  
	  
    public static void main(String args[]) {
     
        int[] unsorted = {32, 39,21, 45, 23, 3};
        bubbleSort(unsorted);
      
    }   
  
    
    public static void bubbleSort(int[] unsorted){
        System.out.println("unsorted array before sorting : " + Arrays.toString(unsorted));
      
       
        for(int i=0; i<unsorted.length -1; i++){
          
          
            for(int j= 1; j<unsorted.length -i; j++){
              
               
                if(unsorted[j-1] > unsorted[j]){
                    int temp = unsorted[j];
                    unsorted[j] = unsorted[j-1];
                    unsorted[j-1] = temp;
                }
            }
            System.out.printf("unsorted array after %d pass %s: %n", i+1, Arrays.toString(unsorted));
        }
    }

}

