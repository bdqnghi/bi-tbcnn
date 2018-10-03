//Listing 10.6
//********************************************************************
//  HeapTest.java       Author: Lewis/Loftus/Cocking
//
//  Driver for testing a heap.
//********************************************************************

public class HeapTest {
   //-----------------------------------------------------------------
   //  Creates a heap, adds some elements to it, and prints it out.
   //-----------------------------------------------------------------
   public static void main (String[] args) {
      HeapOfCharacters heap = new HeapOfCharacters();

      heap.add('Q');
      System.out.println (heap);
      heap.add('H');
      System.out.println (heap);
      heap.add('N');
      System.out.println (heap);
      heap.add('B');
      System.out.println (heap);
      heap.add('F');
      System.out.println (heap);
      heap.add('W');
      System.out.println (heap);
      heap.add('K');
      System.out.println (heap);
      heap.add('A');
      System.out.println (heap);
   }
}