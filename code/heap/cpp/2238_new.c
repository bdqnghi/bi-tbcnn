#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int len = 1000;

template<class T>
inline void iswap(T& a, T& b) { T c = a; a = b; b = c; }

/* Build big heap. */
inline void buildHeap(int n, vector<int>& heap)
{
	for(int i = n >> 1; i >= 0; i--)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int max = i;
		if(l <= n && heap[l] > heap[max]) { max = l; }
		if(r <= n && heap[r] > heap[max]) { max = r; }
		if(max != i) { iswap(heap[i], heap[max]);}
	}
}

inline void heapSort(vector<int>& heap)
{
	for(int i = len - 1; i > 0; i--)
	{
		buildHeap(i, heap);
		iswap(heap[0], heap[i]);
	}
}

inline void displayHeap(vector<int>& heap)
{
	for(vector<int>::iterator it = heap.begin(); it != heap.end(); it++)
	{
		cout << (*it) << " " << endl;
	}
}

int main()
{
	vector<int> heap;
	for(int i = 0; i < len; i++)
	{
		heap.push_back(rand() % len);
	}

	heapSort(heap);

	displayHeap(heap);

	return 0;
}
