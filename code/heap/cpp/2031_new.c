#include "heap.h"

Heap::Heap(type_t type)
{
	heap = NULL;
	heap_length = 0;
	data_length = 0;
	Heap::type = type;
}

Heap::Heap()
{
	heap = NULL;
	heap_length = 0;
	data_length = 0;
	type = MIN_HEAP;
}

/*
	insert_heap - inserts a key into the heap
		heap_t		*heap	- heap to insert into
		heapkey_t	*key	- key to insert
		returns zero upon success, non zero on failure.
*/
int Heap::insert(const heapkey_t *key)
{
	if ( data_length < ++heap_length )
	{
		heap = (heapkey_t *)realloc( (void *)heap, (heap_length + 1) * sizeof(heapkey_t) );
		if (heap == NULL)
		{
			perror("realloc() failed in function insertHeap()");
			return 1;
		}
	}

	data_length = heap_length;
	heap[heap_length] = *key;
	fix();
	return 0;
}

/*
	modifyHeap - updates given key if found in heap
		heap_t		*heap	- heap to modify
		heapkey_t	*key	- key to update
*/
void Heap::modify(const heapkey_t *key)
{
	int i;

	for (i = 0; i < heap_length; i++)
	{
		if (heap[i].index == key->index)
		{
			heap[i].data = key->data;
			fix();
			break;
		}
	}
}

/*
	extractHeap - extracts requested index from heap
		heap_t	*heap	- heap to extract from
		int	index	- index in heap to return. (might be useful... someday)
		returns key requested
*/
heapkey_t Heap::extract(const int index)
{
	heapkey_t	key = heap[index];
	heap[index] = heap[heap_length--];
	fix();
	return key;
}

/*
	fixHeap - restores heap property
		heap_t *heap - heap to fix
*/
void Heap::fix()
{
	int index = 1;
	int child;

	while(1)
	{
		if (2 * index > heap_length)
			break;
		if (2 * index + 1 > heap_length)
			child = 2 * index;
		else if (type == MIN_HEAP)
			child = (heap[2 * index].data < heap[2 * index + 1].data) ? 2 * index : 2 * index + 1;
		else
			child = (heap[2 * index].data > heap[2 * index + 1].data) ? 2 * index : 2 * index + 1;
			

		if (	( type == MIN_HEAP && heap[index].data > heap[child].data ) ||
			( type == MAX_HEAP && heap[index].data < heap[child].data ) )
		{
			heapkey_t temp = heap[index];

			heap[index] = heap[child];
			heap[child] = temp;
			index = child - 1;
		}
		index++;
	}
}


Heap::~Heap()
{
	free((void *)heap);
}
