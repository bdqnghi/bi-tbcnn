
public class Bubblesort implements SortingAlgorithms{
	String name="BubbleSort";
	@Override
	public int[] sort(int[] data) {
		// TODO Auto-generated method stub
		//loop through entire list
		for (int n=0;n<data.length-1;n++){
			//sub loop through the data as far as the nth unsorted element
			for(int i=0;i<data.length-n-1;i++){
				//if consecutive elements are out of place, swap them
				if(data[i]>data[i+1]){
					int bigger=data[i];
					int smaller=data[i+1];
					data[i]=smaller;
					data[i+1]=bigger;
				}
			}
		}
		return data;
	}
	@Override
	public String name() {
		// TODO Auto-generated method stub
		//return the name variable
		return name;
	}

	@Override
	public void name(String name) {
		// TODO Auto-generated method stub
		//set the name variable
		this.name=name;
	}
	

}
