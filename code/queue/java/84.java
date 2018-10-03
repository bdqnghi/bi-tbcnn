package PrintQueueSimulator;
/**
 * This queue class is the sub class of list
 * @author siqi zhang
 */
public class Queue extends List
{  
    /**
     *  default constructor
     */
    public Queue()
    {
        super( "queue" );
    }
    /**
     * Method: enqueue-
     * method that will insert the object into the queue
     * @param o 
     */
    public synchronized void enqueue( Object o )
    {
        insertAtBack( o );
    }
    /**
     * Method: dequeue-
     * This is the method that will dequeue the first object in the queue and return it
     * @return the dequeued object
     * @throws EmptyListException 
     */
    public synchronized Object dequeue() throws EmptyListException
    {
        return removeFromFront();
    }
    /**
     * Method: isEmpty-
     * This me
     * @return true if the queue is empty;false if its not
     */
    public synchronized boolean isEmpty()
    {
        return super.isEmpty();
    }
    public synchronized void print()
    {
        super.print();
    }
    /**
     * Method: length-
     * This method will return the length of the current queue when it is called
     * @return the length of the queue
     */
    public synchronized int length()
    {
        int size = 0;
        if(isEmpty())
            size = 0;
        else
        {
            ListNode current = firstNode;
            while(current!= null)
            {
                size++;
                current = current.next;
            }
        }
        return size;
    }
}