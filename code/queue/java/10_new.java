import org.junit.Test;

import static org.junit.Assert.*;

public class QueueSizeTest {
    @Test
    public void sizezerotest(){
         Queue queue=new MyQueue();
         assertEquals(0,queue.size(),0);
    }
    @Test
    public void sizeonetest(){
        Queue queue=new MyQueue();
        queue.add(5);
        assertEquals(1, queue.size(), 0);
    }
    @Test
    public void twoelementsizetest(){
        Queue queue= new MyQueue();
        queue.add(6);
        queue.add(8);
        assertEquals(2,queue.size(),0);
    }
    @Test
    public void multipleelementsizetest(){
        Queue queue= new MyQueue();
        queue.add(6);
        queue.add(8);
        queue.add(15);
        assertEquals(3,queue.size(),0);
    }
    @Test
    public void removemultipleelementtest(){
        Queue queue= new MyQueue();
        queue.add(6);
        queue.add(8);
        queue.add(15);
        queue.remove();
        queue.remove();
        assertEquals(1,queue.size(),0);
    }
    @Test
    public void removelasttest(){
        Queue queue= new MyQueue();
        queue.add(6);
        queue.remove();
        assertEquals(0,queue.size(),0);
    }
    @Test
    public void removelastcheckemptytest(){
        Queue queue= new MyQueue();
        queue.add(6);
        queue.remove();
        assertTrue(queue.isEmpty());
    }
}
