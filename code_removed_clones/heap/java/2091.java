/*
 *  Copyright 2006-2007 Columbia University.
 *
 *  This file is part of MEAPsoft.
 *
 *  MEAPsoft is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  MEAPsoft is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with MEAPsoft; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 *  02110-1301 USA
 *
 *  See the file "COPYING" for the text of the license.
 */
package EvacSim.jme3tools.navmesh.util;

import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.Vector;

/**
 * Abstract implementation of the basic functions needed for a binary
 * heap using java.util.Vector as a back end.  
 *
 * Unlike java.util.TreeSet, this data structure can handle duplicate
 * entries.  The implementations of the methods given here implement a
 * MinHeap.  It is abstract so that we can have a MinHeap class that
 * supports deleteMin() and a MaxHeap class that supports deleteMax()
 * but neither of them support both.
 *
 * @param <T> 
 * @author Ron Weiss (ronw@ee.columbia.edu)
 */
public abstract class Heap<T> extends Vector<T> {
    // Comparator to use to compare two elements in this Heap (if this
    // is null, assume that all elements are Comparable)

    private Comparator<T> comp = null;
    // Does the current instance obey the heap property?
    // (all operations aside from sort() are guaranteed to maintain
    // the heap property, this is just to keep track of whether or not
    // sort() has screwed stuff up).
    /**
     *
     */
    protected boolean isHeap = true;

    /**
     * Creates an empty Heap.
     */
    public Heap() {
        super();
    }

    /**
     *  Use given Comparator for all comparisons between elements in
     *  this Heap.  Otherwise rely on compareTo methods and Comparable
     *  Objects.
     * @param c 
     */
    public Heap(Comparator<T> c) {
        super();
        comp = c;
    }

    /**
     * Creates an empty Heap with the given capacity.
     * @param capacity 
     */
    public Heap(int capacity) {
        super(capacity);
    }

    /**
     * Create a new Heap containing the elements of the given
     * Collection.
     * @param c 
     */
    public Heap(Collection<T> c) {
        super();
        addAll(c);
    }

    /**
     * Remove the Object at the given index from the Heap
     * @param index 
     * @return 
     */
    @Override
    public T remove(int index) {
        if (!isHeap) {
            rebuildHeap();
        }

        T o = get(index);

        set(index, get(size() - 1));
        removeElementAt(size() - 1);

        heapify(index);

        return o;
    }

    /**
     * Remove the Object o from the Heap and return true.  Returns
     * false if o is not in the Heap (as measured by o.equals()).
     * @param o 
     * @return 
     */
    @Override
    public boolean remove(Object o) {
        boolean found = false;
        for (int i = 0; i < size(); i++) {
            if (o == null ? get(i) == null : o.equals(get(i))) {
                found = true;
                remove(i);

                break;
            }
        }

        return found;
    }

    /**
     * Add o to the Heap.
     * @param o
     * @return  
     */
    @Override
    public boolean add(T o) {
        if (!isHeap) {
            rebuildHeap();
        }

        boolean b = super.add(o);

        for (int node = size() - 1; node > 0;) {
            int cmp;
            int parent = (int) ((node - 1) / 2);

            if (cmp(node, parent) < 0) {
                // swap them and reheapify
                T tmp = get(node);
                set(node, get(parent));
                set(parent, tmp);
            }

            node = parent;
        }

        //System.out.print("\nContents: ");
        //for(int x = 0; x < size(); x++)
        //    System.out.print(get(x) + " ");
        //System.out.println();

        return b;
    }

    /**
     *  Add the contents of a Collection to the Heap.
     * @param c
     * @return  
     */
    @Override
    public boolean addAll(Collection c) {
        boolean b = super.addAll(c);
        rebuildHeap();
        return (b);
    }

    /**
     * Ensure that every element in this heap obeys the heap property.
     * Runs in linear time.  
     *
     * This is meant to be called if/when the Comparator associated
     * with this object is modified.
     */
    public void rebuildHeap() {
        // do the whole linear time build-heap thing
        for (int i = (int) (size() / 2); i >= 0; i--) {
            heapify(i);
        }

        isHeap = true;
    }

    /**
     * Perform an in place heap sort on the data stored in this heap.
     * After calling sort, a call to this objects iterator() method
     * will iterate through the data stored in the heap in ascending
     * sorted order.  This is not a stable sort.
     */
    public void sort() {
        Object[] a = toArray();
        if (comp == null) {
            Arrays.sort(a);
        } else {
            Arrays.sort((T[])a, comp);
        }

        elementData = a;

        // there is some wierdo off by one error here that I cannot find...
        //for(int x = size()-1; x > 0; x--)
        //{
        //    // swap end of heap with the root, then heapify whats
        //    // left.
        //    Object tmp = get(x);
        //    set(x, get(0));
        //    set(0, tmp);
        //
        //    heapify(0, x);
        //}           

        // the above code destroys the heap property - the array is
        // essentially in reverse sorted order (with respect to the
        // first element in the heap (min if MinHeap, max if MaxHeap))
        //
        // The next call to one of the Heap methods will rebuild the
        // heap.
        isHeap = false;
    }

    /**
     * Compare two Objects in this heap - wrapper around
     * compareTo/Comparator.compare.
     * @param node1
     * @param node2 
     * @return  
     */
    protected int cmp(int node1, int node2) {
        int c = 0;
        if (comp != null) {
            c = comp.compare(get(node1), get(node2));
        } else {
            c = ((Comparable<T>) get(node1)).compareTo(get(node2));
        }

        return c;
    }

    /**
     * Ensure that the subtree of the given size rooted at node obeys
     * the heap property
     */
    private void heapify(int node, int size) {
        if (node > size) {
            return;
        }

        int left = (node + 1) * 2 - 1;
        int right = (node + 1) * 2;

        int minidx = node;

        if (left < size && cmp(left, node) <= 0) {
            minidx = left;
        }
        if (right < size && cmp(right, node) <= 0 && cmp(right, left) <= 0) {
            minidx = right;
        }

        if (minidx != node) {
            // swap them and recurse on the subtree rooted at minidx
            T tmp = get(node);
            set(node, get(minidx));
            set(minidx, tmp);

            heapify(minidx, size);
        }
    }

    /**
     * Ensure that the subtree rooted at node obeys the heap property
     */
    private void heapify(int node) {
        heapify(node, size());
    }

    /**
     * Do the contents of this object currently obey the heap
     * property?
     * @return 
     */
    public boolean isHeap() {
        return isHeap;
    }
}
