/**
 *	name	  : Wong Kang Fei
 *	matric no.:	A0138862W
 */

import java.util.*;

class Result {
    // declare the member field
	private int[] itemWeights;
	private int capacity;

    // declare the constructor
	public Result(int[] itemWeights, int capacity){
		this.itemWeights = itemWeights;
		this.capacity = capacity;
	}

	/** 
	 *	solve			: to count the number of sets of items satisfying the criteria.
	 * 		  			  (the total weight of all items in a set should not exceed the capacity of the sack)
	 * 	Pre-condition  	:
	 * 	Post-condition 	:
	 */	
	// you should determine the recurrence state(parameters) yourself.
	//
	public int solve(){
		return solve(0, 0) + 1; // empty sack always present;
	}

	public int solve(int total, int index) {
		// implementation
		// compute the next weight
		//
		// if greater than capcity
		// return 0;
		// if equal or less than capacity
		// return recursive + 1;
		
		// empty sack
		if(index >= itemWeights.length){
			return 0;
		}

		int totalChosen = total + itemWeights[index];
		int totalNotChosen = total;

	
		if(totalChosen > capacity){
			return solve(totalNotChosen, index+1);
		}else{
			return solve(totalChosen, index+1) + solve(totalNotChosen, index+1) + 1;
		}
	}
}

class Knapsack {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// declare the necessary variables
		int itemCount = sc.nextInt();
		int capacity = sc.nextInt();

		int[] itemWeights = new int[itemCount];

		// read input and process them accordingly
		for( int i = 0; i<itemCount; i++){
			itemWeights[i] = sc.nextInt();
		}

		Result result = new Result(itemWeights, capacity);
		System.out.println(result.solve());
	}
}
