#include "stdafx.h"
#include "Array.h"

struct TArrayTest {
  TArrayTest() 
  {
    CHeap<int> kHeap;
    kHeap.Add(5);
    kHeap.Add(345);
    kHeap.Add(-5);
    kHeap.Add(675);
    kHeap.Add(11);

    kHeap.Append(202);
    kHeap.Append(201);
    kHeap.Append(-1000);

    kHeap.InitHeap();

    int i = kHeap[0];

    kHeap.Remove(0);
    i = kHeap[0];

    kHeap.RemoveValue(i);

    kHeap[3] = 66;
    kHeap.Resort(3);

    i = kHeap.Find(1000);

    i = kHeap.Find(675);
    i = kHeap.Find(345);
  }
} /*g_ArrayTest*/;