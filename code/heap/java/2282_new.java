
package quiz9.heap;

import static org.junit.Assert.*;

import org.junit.Test;

public class TestMinHeap {

	@Test
	public void test0() {
		MinHeap heap = new MinHeap();
		assertEquals(heap.size, 0);
	}

	@Test
	public void test1() {
		MinHeap heap = new MinHeap();
		heap.add(9);
		assertEquals(heap.size, 1);
		assertEquals(heap.queue[0], 9);
	}

	@Test
	public void test2() {
		MinHeap heap = new MinHeap();
		heap.add(9);
		heap.add(5);
		assertEquals(heap.size, 2);
		assertEquals(heap.queue[0], 5);
		assertEquals(heap.queue[1], 9);
	}

	@Test
	public void test3() {
		MinHeap heap = new MinHeap();
		heap.add(9);
		heap.add(5);
		heap.add(8);
		assertEquals(heap.size, 3);
		assertEquals(heap.queue[0], 5);
		assertEquals(heap.queue[1], 9);
		assertEquals(heap.queue[2], 8);
	}

	@Test
	public void test4() {
		MinHeap heap = new MinHeap();
		heap.add(9);
		heap.add(5);
		heap.add(8);
		heap.add(3);
		assertEquals(heap.size, 4);
		assertEquals(heap.queue[0], 3);
		assertEquals(heap.queue[1], 5);
		assertEquals(heap.queue[2], 8);
		assertEquals(heap.queue[3], 9);
	}

	@Test
	public void test5() {
		MinHeap heap = new MinHeap();
		heap.add(9);
		heap.add(5);
		heap.add(8);
		heap.add(3);
		heap.add(1);
		assertEquals(heap.size, 5);
		assertEquals(heap.queue[0], 1);
		assertEquals(heap.queue[1], 3);
		assertEquals(heap.queue[2], 8);
		assertEquals(heap.queue[3], 9);
		assertEquals(heap.queue[4], 5);
	}

	@Test
	public void test6() {
		MinHeap heap = new MinHeap();
		heap.add(9);
		heap.add(5);
		heap.add(8);
		heap.add(3);
		heap.add(1);
		heap.add(6);
		assertEquals(heap.size, 6);
		assertEquals(heap.queue[0], 1);
		assertEquals(heap.queue[1], 3);
		assertEquals(heap.queue[2], 6);
		assertEquals(heap.queue[3], 9);
		assertEquals(heap.queue[4], 5);
		assertEquals(heap.queue[5], 8);
	}
}
