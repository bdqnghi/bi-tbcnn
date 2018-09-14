class mergesort{
	public static void main(String[] args){
		int[] a={3,5,4,6,1,7};
		int n=a.length;
		mergesort ms=new mergesort();
		ms.breakandmerge(a);
		for(int i=0;i<n;i++){
			System.out.print(a[i]+" ");
		}
	}
	void breakandmerge(int[] a){
		int n=a.length;
		if(n<2){
			return;
		}
		int mid=n/2;
		int[] l=new int[mid];
		int[] r=new int[n-mid];
		for(int i=0;i<mid;i++){
			l[i]=a[i];
		}
		for(int i=mid;i<n;i++){
			r[i-mid]=a[i];
		}
		breakandmerge(l);
		breakandmerge(r);
		mergeit(l,r,a);
	}
	void mergeit(int[] l, int[] r, int[] a){
		int i=0, j=0, k=0;
		int nl=l.length;
		int nr=r.length;
		while(i<nl&&j<nr){
			if(l[i]<=r[j]){
				a[k]=l[i];
				i++;
				k++;
			}
			else{
				a[k]=r[j];
				j++;
				k++;
			}
		}
		while(i<nl){
			a[k]=l[i];
			i++;
			k++;
		}
		while(j<nr){
			a[k]=r[j];
			j++;
			k++;
		}
	}
}