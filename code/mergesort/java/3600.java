import java.util.Arrays;

public class mergesort{
    int [] array;
    
    public mergesort(int [] x){
	array=x;
    }

    /*
    public void merge(int[]data, int starta, int enda,int startb, int endb){
	System.out.println(starta);
	System.out.println(enda);
	System.out.println(startb);
	System.out.println(endb);
	int counta=0;
	int countb=0;
	int [] temp;
	int mid=starta + (startb-starta)/2;
	temp= new int [endb-starta+1];
	if (2 == endb-starta+1){
	    if (data[0]>data[1]){
		temp[0]=data[1];
		temp[1]=data[0];
	    }
	    else{
		temp[0]=data[0];
		temp[1]=data[1];
	    }
	}
	else{
	    while (counta+starta < enda && startb+countb < endb){
		if (data[starta+counta]<data[startb+countb]){
		    temp[counta+countb]=data[starta+counta];
		    counta++;
		    //System.out.println("counta");
		    //System.out.println(counta);
		}
		if(data[startb+countb]<data[starta+counta]){
		    temp[counta+countb]=data[startb+countb];
		    countb++;
		    //System.out.println("countb");
		    //System.out.println(countb);
		}
		if(data[startb+countb]==data[starta+counta]){
		    temp[counta+countb]=data[starta+counta];
		    counta++;
		    //System.out.println("counta");
		    //System.out.println(counta);
		    temp[counta+countb]=data[startb+countb];
		    countb++;
		    //System.out.println("countb");
		    //System.out.println(countb);
		}
	    }
	    if (counta+starta>enda){
		while(countb+startb < endb){
		    temp[counta+countb]= data[startb+countb];
		    countb++;
		    //System.out.println("countb"); 
		    //System.out.println(countb);

		}
	    }
	    if (countb+startb>endb){
		while(counta+starta <= enda){
		    temp[counta+countb]= data[starta+counta];
		    counta++;
		    //System.out.println("countba");
		    //System.out.println(counta);
		}
	    }
	}
	for (int x=0;x<temp.length;x++){
	    data[starta+x]=temp[x];
	}
	System.out.println(Arrays.toString(array));
    }
    */

    public void merge(int[]data, start, end){
	int[]temp=data[data.length];
	int mid = start+ (end-start)/2;
	int leftpos=mid;
	int rightpos=end;
	while (rightpos+leftpos < end){
	    if (data[leftpos]<data[rightpos]){
		temp
	    }
	}
    }

    public void sort(int [] data){
	sortH(data,0,data.length-1);
    }

    public void sortH(int[]data,int start, int end){
	if (data.length==1){
	    return;
	}
	if (start<end){
	    int mid= start + (end-start)/2;
	    sortH(data,start,mid);
	    sortH(data,mid+1,end);
	    merge(data,start,mid,mid+1,end);
	}
    }

    public int[] leftHalf(int [] ary){
	int length = ary.length/2;
	int [] temp= new int [length];
	for (int x=0; x<length;x++){
	    temp[x]=ary[x];
	}
	return temp;
    }

    public int[] rightHalf(int[]ary){
	int length= ary.length - (ary.length/2);
	int []temp= new int[length];
	for (int x=0; x<length;x++){
	    temp[x]= ary[(ary.length/2)+x];
	}
	return temp;
    }

    

    public static void main (String [] args){
	int[]x= {1,7,2,3,9,5,4,13};
	mergesort test=  new mergesort(x);
	test.sort(test.array);
	//test.merge(test.array,0,3,4,7);
	System.out.println(Arrays.toString(test.array));
    }
}
