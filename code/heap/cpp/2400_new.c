#include "HeapSort.h"
#include "Heap.h"
HeapSort::HeapSort(int *arr, int len)
	: Sort(arr, len)
{
}
HeapSort::HeapSort(int len)
	: Sort(len)
{
}
HeapSort::~HeapSort()
{
}

void HeapSort::sort()
{
	Heap heap(m_arr, m_len);
	heap.buildMaxHeap();
	heap.print();
#define heapsize heap.getHeapSize()
	for(int i = 0; i < m_len - 1; ++i)
	{
		heap.swap(1, heapsize);
		heap.setHeapSize(heapsize - 1);
		heap.maxHeapify(1);
	}
	heap.setHeapSize(m_len);
#undef heapsize
	heap.print();
	//heap.buildMaxHeap();
	//heap.print();
}
