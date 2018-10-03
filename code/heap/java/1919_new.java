
package quiz9.heap;

import static org.junit.Assert.*;

import org.junit.Test;

public class TestMinHeap {

	@Test
	public void test1() {
		MinHeap heap = new MinHeap(new int[] { 0, 1, 3, 6, 9, 5, 8 });
		heap.remove(1);
		assertArrayEquals(heap.queue, new int[] { 0, 3, 5, 6, 9, 8, 0 });
	}

	@Test
	public void test2() {
		MinHeap heap = new MinHeap(new int[] { 0, 1, 3, 6, 9, 5, 8 });
		heap.remove(5);
		assertArrayEquals(heap.queue, new int[] { 0, 1, 3, 6, 9, 8, 0 });
	}

	@Test
	public void test3() {
		MinHeap heap = new MinHeap(new int[] { 0, 1, 3, 6, 9, 5, 8 });
		heap.remove(3);
		assertArrayEquals(heap.queue, new int[] { 0, 1, 5, 6, 9, 8, 0 });
	}

}
