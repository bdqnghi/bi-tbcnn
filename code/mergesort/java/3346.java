/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package demo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author Yash
 */
public class mergesort {


public static void main(String args[]){
    
    int arr[] = {8,4,5,1,3,6,7,3,4,5,9,8,6,1,4};
    
    display(arr) ;
    
    divideList(arr , 0 , arr.length-1 );
    
     display(arr);
    

    
}    

    private static void divideList(int[] arr, int i, int j) {
     
    //    System.out.println(i+ " - "+j);
        
        if (j-i<=0){
            return;
        }
        
        int k = (i+j)/2;
        
        divideList(arr , i , k);
        
        divideList(arr , k+1 , j);
        
        merge(arr , i , k , j);
    }

  
    private static void merge(int[] arr, int i, int k, int j) {
    
       int x=0; int y=0;
       int cnt=i;
       int s1 = k - i + 1;
       int s2 = j - k;
       
  //     System.out.println("i="+i+" k="+k+" j="+j+" size s1:"+s1+" s2:"+s2);
       int t1[]=new int[s1];
       int t2[] = new int[s2];
  //     System.out.println();
  //     System.out.println("arr t1:-");
       for(int c=0;c<s1;c++){
           t1[c] = arr[i+c];
  //         System.out.print(" "+t1[c]);
       }
      
        System.out.println("arr t2:-");
       for(int c=0;c<s2;c++){
           t2[c] = arr[k+1+c];
           
   //        System.out.print(" "+t2[c]);
       }
   //     System.out.println();
       
   
       while(x<s1 && y<s2 ){
           if (t1[x] <= t2[y]){
               arr[cnt] = t1[x];
               x++;
           }
           else {
                arr[cnt] = t2[y];
               y++;
           }
           cnt++;
    //       System.out.println("in loop");
          
       }  
       
       if (x<s1){
     //       System.out.println("t1 remained");
            
            for(int c=x;c<s1;c++) {
                arr[cnt] = t1[c];
                cnt++;
            }
            
       }
       else if (y<s2){
     //      System.out.println("t2 remained");
             for(int c=y;c<s2;c++) {
                arr[cnt] = t2[c];
                cnt++;
            }
           
       }
      //  display(arr);
   
       
    
    }

    
    
      private static void display(int[] arr) {
        System.out.println();
      for(int i=0;i<arr.length;i++){
          System.out.print(" "+arr[i]);
      }
    }

  
    
    
}
    



