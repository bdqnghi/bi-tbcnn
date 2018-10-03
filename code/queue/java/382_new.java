package com.tutego.insel.util.queue;

import java.util.*;

public class PriorityQueueDemo
{
  public static void main( String[] args )
  {
    PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
    queue.addAll( Arrays.asList( 9, 2, 3, 1, 3, 8 ) );
    System.out.println( queue );  // [1, 2, 3, 9, 3, 8]
    queue.remove();
    System.out.println( queue );  // [2, 3, 3, 9, 8]
    queue.remove();
    System.out.println( queue );  // [3, 8, 3, 9]
    queue.remove();
    System.out.println( queue );  // [3, 8, 9]
    queue.remove();
    System.out.println( queue );  // [8, 9]
    queue.remove();
    System.out.println( queue );  // [9]
    queue.remove();
    System.out.println( queue );  // []
  }
}