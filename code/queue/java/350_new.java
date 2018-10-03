/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;
import queue.*;
/**
 *
 * @author jarvis
 */
public class Test {
    public static void main(String[] args){
    
        MyQueue queue=new MyQueue();
        

        queue.enqueue(12);
        queue.enqueue(13);
        queue.enqueue(11);queue.enqueue(11);queue.enqueue(11);queue.enqueue(11);queue.enqueue(11);queue.enqueue(11);queue.enqueue(11);queue.enqueue(11);
        queue.printQueue();
        queue.dequeue();
        queue.enqueue(14);
        queue.dequeue();queue.dequeue();queue.dequeue();queue.dequeue();queue.dequeue();queue.dequeue();
        queue.enqueue(99);queue.dequeue();
        queue.printQueue();
    }
    
}