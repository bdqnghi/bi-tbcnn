
public class Quicksort implements Runnable{
	int[] arr;
	int low;
	int high;
	
	public Quicksort(int[] arr,int low,int high) {
		// TODO Auto-generated constructor stub
		this.arr = arr;
		this.low= low;
		this.high = high;
	}
	
	void QS() throws InterruptedException{
		if(low<high){
			int p = partition();
			Quicksort obj1=new Quicksort(arr,low,p);
			Thread t1=new Thread(obj1);
			t1.start();
			
			
			Quicksort obj2=new Quicksort(arr,p+1,high);
			Thread t2=new Thread(obj2);
			t2.start();
			
			t1.join();
			t2.join();
		}
	}
	
	int partition(){
		int pivot = arr[low];
		int i = low-1;
		int j = high+1;
		
		while(true){
			do{
				i = i+1;
			}while(arr[i]<pivot);
			
			do{
				j = j-1;
			}while(arr[j]>pivot);
			
			if(i>=j){
				return j;
			}
			
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			QS();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
	}

}
