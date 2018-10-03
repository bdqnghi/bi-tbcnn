#include "Heap.h"
#include <cstdlib>
#include <cstdio>

#define MinElements (1)

struct HeapStruct {
	int Capacity;
	int Size;
	int *Elements;
};

Heap InitializeHeap(int MaxElements) {
	Heap H;

	if(MaxElements < MinElements) {
		printf("Heap Size is too small ! \n");
		return NULL;
	}

	H = (Heap)malloc(sizeof(struct HeapStruct));
	if(H == NULL) {
		printf("out of space");
		return NULL;
	}

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements = (int *)malloc(sizeof(int) * (MaxElements+1) );
	if(H->Elements == NULL) {
		printf("out of space ! \n");
		return NULL;
	}
	H->Elements[0] = -1;

	return H;
}

int IsFull(Heap H) {
	return H->Capacity == H->Size;
}

int IsEmpty(Heap H) {
	return H->Size == 0;
}

void Insert(int X, Heap H) {
	if(IsFull(H)) {
		printf("the Heap is full !\n");
		return ;
	}
	int i;
	for(i = ++H->Size; H->Elements[i/2] > X ; i /= 2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = X;
}

int DeleteMin(Heap H) {
	int MinElement, LastElement;

	if(IsEmpty(H)) {
		printf("the Heap is empty !\n");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];

	int i,Child;
	for(i = 1; i*2 <= H->Size; i = Child) {
		Child = i * 2;
		if(Child != H->Size && H->Elements[Child] > H->Elements[Child + 1])
			Child++;
		if(LastElement > H->Elements[Child])
			H->Elements[i] = H->Elements[Child];
		else
			break;
	}
	H->Elements[i] = LastElement;
	return MinElement;
}