package homework3;

public class mergesort {
	public static long[] array2;
	void init(long[] array)
	{
		array2=array;
		msort(0,array2.length-1);
	}
	void msort(int left,int right)
	{
		if(right>left&&right-left<50)//�Ż�
		{
			long t[]=null;
			long tt[]=new long[right-left+1];
			Insertion tmp=new Insertion();
			for(int i=0;i<right-left+1;i++)
				tt[i]=array2[i+left];
			t=tmp.sort(tt);
			for(int i=0;i<right-left+1;i++)
				array2[left+i]=t[i];
		}
		if(left<right)
		{
		int medium=(left+right)/2;
		msort(left,medium);
		msort(medium+1,right);
		merge(left,medium,right);
		}
	}
	void merge(int left,int medium,int right)
	{
		if(array2[medium]<=array2[medium+1])
			return;
		int index=left;
		long sum=4294967296L;
		long t1[]=new long[medium-left+2];
		long t2[]=new long[right-medium+1];
		for(int i=0;i<=medium-left;i++)
		{
			t1[i]=array2[left+i];
		}
		t1[medium-left+1]=sum;
		for(int i=0;i<right-medium;i++)
		{
			t2[i]=array2[medium+1+i];
		}
		t2[right-medium]=sum;
		for (int i=0,j=0,k=0; k<(right-left+1);){
            if (t1[i] < t2[j]){
                array2[left+k] = t1[i++];
                k++;
            }
            else{
                array2[left+k] = t2[j++];
                k++;
            }
        }
	}
}
