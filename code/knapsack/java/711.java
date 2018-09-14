package name.xmj.basic;

import java.util.Arrays;

/**
 * 0-1 knapsack
 * @author mingjun
 *
 */
public class Knapsack {
	int [] w;
	int [] v; 
	int n;
	
	Knapsack(int [] w, int [] v) {
		// w.length == v.length == n
		this.w = w;
		this.v = v;
		n = this.w.length;
		
		System.out.println(Arrays.toString(w));
		System.out.println(Arrays.toString(v));
	}

	public int findR(int bagSize) {
		int value = fillR(0, 0, bagSize);
		return value;
	}
	
	public int fillR(int index, int valueInbag, int remainWeight) {
		if(index >= n) {
			return valueInbag;
		}
		
		if(w[index] > remainWeight) {
//			y[index] = 0;
			return fillR(index+1, valueInbag, remainWeight);
		} else {
//			y[index] = 0;
			int v1 = fillR(index+1, valueInbag, remainWeight);
//			y[index] = 1;
			int v2 = fillR(index+1, valueInbag + v[index], remainWeight - w[index]);
			return Math.max(v1, v2);
		}
	}
	
	//TODO can improve with DP: Matrix(n x bagSize)
}
