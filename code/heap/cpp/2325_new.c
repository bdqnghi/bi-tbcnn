#include <bits/stdc++.h>
using namespace std;
#define infi 10000000
template <class T>
class min_heap
{
	vector <T> heap;
	public:
		int size(void){ return heap.size();}
		void heapify(int index)
		{
			int i = index;
			T t;
			int j = heap.size();
			while(i <= j/2 - 1)
			{
				if(heap[i] > heap[2*i])
				{
					t = heap[i];
					heap[i] = heap[2*i];
					heap[2*i] = t; 
					i = 2*i;
				}
				else if (heap[i] > heap[2*i + 1])
				{
					t = heap[i];
					heap[i] = heap[2*i + 1];
					heap[2*i + 1] = t;
					i = 2*i + 1;
				}
				else
				{
					break;
				}
			}
		}
		void insert(T j)
		{
			heap.push_back(j);
			int temp = heap.size() - 1;
			T t;
			while ( temp >0 && heap[temp/2] > heap[temp] )
			{
				t = heap[temp];
				heap[temp] = heap[temp/2];
				heap[temp/2] = t;
				temp = temp/2;
			}
		}
		void modify(int index,T val)
		{
			T temp = heap[index];
			heap[index] = val;
			T t;
			if( val > temp)
			{
				heapify(index);
			}
			else if (val < temp)
			{
				temp = index;
				while ( temp >0 && heap[temp/2] > heap[temp] )
				{
					t = heap[temp];
					heap[temp] = heap[temp/2];
					heap[temp/2] = t;
					temp = temp/2;
				}
			}
		}
		T pop()
		{
			T val = heap[0];
			heap[0] = heap[heap.size() - 1];
			heapify(0);
			heap.pop_back();
			return val;
		}
		/*void print()
		{
			int i;
			for (i = 0; i < heap.size(); ++i)
			{
				printf("%d ",heap[i]);
			}
			printf("\n");
		}*/
};

int main()
{
	min_heap <int> h;
	h.insert(6);
	h.insert(5);
	h.insert(3);
	h.insert(4);
	h.insert(677);
	h.insert(40);
	h.insert(4);
	h.insert(1);
	h.insert(2);
	//h.print();
	while(h.size() > 0)
	{
		printf("%d\n", h.pop());
	}
	return 0;
}