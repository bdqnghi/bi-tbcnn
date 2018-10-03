#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

// heap����
// heap[0] �̓_�~�[
typedef vector<int> Heap;

int parent(int i) { return i/2; }
int left(int i) { return 2*i; }
int right(int i) { return 2*i+1; }

// i ���Ƃ��镔���؂� max-heap �ɂȂ�悤�� heap[i] ���藎�Ƃ�
void maxHeapify(Heap &heap, const int i, const int heapSize)
{
	int l = left(i);
	int r = right(i);
	int largest = i;

	if (l<heapSize && heap[l]>heap[largest]) largest = l;
	if (r<heapSize && heap[r]>heap[largest]) largest = r;

	if (largest != i) {
		swap(heap[i], heap[largest]);
		maxHeapify(heap, largest, heapSize);
	}
}

// maxHeapfy �̋t
void minHeapify(Heap &heap, const int i, const int heapSize)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l<heapSize && heap[l]<heap[smallest]) smallest = l;
	if (r<heapSize && heap[r]<heap[smallest]) smallest = r;

	if (smallest != i) {
		swap(heap[i], heap[smallest]);
		minHeapify(heap, smallest, heapSize);
	}
}

// heap �� max-heap �ɂ���
void buildMaxHeap(Heap &heap)
{
	for (int i=heap.size()/2; 0 < i; --i) {
		maxHeapify(heap, i, heap.size());
	}
}

// heap �� min-heap �ɂ���
void buildMinHeap(Heap &heap)
{
	for (int i=heap.size()/2; 0 < i; --i) {
		minHeapify(heap, i, heap.size());
	}
}

// heap ��\�[�g
void heapSort(Heap &heap)
{
	buildMaxHeap(heap);
	//buildMinHeap(heap);

	int heapSize = heap.size();
	for (int i=heap.size()-1; 1 < i; --i) {
		swap(heap[1], heap[i]);
		maxHeapify(heap, 1, --heapSize);
		//minHeapify(heap, 1, --heapSize);
	}
}

// heap �̍ő�̒l��Ƃ肾��
int heapExtractMax(Heap &heap, int heapSize)
{
	if (heapSize < 1) assert(!"Heap Under Flow");
	int maxValue = heap[1];
	heap[1] = heap[heapSize];
	--heapSize;
	maxHeapify(heap, 1, heapSize);
	return maxValue;
}

// max-heap ��ۂ��Ȃ���ߓ_�̒l��㏸������
void heapIncreaseKey(Heap &heap, int i, const int key)
{
	if (key < heap[i]) assert(!"newKey < nowKey");
	heap[i] = key;
	while (i>1 && heap[parent(i)] < heap[i]) {
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}

// max-heap ��ۂ��Ȃ���ߓ_��ǉ�����
void maxHeapInsert(Heap &heap, const int key)
{
	heap.push_back(INT_MIN);
	heapIncreaseKey(heap, heap.size()-1, key);
}

