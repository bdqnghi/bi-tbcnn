/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sorting;

/**
 *
 * @author bharathsurampudi
 */
public class Bubblesort {
    public void printArray(int []arr){
        for(int i = 0;i< arr.length;i++){
            System.out.print(arr[i]+ " ");
        }
        System.out.println();
    }
    public void sort(int []arr){
        for(int i = 0; i < arr.length;i++){
            for(int j = 1 ; j < arr.length;j++){
                if(arr[j-1] > arr[j]){
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        
    }
    public static void main(String []args){
        int [] arr = {13,29,41,72,32,64,8,9,24,6};
        Bubblesort ob = new Bubblesort();
        System.out.print("Given Array is ");
        ob.printArray(arr);
        ob.sort(arr);
        System.out.print("Sorted Array is ");
        ob.printArray(arr);
    }
    
}
