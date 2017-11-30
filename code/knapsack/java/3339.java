/**
 *	name	  : Ravi Shwetha
 *	matric no.: A0146130W
 */

import java.util.*;

class Result {
	private int[] store;
	private int items;
	private int cap;

	public Result(int[] store, int N, int K) {
		this.store = new int[N];
		this.store = store;

		this.items = N;
		this.cap = K;
	}

	/** 
	 *	solve			: to count the number of sets of items satisfying the criteria.
	 * 		  			  (the total weight of all items in a set should not exceed the capacity of the sack)
	 * 	Pre-condition  	: cap is not negative nor is items
	 * 	Post-condition 	: answer is always a whole number: 0, 1, 2, 3...
	 */

	public int solve(int currWt, int itemID) {
		if(currWt == cap) {
			return 1;
		}
		else if(currWt > cap) {
			return 0;
		}
		else if(itemID == items-1) {
			return 1;
		}
		else {
			return solve(currWt, itemID+1) + solve(currWt + store[itemID+1], itemID+1);
		}
	}
}

class Knapsack {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// read input
		int N = sc.nextInt();
		int K = sc.nextInt();
		sc.nextLine();
		int[] store = new int[N];

		for(int i=0; i<N; i++) {
			store[i] = sc.nextInt();
		}
		sc.nextLine();

		Result question = new Result(store, N, K);
		System.out.println(question.solve(0, -1));
	}
}
