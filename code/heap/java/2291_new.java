package com.kimjeeyoung.datastruct;

import java.util.*;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class FibHeapTest extends AbstractHeapTest {

  @Test
  public void testPop_simple() {
    FibHeap<Integer> heap = new FibHeap<>();
    heap.insert(101);
    heap.insert(102);
    assertEquals(101, heap.popMinimum().intValue());
    assertEquals(1, heap.size());
    assertEquals(102, heap.popMinimum().intValue());
    assertEquals(0, heap.size());
    validate(heap);
  }

  @Test
  public void testUnion() {
    FibHeap<Integer> heapA = new FibHeap<>();
    heapA.insert(1);
    FibHeap<Integer> heapB = new FibHeap<>();
    heapB.insert(1);
    heapB.insert(3);
    FibHeap<Integer> heapC = heapA.union(heapB);
    assertEquals(3, heapC.size());
    assertEquals(1, heapC.getMinimum().intValue());
    validate(heapC);
  }

  @Test
  public void testDecrement_simple() {
    FibHeap<Integer> heap = new FibHeap<>();
    Heap.HeapNode<Integer> last = heap.insert(6);
    Heap.HeapNode<Integer> secondLast = heap.insert(5);
    heap.insert(4);
    heap.insert(3);
    heap.insert(2);
    heap.insert(1);
    assertEquals(1, heap.popMinimum().intValue());
    last.decrement(0);
    secondLast.decrement(-1);
    assertEquals(-1, heap.popMinimum().intValue());
    validate(heap);
  }

  @Test
  public void testRandom_union() {
    final int SIZE_PER_HEAP = 100;
    final int NUM_HEAPS = 100;
    final Random RANDOM = new Random(0);
    FibHeap<Integer> combinedHeap = new FibHeap<>();
    for (int j = 0; j < NUM_HEAPS; j++) {
      FibHeap<Integer> localHeap = new FibHeap<>();
      List<Integer> values = new ArrayList<>();
      for (int i = 0; i < SIZE_PER_HEAP; i++) {
        values.add(j * SIZE_PER_HEAP + i);
      }
      Collections.shuffle(values, RANDOM);
      for (Integer value : values) {
        localHeap.insert(value);
      }
      combinedHeap = combinedHeap.union(localHeap);
    }
    validate(combinedHeap);
    assertEquals(SIZE_PER_HEAP * NUM_HEAPS, combinedHeap.size());
    for (int i = 0; i < SIZE_PER_HEAP * NUM_HEAPS; i++) {
      assertEquals(i, combinedHeap.popMinimum().intValue());
      if (i % SIZE_PER_HEAP == 0) {
        validate(combinedHeap);
      }
    }
    assertEquals(0, combinedHeap.size());
    validate(combinedHeap);
  }

  @Override
  <K> Heap<K> newHeap() {
    return new FibHeap<K>();
  }

  @Override
  <K> Heap<K> newHeap(Comparator<K> comparator) {
    return new FibHeap<>(comparator);
  }

  @Override
  void validate(Heap<?> heap) {
    ((FibHeap<?>) heap).validateState();
  }
}