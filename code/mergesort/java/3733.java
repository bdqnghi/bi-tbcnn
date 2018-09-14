import java.util.ArrayList;
import java.util.Arrays;
public class Mergesort{
    public ArrayList<Integer> merge(ArrayList<Integer> a, ArrayList<Integer> b){
	ArrayList<Integer> c = new ArrayList<Integer>();
	while(b.size() > 0 || a.size() > 0){
	    if(b.size()==0){
		c.add(a.remove(0));
	    } else if (a.size() == 0){
	        c.add(b.remove(0));
	    } else if (a.get(0) > b.get(0)){
		c.add(b.remove(0));
	    } else {
		c.add(a.remove(0));
	    }
	}
	return c;
    }

    public int[] merge(int[] a, int[] b){
	int[] c = new int[a.length+b.length];
	int aindex=0;
	int bindex=0;
	int cindex=0;
	while(aindex<a.length&&bindex<b.length){
	    if(a[aindex]<=b[bindex]){
		c[cindex]=a[aindex];
		aindex++;
	    }else{
		c[cindex]=b[bindex];
		bindex++;
	    }
	    cindex++;
	}
	if(aindex<a.length){
	    for(int i=aindex; i<a.length; i++){
		c[b.length+i]=a[i];
	    }
	}
	if(bindex<b.length){
	    for(int i=bindex; i<b.length; i++){
		c[a.length+i]=b[i];
	    }
	}
	return c;
    }

    public int[] msort(int[] L){
	if(L.length <= 1){
	    return L;
	}else{
	    int[] a = new int[L.length/2];
	    int[] b = new int[L.length-a.length];
	    for(int i=0; i<a.length; i++){
		a[i]=L[i];
	    }
	    for(int i=0; i<b.length; i++){
		b[i]=L[a.length+i];
	    }	
	    int[] r1 = msort(a);
	    int[] r2 = msort(b);
	    return merge(r1,r2);
	}
    }

    public static void main(String[] args){
	Mergesort m = new Mergesort();
	int[] x = {1,4,5};
	int[] y = {3,6,9,22};
	System.out.println(Arrays.toString(m.merge(x,y)));
	int[] z = {3,1,4,1,5,9,2,6,5,3,5};
	System.out.println(Arrays.toString(m.msort(z)));
    }
}
