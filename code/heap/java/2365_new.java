package com.aditya.ds.heap.patterns;

import java.util.Iterator;

import com.aditya.ds.heap.patterns.heap.Heap;

public class LaunchHeap {

	public static void main(String[] args) {

		Heap<String> aHeap = new Heap<String>();
		aHeap.add("a");
		aHeap.add("b");
		aHeap.add("c");
		aHeap.add("d");
		aHeap.add("e");
		Iterator<String> i = aHeap.iterator();
		String inOrderTraversal = "";
		while (i.hasNext()) {
			inOrderTraversal = inOrderTraversal + i.next() + " ";
		}
		System.out.println(inOrderTraversal);
		// MaxHeap<String> aMinHeap = new MaxHeap<String>();
		// aMinHeap.add("a");
		// aMinHeap.add("b");
		// aMinHeap.add("c");
		// aMinHeap.add("d");
		// aMinHeap.add("e");
		// System.out.println(aMinHeap.preOrderTraversal());

		// Heap<String> aHeap = new Heap<String>(new MaxHeap<String>());
		// aHeap.add("aing");
		// aHeap.add("b");
		// aHeap.add("cing");
		// aHeap.add("d");
		// aHeap.add("e");
		// System.out.println(aHeap.toString());
		
		

		// HeapFactory<String> aHeapFactory = new MinHeap<String>();
		// aHeapFactory = new IngHeapDecorator<String>(aHeapFactory);
		// aHeapFactory.add("aing");
		// aHeapFactory.add("bing");
		// aHeapFactory.add("c");
		// aHeapFactory.add("d");
		// aHeapFactory.add("e");
		// aHeapFactory.add("fing");
		// aHeapFactory.add("g");
		// aHeapFactory.add("hing");
		// System.out.println(aHeapFactory.preOrderTraversal());
		// System.out.println(aHeapFactory.toString());

		//
		// System.out.println(aHeapFactory.toArray().length);
		// for (int i = 0; i < aHeapFactory.toArray().length; i++) {
		// System.out.println(aHeapFactory.toArray()[i]);
		// }

		// System.out.println(aHeapFactory.preOrderTraversal());
		// System.out.println(aHeapFactory.toString());

		// Heap<String> aHeap = new Heap<String>(new MinHeap<String>());
		// aHeap.add("1");
		// aHeap.add("2");
		// aHeap.add("3");
		// aHeap.add("4");
		// aHeap.add("5");
		// aHeap.add("6");
		// aHeap.add("7");
		// aHeap.add("8");
		// Iterator<String> i = aHeap.iterator();
		// while (i.hasNext()) {
		// System.out.println(i.next());
		// }
		
		// int len = aHeap.toArray().length;
		// System.out.println(len);
		// for (int j = 0; j < len; j++) {
		// System.out.println(aHeap.toArray()[j]);
		// }
	}
}
