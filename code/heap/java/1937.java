/*
 * Heap.java
 *
 * Computer Science E-119, Harvard University
 */

import java.util.*;

/**
 * Heap - a class that implements a max-at-top heap using an array.
 */
public class Heap<T extends Comparable<T>> {
    private T[] contents;
    private int numItems;

    public Heap(int maxSize) {
	contents = (T[])new Comparable[maxSize];
	numItems = 0;
    }

    public Heap(T[] arr) {
	// Note that we don't copy the array, so that heapsort can
	// sort the array in place.
	contents = arr;
	numItems = arr.length;
	makeHeap();
    }

    /* 
     * makeHeap - turn the elements in the contents array into a
     * representation of a max-at-top heap.
     */
    private void makeHeap() {
	int last = contents.length - 1;
	int parentOfLast = (last - 1)/2;
	for (int i = parentOfLast; i >= 0; i--)
	    siftDown(i);
    }

    /** 
     * insert - add the specified item to the heap and sift it up
     * into its proper position.
     */
    public void insert(T item) {
	if (numItems == contents.length) {
	    // grow the array
	    T[] newContents = (T[])new Comparable[contents.length * 4];
	    System.arraycopy(contents, 0, newContents, 0, numItems);
	    contents = newContents;
	}

	contents[numItems] = item;
	siftUp(numItems);
	numItems++;
    }

    /**
     * remove and return the item at the top of the heap, and adjust
     * the remaining items so that we still have a heap.
     */
    public T remove() {
	T toRemove = contents[0];

	// Move the element currently the end of the heap to the top
	// and sift it into place.
	contents[0] = contents[numItems - 1];
	numItems--;
	siftDown(0);

	return toRemove;
    }

    /**
     * isEmpty - does the heap currently have no items?
     */
    public boolean isEmpty() {
	return (numItems == 0);
    }

    /**
     * toString - create a string representation of the heap of the form
     * { ( root ) ( items in level 1 ) ( items in level 2 ) ... }
     */
    public String toString() {
	String str = "{ ";
	
	int start = 0;
	int levelSize = 1;
	while (start < numItems) {
	    // print all of the items at the current level of the tree
	    str += "( ";
	    for (int i = start; i < start + levelSize && i < numItems; i++)
		str += (contents[i] + " ");
	    str += ") ";

	    // move down to the next level
	    start += levelSize;
	    levelSize *= 2;
	}

	str += "}";
	return str;
    }

    /*
     * siftDown - sift the element in contents[i] down into its
     * correct position in the heap.
     */
    private void siftDown(int i) {
	// Store a reference to the element being sifted.
	T toSift = contents[i];

	// Find where the sifted element belongs.
	int parent = i;
	int child = 2 * parent + 1;
	while (child < numItems) {
	    // If the right child is bigger, compare with it.
	    if (child < numItems - 1  &&
		contents[child].compareTo(contents[child + 1]) < 0)
		    child = child + 1;

	    // Check if we're done.
	    if (toSift.compareTo(contents[child]) >= 0)
		break;

	    // If not, move child up and move down one level in the tree.
	    contents[parent] = contents[child];
	    parent = child;
	    child = 2 * parent + 1;
	}

	contents[parent] = toSift;
    }

    /*
     * siftUp - sift the element in contents[i] up into its
     * correct position in the heap.
     */
    private void siftUp(int i) {
	// Store a reference to the element being sifted.
	T toSift = contents[i];

	// Find where the sifted element belongs.
	int child = i;
	while (child > 0) {
	    int parent = (child - 1)/2;

	    // Check if we're done.
	    if (toSift.compareTo(contents[parent]) <= 0)
		break;

	    // If not, move parent down and move up one level in the tree.
	    contents[child] = contents[parent];
	    child = parent;
	}

	contents[child] = toSift;
    }

    public static void main(String[] args) {
	String commandString = "";
	Scanner in = new Scanner(System.in);

	System.out.print("max size: ");
	int maxSize = in.nextInt();
	in.nextLine();    // consume the rest of the line
	Heap<Integer> heap = new Heap<Integer>(maxSize);

	while(true) {
	    System.out.println(heap);
	    System.out.println();

	    do {
		System.out.print("[Insert int | Remove | Quit] : ");
		commandString = in.nextLine();
	    } while (commandString.length() == 0);	
		
	    Scanner command = new Scanner(commandString);
	    String commandChar = command.next();
	    
	    try {
		if (commandChar.equalsIgnoreCase("q"))
		    System.exit(1);
		else if (commandChar.equalsIgnoreCase("i")) {
		    // insert
		    int item = command.nextInt();
		    heap.insert(item);
		} else if (commandChar.equalsIgnoreCase("r")) {
		    // remove (and isEmpty)
		    if (heap.isEmpty())
			System.out.println("Heap is empty.");
		    else 
			System.out.println("Removed: " + heap.remove());
		} else
		    System.out.println("Invalid command: " + commandString);
	    } catch (NoSuchElementException e) {
		System.out.println("Invalid command: " + commandString);
	    }
	}
    }
}
