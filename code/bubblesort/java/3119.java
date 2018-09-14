class Bubblesort {

	int arr[];
	int elem;
	
	Bubblesort(int e)
	{
		int i = 0;
		arr = new int[e];
		elem = e;
		for(i = 0; i < e; i++) {
			arr[i] = int.random;
		}
	}
	
	sort() :Void
	{
  		int top = elem - 1;
  		while(top > 0) {
    		int i = 0;
			while(i < top) {
	  			if(arr[i] > arr[i + 1]) {
					int t = arr[i];
	      			arr[i] = arr[i + 1];
		  			arr[i + 1] = t;
				}
	  			i = i + 1;
			}
			top = top - 1;
  		}
	}

  public static void main(String argv[])
  {
    int i, loops = (new Integer(argv[0])).intValue();

    for(; loops > 0; loops--) {
      Bubblesort bs = new Bubblesort(1000);
	  bs.sort();
    }
  }
}