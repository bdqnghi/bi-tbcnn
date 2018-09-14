
package algorithms.Sorting;

/**
 *
 * @author JoseLlorens
 * Testing version.
 */
public class Mergesort {
    public static <T extends Comparable<T>> void mergesort(T[] ar){
        mergesort (ar,0,ar.length-1);
    }
    public static <T extends Comparable<T>> void mergesort (T[] ar, int i, int f){
        if(i<f){
            int m = (i+f)/2;
            mergesort(ar,i,m);
            mergesort(ar,m+1,f);
            merge(ar,i,f,m);
        }
    }
    public static <T extends Comparable<T>> void merge(T[] ar, int i, int f,int m){
        T[] aux = (T[]) new Comparable[f-i+1];
        int k=0,a=i,b=m+1;
        while(a<=m && b <= f){
            if(ar[a].compareTo(ar[b])<0){
                aux[k] = ar[a];
                k++;
                a++;
            }else{
                aux[k]=ar[b];
                k++;
                b++;
            }
        }
        while(a<=m){
            aux[k]=ar[a];
            k++;
            a++;
        }
        while(b<=f){
            aux[k]=ar[b];
            k++;
            b++;
        }
        for(a=i,k=0;a<=f;a++,k++) ar[a]=aux[k];
    }
    
}
