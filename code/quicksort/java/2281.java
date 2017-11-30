import java.lang.*;
import java.io.*;
import java.util.*;
public class Quicksort{
  private  static int sz;
  private static int arr[];
  public static void main(String args[])
  {
    arr=read();
    printarr();
    quicksort(0,sz-1);
    printarr();
  }
  
  private static void quicksort(int l,int r)
  {
    if(l<r)
    {
      int s=partition(l,r);
      quicksort(l,s-1);
      quicksort(s+1,r);
    }
  }
  
  private static int partition(int l,int r)
  {
    int p=arr[l];
    int i=l+1,j=r;
    for(;i<j;)
    {
      for(;arr[i]<p && i<=r;i++);
      for(;arr[j]>p && j>=l;j--);
      if(i<=r && j>=l)
      {
        swap(i,j);
      }
    }
    swap(i,j);
    swap(l,j);
    return j;
  }
  
  private static void swap(int i,int j)
  {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }
  
  private static void printarr()
  {
    for(int i:arr)
      System.out.print(i+" ");
    System.out.println();
  }
  
  private static int[] read()
  {
    println("Enter the Size of the array needed to be sorted:");
    Scanner cin=new Scanner(System.in);
    sz=cin.nextInt();
    int a[]=new int[sz];
    println("Enter the "+sz+" number of elements for the array:");
    for(int i=0;i<sz;i++)
      a[i]=cin.nextInt();
    return a;
  }
  
  private static void println(Object line)
  {
    System.out.println(line);
  }
}