package is.a.amoneysharinggui;

public class Quicksort {
	public static void sort(int n,Individual a[],Individual pos[],Individual neg[],Transaction tr[], int npos1[], int nneg1[], int numtr1[]){
		
		int beg,end;
		System.out.printf("------- PERFORMING QUICK SORT ---\n\n");
		beg=0;
		end=n-1;
		quick_srt(a,beg,end);                        	  //Calling of QuickSort Function

		int npos=0,nneg=0;
		for(int i=0;i<n;i++)
		{
			if(a[i].amt>0)
			{
				pos[npos] = new Individual();
				pos[npos].nperson = a[i].nperson;
				pos[npos++].amt = a[i].amt;
			}
			else if(a[i].amt<0)
			{
				neg[nneg] = new Individual();
				neg[nneg].nperson = a[i].nperson;
				neg[nneg++].amt = -a[i].amt;
			}

		}

		System.out.printf("\nAfter Sorting \nNumber of Individuals : %d\n", n);
		for(int i=0;i<n;i++)
		{
			System.out.printf("%d  %f", a[i].nperson, a[i].amt);
			System.out.println();
		}
		System.out.printf("\nNumber of Giving Individuals : %d\n", npos);
		for(int i=0;i<npos;i++)
		{
			System.out.printf("%d  %f", pos[i].nperson, pos[i].amt);
			System.out.println();
		}
		System.out.printf("\nNumber of Receiving Individuals : %d\n", nneg);
		for(int i=0;i<nneg;i++)
		{
			System.out.printf("%d  %f", neg[i].nperson, neg[i].amt);
			System.out.println();
		}

		int numtr = dotrans(pos,neg,tr,npos,nneg);
		System.out.printf("\nNumber of Transactions : %d\n", numtr);
		System.out.printf("GIVE TAKE AMOUNT\n");
		for(int i=0;i<numtr;i++)
		{
			System.out.printf("%d     %d    %f", tr[i].pgiv, tr[i].ptke, tr[i].amt);
			System.out.println();        
		}
		npos1[0] = npos;
		nneg1[0] = nneg;
		numtr1[0] = numtr;
	}	

	public static void quick_srt(Individual a[],int beg, int end){
		if(beg<end)
		{
			int p=Partition(a,beg,end);                      //Calling Procedure to Find Pivot
			quick_srt(a,beg,p-1);                             //Calls Itself (Recursion)
			quick_srt(a,p+1,end);	              //Calls Itself (Recursion)
		}


	}

	public static int Partition(Individual a[], int beg, int end){
		int p=beg, loc;
		Individual pivot=a[beg];
		for(loc=beg+1;loc<=end;loc++)
		{
			if(pivot.amt > a[loc].amt)
			{
				a[p]=a[loc];
				a[loc]=a[p+1];
				a[p+1]=pivot;
				p=p+1;
			}
		}
		return p;	
	}

	public static int dotrans(Individual pos[], Individual neg[], Transaction tr[], int npos, int nneg)
	{
		if(neg[0] == null)
		{
			return 0;
		}
		int posp = 0, negp = 0, ntran = 0;
		float agiv=0,atke=0; 
		atke= neg[negp].amt;
		agiv = pos[posp].amt;
		for(;posp<npos&&negp<nneg;)
		{
			if(agiv<=atke)
			{
				tr[ntran] = new Transaction(); 
				tr[ntran].amt = agiv;
				tr[ntran].pgiv = pos[posp].nperson;
				tr[ntran++].ptke = neg[negp].nperson;
				atke = atke - agiv;
				posp = posp+1;
				if(posp<npos)
					agiv = pos[posp].amt;                 
				if(atke == 0)
				{
					negp = negp +1;
					if(negp<nneg)
						atke= neg[negp].amt;
				}
			}
			else
			{
				tr[ntran] = new Transaction();
				tr[ntran].amt = atke;
				tr[ntran].pgiv = pos[posp].nperson;
				tr[ntran++].ptke = neg[negp].nperson;
				agiv = agiv - atke;
				negp = negp + 1;
				if(negp<nneg)
					atke= neg[negp].amt;    
			}    
		}
		return ntran;    
	}


}