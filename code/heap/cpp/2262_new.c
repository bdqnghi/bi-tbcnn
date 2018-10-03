#include "Heap.h"

#include <iostream>

using namespace  std;

int main()
{
	const int n = 9;
	int data[n] = {0,1,2,3,4,8,9,3,5};

	MyHeap<int> *intHeapObj = new MyHeap<int>;

	intHeapObj->initHeap(data,n);
	intHeapObj->printfHeap();

	intHeapObj->makeHeap();
	intHeapObj->printfHeap();

	intHeapObj->pushHeap(7);
	intHeapObj->printfHeap();

	intHeapObj->popHeap();
	cout << "The top of heap :" << intHeapObj->getVec().back() << endl;
	intHeapObj->getVec().pop_back();
	intHeapObj->printfHeap();

	intHeapObj->sortHeap();
	cout << "Sorted data :";
	for (int i = 1;i <= n;++i)
		cout << intHeapObj->getVec()[i] << " ";
	cout << endl;

        delete intHeapObj;

	return 0;
}
