//============================================================================
// Name        : heap.cpp
// Author      : Evgeniya Bautina
// Version     : 04/06/2013
// Copyright   :
// Description : Class Heap Implementation
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

using namespace std;

int main1() {
  Heap<int> *heap = new Heap<int>();
  for (int i = 0; i < heap->getArraySize(); i++) {
    int randNumber = rand() % 10 + 1;
    heap->addElement(randNumber);
  }
  heap->checkHeap();
  heap->printHeap();
  while(!heap->isEmpty()){
    cout << heap->deleteMinElement() << " ";
    heap->checkHeap();
  }
  cout << endl;
  delete heap;
  return 0;
}

