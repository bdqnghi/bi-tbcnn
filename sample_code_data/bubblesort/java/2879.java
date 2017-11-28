package algorithms.bubblesort;

import java.util.ArrayList;
import java.util.Collections;

import algorithms.IAlgorithm;

public class Bubblesort implements IAlgorithm{

	@Override
	public ArrayList<Integer> sortList(ArrayList<Integer> unsortedList) {
		
		Boolean Changes = true;

		while(Changes){
			Changes = false;
			for(int x = 0; x < unsortedList.size() - 1; x++){
				if(unsortedList.get(x) > unsortedList.get(x+1)){
					Collections.swap(unsortedList, x, x+1);
					Changes = true;
				}
			}
		}
		return unsortedList;
	}

	@Override
	public String returnCode() {
		// TODO Auto-generated method stub
		return null;
	}

}
