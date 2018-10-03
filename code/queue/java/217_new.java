// Gokhan Arik
//
// Queue Implementation

public class QueueTest{

    public static void main(String args[]){
       
       System.out.println("Creating new Stack");
       Queue<String> testQueue = new Queue<String>();
       
       System.out.println("Adding element to Stack");
       testQueue.queue("Gokhan");
       testQueue.print();
       testQueue.queue("Arik");
       testQueue.print();
       testQueue.queue("asd");
       testQueue.print();
       testQueue.queue("sss");
       testQueue.print();
       testQueue.queue("as");
       testQueue.print();
       testQueue.queue("ds");
       testQueue.print();
       
       System.out.println("Popping element from the Stack");
       testQueue.dequeue();
       testQueue.print();
       testQueue.dequeue();
       testQueue.print();
       testQueue.dequeue();
       testQueue.print();
       testQueue.dequeue();
       testQueue.print();
    }
}
