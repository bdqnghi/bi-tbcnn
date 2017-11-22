import java.util.Arrays;

public class Mergesort {
  public static void main(String []args){
    int a[]={49,38,65,97,76,13,27,49,78,34,12,64,5,4,62,99,98,54,56,17,18,23,34,15,35,25,53,51};
    int numbers [] = sorting(a,0,a.length-1);
    System.out.println(Arrays.toString(numbers));
  }

public static int[] sorting(int[] data, int left, int right) {
    // TODO Auto-generated method stub
    if(left<right){
        //find the center
        int center=(left+right)/2;
        //recursively sort the left part
        sorting(data,left,center);
        //recursively sort the right part
        sorting(data,center+1,right);
        //merge
        return merge(data,left,center,right);

    }
    return data;
}
public static int[] merge(int[] data, int left, int center, int right) {
    // TODO Auto-generated method stub
    int [] tmpArr=new int[data.length];
    int mid=center+1;
    //third log the center
    int third=left;
    int tmp=left;
    while(left<=center&&mid<=right){

   //choose the smaller of the two arrays to the middle arrays
        if(data[left]<=data[mid]){
            tmpArr[third++]=data[left++];
        }else{
            tmpArr[third++]=data[mid++];
        }
    }
    //rest part put into the arrays sequentially
    while(mid<=right){
        tmpArr[third++]=data[mid++];
    }
    while(left<=center){
        tmpArr[third++]=data[left++];
    }
    //Copy the middle part to the original arrays
    while(tmp<=right){
        data[tmp]=tmpArr[tmp++];
    }
    return data;
    //System.out.println(Arrays.toString(data));
}

}
