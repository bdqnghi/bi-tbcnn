package com.aditya.ds.heap.patterns.junit;
import static org.junit.Assert.assertEquals;

import org.junit.Test;

import com.aditya.ds.heap.patterns.heap.Heap;
import com.aditya.ds.heap.patterns.heap.MaxHeap;
import com.aditya.ds.heap.patterns.heap.MinHeap;

public class HeapTest {
	@Test
	public void testDefaultHeap() {
		// a MinHeap is created by default.
		Heap<String> aHeap = new Heap<String>();
		aHeap.add("a");
		aHeap.add("b");
		aHeap.add("c");
		aHeap.add("d");
		aHeap.add("e");
		assertEquals("Default Heap PreOrderTraversal", "a b d c e ",
				aHeap.preOrderTraversal());
	}
	@Test
	public void testMaxHeap() {
		MaxHeap<String> aMaxHeap = new MaxHeap<String>();
		aMaxHeap.add("a");
		aMaxHeap.add("b");
		aMaxHeap.add("c");
		aMaxHeap.add("d");
		aMaxHeap.add("e");
		assertEquals("MaxHeap PreOrderTraversal", "e c a d b ",
				aMaxHeap.preOrderTraversal());
		// Height incremented 1 more than expected height intentionally.
		assertEquals("MaxHeap Height", 4, aMaxHeap.height());
		assertEquals("MaxHeap Size", 5, aMaxHeap.size());
	}
	@Test
	public void testMinHeap() {
		MinHeap<String> aMinHeap = new MinHeap<String>();
		aMinHeap.add("a");
		aMinHeap.add("b");
		aMinHeap.add("c");
		aMinHeap.add("d");
		aMinHeap.add("e");
		assertEquals("MinHeap PreOrderTraversal", "a b d c e ",
				aMinHeap.preOrderTraversal());
		assertEquals("MinHeap Height", 4, aMinHeap.height());
		assertEquals("MinHeap Size", 5, aMinHeap.size());
	}
}
