package pt.davidcunha.stacksqueues;

import static org.junit.Assert.*;
import org.junit.Test;
import pt.davidcunha.stacksqueues.queue.QueueImpl;

/**
 * Unit test for Queue Implementation
 */
public class QueueTest {

    @Test(expected = IllegalStateException.class)
    public void setupCircularFalse() {
        QueueImpl queue = new QueueImpl(5, false);
        assertTrue(queue.isEmpty());
        queue.insert(20);
        queue.insert(30);
        queue.insert(40);
        assertFalse(queue.isFull());
        queue.insert(50);
        queue.insert(60);
        assertTrue(queue.isFull());
        assertEquals(20, queue.peek());
        queue.insert(70);
    }

    @Test
    public void setupCircularTrue() {
        QueueImpl queue = new QueueImpl(5, true);
        assertTrue(queue.isEmpty());
        queue.insert(20);
        queue.insert(30);
        queue.insert(40);
        assertFalse(queue.isFull());
        queue.insert(50);
        queue.insert(60);
        assertTrue(queue.isFull());
        assertEquals(20, queue.peek());
        queue.insert(70);
        assertEquals(30, queue.peek());
        queue.insert(80);
        assertEquals(40, queue.peek());
        queue.insert(90);
        assertEquals(50, queue.peek());
        queue.insert(100);
        assertEquals(60, queue.peek());
        queue.insert(110);
        assertEquals(70, queue.peek());
        queue.insert(120);
        assertEquals(80, queue.peek());
        queue.insert(130);
        assertEquals(90, queue.peek());
        queue.remove();
        assertEquals(100, queue.peek());
        queue.remove();
        assertEquals(110, queue.peek());
        queue.insert(140);
        assertEquals(110, queue.peek());
        queue.insert(150);
        assertEquals(110, queue.peek());
        queue.insert(160);
        assertEquals(120, queue.peek());
        queue.insert(170);
        assertEquals(130, queue.peek());
        queue.remove();
        queue.remove();
        queue.remove();
        assertEquals(160, queue.peek());
    }
}
