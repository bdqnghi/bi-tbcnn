package com.sillycat.easyalgorithm.sort;

import java.util.List;
import java.util.Vector;

public class Bubblesort implements Sorter {

	@Override
	public void sort(List<Integer> list) {
		if (list.isEmpty()) {
			System.out.println("Vector can not be null!");
			return;
		}
		Integer bak;
		boolean flag = true;
		while (flag) {
			flag = false;
			for (int i = 0; i < list.size() - 1; i++) {
				System.out.println("counting ....");
				bak = list.get(i);
				if (bak > list.get(i + 1)) {
					flag = true;
					list.set(i, list.get(i + 1));
					list.set(i + 1, bak);
				}
			}
		}
	}

	public static void main(String[] args) {
		Vector<Integer> v1 = new Vector<Integer>();
		v1.add(1);
		v1.add(9);
		v1.add(3);
		v1.add(11);
		v1.add(6);
		System.out.println(v1);
		Bubblesort sort1 = new Bubblesort();
		sort1.sort(v1);
		System.out.println(v1);
	}

}
