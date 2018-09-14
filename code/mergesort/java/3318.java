import java.io.*;
import java.util.*;
public class Mergesort  {

    public static ArrayList<String> mergesort(ArrayList<String> c) {
	if (c.size() <= 1) {
	    return c;
	}

	ArrayList <String> a = new ArrayList <String> (c.size()/2);
        ArrayList <String> b = new ArrayList <String> (c.size() - a.size());
	int i;
	for (i = 0; i < a.size(); i++) {
	    (a.get(i)).set(i, (c.get(i)));
	}
	for (; i < b.size(); i++) {
	    b[c.size()-i-1] = c[i];//why?
	}
	    
	a = mergesort(a);
	b = mergesort(b);
	
        ArrayList<String>  merged = merge(a,b);
	return merged;
	
    }
    public static  ArrayList <String>  merge(ArrayList <String> a, 
					     ArrayList <String> b) {
	ArrayList <String> merged = new int[a.size()+ b.size()];
	//System.out.println(merge);
	int indexa = 0;
	int indexb = 0;
	int indexm = 0;
	while (indexa < a.size() && indexb < b.size())  {
	    if (a[indexa]<b[indexb]) {
		merged[indexm].set(a[indexa]);indexa++;
	    }  else {
		merged[indexm].set(b[indexb]);indexb++;
	    }
	    indexm++;
	}

	if (indexa>=a.size()) {
	    for (;indexm<merged.size();indexm++){
		merged[indexm].set(b[indexb]);indexb++;
	    }
	} else {
	    for (;indexm<merged.size();indexm++){
		merged[indexm].set(a[indexa]);indexa++;
	    }
	}
	return merged;
    }


    //MY CODE:
    /*  if (a.length <= indexa) {
	for (int j: b) {
	merge[indexm] = b[j];
	//indexm ++;
	//System.out.println(merge);
	}
	}
	else if (b.length <= indexb) {
	for (int i = indexa; i <a.length; i++) {
	merge[indexm] = a[indexa];
	//indexm ++;
	//System.out.println(merge);
	}
	}
	else if (a[indexa] < b[indexb]) {
	merge[indexm] = a[indexa];
	indexa ++;
	//indexm ++;
	//System.out.println(merge);
	}
	else{
	merge[indexm] = b[indexb];
	indexb ++;
	//indexm ++;
	//System.out.println(merge);
	} 
	indexm ++;
	}
    
	return merge;
	}*/
    public static String linsearch(String s, ArrayList <String> a) {
	for (int i = 0; i < a.size(); i++) {
	    if ((a.get(i)).equals(s)) {
		    return i;
		}
	}
	    
    }
    public static void main (String[] args) {
	int[] a = new int[]{1,5,8,10,14,20,34};
	int[] b = new int[]{2,4,8,12,18,24,39,45};
	System.out.println(mergesort(a));
	System.out.println(mergesort(b));
    }
}
	
