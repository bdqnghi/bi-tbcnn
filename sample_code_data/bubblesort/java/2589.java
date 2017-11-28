import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;


/*
 * How to access array: myarray[0];
 * How to set value in array: myarray[0] = 4
 * Arrays have a specific length and bounds that may not be exceeded
 * You can access the the length of the array from the length property: i.e. myarray.length
 */
public class bubblesort
{
    public static void main(String[] args)
    {
        int[] myarray = new int[] { -1, -1, -2, 1, 0, 1};
        
        bubblesort(myarray);
        System.out.println(Arrays.toString(myarray));
    }
    
    public static void bubblesort(int[] array){
        
        boolean notSorted = true;
        
        while (notSorted) {
            boolean isSorted = true;
            for(int counter = 0; counter < (array.length - 1); counter++){
                int g = counter + 1;
                if (array[counter] > array[g])
                {
                    swap(array, counter, g);
                    isSorted = false;
                }
            }
            notSorted = !isSorted;
        }

    }
    
    // x = 0, y = 2
    public static void swap(int[] array, int x, int y)
    {
        int temp = array[x];
        array[x] = array[y];
        array[y] = temp;
    }
}