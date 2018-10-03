/*
 * Heap
 *
 * Author: Howard Cheng
 *
 * This is an implementation of heap using an array.  All routines
 * here reallocs if the "A" field of the heap has not been allocated
 * to store the required number of elements.  Also, write a cmp
 * function that behaves like the one required by qsort().
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ELEMTYPE;        /* replace by any element type */

typedef struct {
  ELEMTYPE *A;
  int n, size;
} Heap;

int cmp(ELEMTYPE a, ELEMTYPE b)
{
  return a - b;
}

void init_heap(Heap *heap, int init_size)
{
  heap->A = malloc(init_size * sizeof(*(heap->A)));
  assert(heap->A);
  heap->n = 0;
  heap->size = init_size;
}

void free_heap(Heap *heap) 
{
  if (heap->size > 0) {
    free(heap->A);
    heap->n = 0;
    heap->size = 0;
  }
}

void up_heap(Heap *heap, int k)
{
  ELEMTYPE v = heap->A[k];
  assert(0 <= k && k < heap->n);
  while (k > 0 && cmp(v, heap->A[(k-1)/2]) < 0) {
    heap->A[k] = heap->A[(k-1)/2];
    k = (k-1)/2;
  }
  heap->A[k] = v;
}

void down_heap(Heap *heap, int k)
{
  int j;
  ELEMTYPE v;

  v = heap->A[k];
  while (2*k+1 < heap->n) {
    j = 2*k+1;
    if (j+1 < heap->n && cmp(heap->A[j], heap->A[j+1]) > 0) {
      j++;
    }
    if (cmp(v, heap->A[j]) <= 0) {
      break;
    }
    heap->A[k] = heap->A[j];
    k = j;
  }
  heap->A[k] = v;
}

void insert(Heap *heap, ELEMTYPE item)
{
  if (heap->n == heap->size) {
    heap->size += 10;
    heap->A = realloc(heap->A, heap->size*sizeof(*(heap->A)));
    assert(heap->A);
  }
  heap->A[heap->n] = item;
  up_heap(heap, heap->n++);
}

ELEMTYPE delete(Heap *heap)
{
  ELEMTYPE val = heap->A[0];
  heap->A[0] = heap->A[--(heap->n)];
  down_heap(heap, 0);
  return val;
}

void check_heap(Heap *heap)
{
  int i, j;

  for (i = 0; i < heap->n; i++) {
    j = 2*i;
    if (j < heap->n) {
      assert(cmp(heap->A[i], heap->A[j]) <= 0);
    }
    if (j+1 < heap->n) {
      assert(cmp(heap->A[i], heap->A[j]) <= 0);
    }
  }
}

int main(void)
{
  int p1, p2, p3;
  int n, t;
  int prev;
  Heap heap;

  while (scanf("%d", &n) == 1 && n > 0) {
    scanf("%d %d %d", &p1, &p2, &p3);
    prev = 1;
    init_heap(&heap, 20);
    insert(&heap, p1);
    insert(&heap, p2);
    insert(&heap, p3);

    while (n > 0) {
      t = delete(&heap);
      if (t != prev) {
        printf("%ld ", t);
        n--;
        prev = t;
        insert(&heap, p1*t);
        insert(&heap, p2*t);
        insert(&heap, p3*t);
      }
    }
    printf("\n");
    free_heap(&heap);
  }

  return 0;
}
