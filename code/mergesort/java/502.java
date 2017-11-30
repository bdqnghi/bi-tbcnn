import java.util.Scanner;
import java.util.Random;
public class mergesort 
{ static final int max=10005;
  static int[]a=new int[max];
  public static void main(String[] args) 
  { Scanner ip=new Scanner(System.in);
    System.out.println("enter max array size");
    int n=ip.nextInt();
    Random random=new Random();
    for(int i=0;i<n;i++)
    	a[i]=5000+random.nextInt(15000);
    long startTime=System.nanoTime();
    mergesortAlgorithm(0,n-1);
    long stopTime=System.nanoTime();
    long elapsedTime=stopTime-startTime;
    System.out.println("sorted array");
    for(int i=0;i<n;i++)
    	System.out.println(a[i]+" ");
    System.out.println("time complexity(ms)for n="+n+"is"+(double)elapsedTime/1000000);
    ip.close();
   }
  public static void mergesortAlgorithm(int low,int high)
  {int mid;
   if(low<high)
   { mid=(low+high)/2;
    mergesortAlgorithm(low,mid);
    mergesortAlgorithm(mid+1,high);
    merge(low,mid,high);
   }
  }
  public static void merge(int low,int mid,int high)
  { int[] b=new int[max];
    int i,h,j,k;
    h=i=low;
    j=mid+1;
    while((h<=mid)&&(j<=high))
    	if(a[h]<a[j])
    		b[i++]=a[h++];
    	else
    		b[i++]=a[j++];
   if(h>mid)
    	for(k=j;k<=high;k++)
    		b[i++]=a[k];
    else
    	for(k=h;k<=mid;k++)
    		b[i++]=a[k];
    for(k=low;k<=high;k++)
    	a[k]=b[k];
   }
}
