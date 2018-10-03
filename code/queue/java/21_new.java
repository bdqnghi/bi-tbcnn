package c10.s01.t06;

import static org.junit.Assert.*;

import org.junit.Test;

public class QueueTest {
    Queue<Integer> queue = new Queue<Integer>();

    @Test
    public void test() {
        queue.enQueue(10);
        queue.enQueue(20);
        assertEquals(10, (int) queue.deQueue());

        queue.enQueue(30);
        queue.enQueue(40);

        assertEquals(20, (int) queue.deQueue());
        assertEquals(30, (int) queue.deQueue());
        assertEquals(40, (int) queue.deQueue());
    }

}
