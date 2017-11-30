/**
 * Created by user on 13-Jul-17.
 */
import java.util.LinkedList;
public class bubblesort {
    public static void main(String[] args) {
        int arr[] = {1,7,2,4,9,11};
//        for(int i:arr){
//            System.out.println(i);
//        }
//        int fNum=arr[0];
//        int sNum=arr[1];
        int end=arr.length;
        int count=0;
        int temp=0;
        LinkedList ll = new LinkedList();
        while(count<end-1){
               if(arr[count]>arr[count+1])
               {
                   temp=arr[count];
                   arr[count]=arr[count+1];
                   arr[count+1]=temp;
               }
               count=count+1;
                end=end-1;
        }
        for(int i:arr){
            System.out.print(i+" ");
        }



    }

}
