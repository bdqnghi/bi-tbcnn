/* Copyright 2014 Laurie Chan-Lam */

#include <gtest/gtest.h>
#include "../../PrepGoogleLib/include/Heap.h"

TEST(Heap, Empty) {
  Heap heap;
  heap.sort();
  EXPECT_TRUE(heap.is_sorted());
}

TEST(Heap, Sorted) {
  Heap heap;
  for (int i = 0; i < 10; ++i)
    heap.insert(i);
  heap.heapify();
  EXPECT_TRUE(heap.is_heap());
  heap.sort();
  EXPECT_TRUE(heap.is_sorted());
}

TEST(Heap, ReverseSorted) {
  Heap heap;
  for (int i = 0; i < 10; ++i)
    heap.insert(10 - i);
  heap.heapify();
  EXPECT_TRUE(heap.is_heap());
  heap.sort();
  EXPECT_TRUE(heap.is_sorted());
}

TEST(Heap, Random) {
  Heap heap;
  for (int i = 0; i < 500; ++i)
    heap.insert(rand() % 1000);  // NOLINT: rand is ok, no multi-threading
  Heap heap_copy = heap;
  heap.heapify();
  bool is_heap = heap.is_heap();
  EXPECT_TRUE(is_heap);
  heap.sort();
  bool is_sorted = heap.is_sorted();
  EXPECT_TRUE(is_sorted);
  if (!is_heap || !is_sorted)
    heap_copy.write("store_heap.txt");
}
