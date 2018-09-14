import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by nikhil on 09-09-2017.
 */
public class bubblesort {

    public static void main(String[] args) {
        int arr[] = {1,4,6,3,2,4,5,6,5,6,7,8,9,1,2,3,4,5,6,7,7};

        for(int i=0;i<arr.length; i++){

            int temp = 0;

            for(int j=0; j<arr.length-1-i; j++){

                if(arr[j] > arr[j+1]){

                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

        System.out.println(Arrays.toString(arr));


    }


}
