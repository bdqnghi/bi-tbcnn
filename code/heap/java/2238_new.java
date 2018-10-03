package com.aditya.dataStructures.minHeap;

public class LaunchMinHeap {

	public static void main( String[] args ) {
		MinHeap aMinHeap = new MinHeap();
		aMinHeap.add( "a" );
		aMinHeap.add( "b" );
		aMinHeap.add( "cing" );
		aMinHeap.add( "d" );
		aMinHeap.add( "eing" );
		aMinHeap.add( "f" );
		aMinHeap.add( "g" );
		aMinHeap.add( "h" );
		aMinHeap.add( "i" );
		aMinHeap.add( "j" );
		aMinHeap.add( "k" );
		aMinHeap.add( "l" );
		aMinHeap.add( "m" );
		aMinHeap.add( "n" );
		aMinHeap.add("a");
		aMinHeap.add("b");
		aMinHeap.add("cing");
		aMinHeap.add("d");
		aMinHeap.add("eing");
		aMinHeap.add("f");
		aMinHeap.add("g");
		aMinHeap.add("h");
		aMinHeap.add("i");
		aMinHeap.add("j");
		aMinHeap.add("k");
		aMinHeap.add("l");
		aMinHeap.add("m");
		aMinHeap.add("n");
		
		
		System.out.println( aMinHeap.preOrderTraversal() );
		System.out.println( aMinHeap.ingEndingPreOrderTraversal() );
	}
}
