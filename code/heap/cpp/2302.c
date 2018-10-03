#include <iostream>
using namespace std;

// Heap class definition
class Heap {
public:
	int heapSize;
	int parent(int i);
	int leftChild(int i);
	int rightChild(int i);
	void heapify(int A[], int i);
	void build_heap(int A[]);
	void insert(int A[], int i);
	void heapsort(int A[]);
	int extract_max(int A[]);
	Heap(){heapSize = -1;}
};

// Heap class function which returns the index of the parent
// of the given index.
// Parameters:
//		i - the index whose parent to find
// Returns:
//		the index of the parent
int Heap::parent(int i)
{
	if(i % 2 == 0)
	{
		return (i-1)/2;
	}

	else
	{
		return i/2;
	}
}

// Heap class function which returns the index of the left child
// of the given index.
// Parameters:
//		i - the index whose left child to find
// Returns:
//		the index of the left child
int Heap::leftChild(int i)
{
	return 2*i+1;
}

// Heap class function which returns the index of the right child
// of the given index.
// Parameters:
//		i - the index whose right child to find
// Returns:
//		the index of the right child
int Heap::rightChild(int i)
{
	return 2*i+2;
}

// Heap class function which takes an array and makes sure it maintains
// the heap property
// Parameters:
//		A - the array to maintain heap property in
//		i - the index where to start checking if the array maintains
//			the heap property
void Heap::heapify(int A[], int i)
{
	// It is assumed that the trees at left and right are heaps
	int left = leftChild(i);
	int right = rightChild(i);
	int largest, temp;

	// Find the node in the root, left and right which has the
	// largest value
	if((left <= this->heapSize) && (A[left] > A[i]))
	{
		largest = left;
	}

	else
	{
		largest = i;
	}

	if((right <= this->heapSize) && (A[right] > A[largest]))
	{
		largest = right;
	}

	// Swap in the largest value to the root position
	if(largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		heapify(A, largest);
	}
}

// Heap class function which takes a random array and turns it into
// a heap
// Parameters:
//		A - the array to make a heap
void Heap::build_heap(int A[])
{
	int j = this->heapSize;
	// Make sure that each tree maintains the heap property
	for(int i = j/2; i >= 0; i--)
	{
		heapify(A, i);
	}
}

// Heap class function which inserts an element into a heap while
// maintaining the heap property
// Parameters:
//		A - the heap in array form
//		i - the element to insert into the heap
void Heap::insert(int A[], int i)
{
	this->heapSize++;
	// Increase the number of elements in the heap
	int k = this->heapSize;

	// Swap the elements into the proper position
	while((k > 0) && (A[parent(k)] < i))
	{
		A[k] = A[parent(k)];
		k = parent(k);
	}

	A[k] = i;
}

// Heap class function which takes a heap and sorts the elements
// Parameters:
//		A - the heap to sort in array form
void Heap::heapsort(int A[])
{
	int temp;
	build_heap(A);

	for(int i = this->heapSize; i >= 1; i--)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		this->heapSize--;
		heapify(A, 0);
	}
}

// Heap class function which takes a heap and removes the max element
// Parameters:
//		A - the heap in array form
// Returns:
//		max - the max element which has been removed
int Heap::extract_max(int A[])
{
	if(this->heapSize < 0)
	{
		cout << "Error - Heap underflow\n";
	}

	else
	{
		int max = A[0];
		A[0] = A[this->heapSize];
		this->heapSize--;
		heapify(A, 0);
		return max;
	}
}

// PriorityQueue class definition
class PriorityQueue: public Heap{
public:
	int maximum(int A[]);
};

// PriorityQueue class function which returns the max element
// Parameter:
//		A - the heap in array form
// Returns:
//		the max element in the heap
int PriorityQueue::maximum(int A[])
{
	if(this->heapSize > 0)
	{
		return A[0];
	}

	else
	{
		cout << "Error - Heap underflow" <<endl;
	}
}

// A function which takes a heap in array form and prints the values
// in it.
// Parameters:
//		A - the heap in array form
//		last - the index of the last full element in the heap
void printHeap(int A[], int last)
{
	cout << "Current Heap:\n";
	for(int i = 0; i <= last; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

// The function which creates the user interface for manipulating the
// heap and priority queue.
void main(void)
{
	PriorityQueue heap;
	int A[100];
	int value;
	int count = 0;

	// Create a heap with 10 elements
	cout << "Please enter 10 values to begin the heap...\n";
	while(count < 10)
	{
		cout << "Value:";
		cin >> value;
		A[count] = value;
		count++;
		heap.heapSize++;
	}

	heap.build_heap(A);

	// Allow user to manipulate the heap
	while(heap.heapSize < 100)
	{
		cout << "Please enter option for the heap...\n";
		cout << "\t1. Insert element into the heap.\n";
		cout << "\t2. Maximum Value.\n";
		cout << "\t3. Extract maximum element from the heap.\n";
		cout << "\t4. Print heap.\n";
		cout << "\t5. Heap sort, Print sorted results and exit.\n";
		cin >> value;

		if(value == 1)
		{
			cout << "Enter value to insert: ";
			cin >> value;
			heap.insert(A, value);
		}

		else if(value == 2)
		{
			cout << "Maximum: " << heap.maximum(A) <<endl;
		}

		else if(value == 3)
		{
			cout << "Maximum: " << heap.extract_max(A) << endl;
		}

		else if(value == 4)
		{
			printHeap(A, heap.heapSize);
		}

		else if(value == 5)
		{
			int last = heap.heapSize;
			heap.heapsort(A);
			printHeap(A, last);
			exit(1);
		}
	}
}
