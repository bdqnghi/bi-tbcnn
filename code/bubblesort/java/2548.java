package bubblesort;

import java.util.ArrayList;

public class Bubblesort {
	private static int[] Input = new int[20];
	
	public static void main(String[] args) {
		new Bubblesort();
	}

	public Bubblesort() {
		super();
		for(int i = 0; i<20; i++) {
			Input[i] = (int) (Math.random()*100);
		}
		
		
		
		int k = 0;
		int temp;
		for(int i = Input.length; i>0;i--) {
			for(k=0; k<i-1; k++) {
				if(Input[k]<Input[k+1]) {
					temp = Input[k+1];
					Input[k+1] = Input[k];
					Input[k] = temp;	
				}
			}
		}
		
		for(int i = 0; i< Input.length; i++) {
			System.out.println(Input[i]);
		}
	}
	
	
}
