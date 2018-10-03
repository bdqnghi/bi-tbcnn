#include <stdlib.h>
#include "../Saf/Algo/Struct/Heap.h"
#include "../Saf/Algo/Sort/SortUtil.h"
#include "../Saf/Collection/DynamicArray.h"
#include "Framework/UnitTestFramework.h"

#define HEAP_SEED	531
#define HEAP_SIZE	10000
#define HEAP_REPEAT	1000
#define HEAP_VAL	Saf::Size

template <class Container, class Val>
static void CreateHeap(Container& heap, Saf::Size elems, Val valMax, Saf::Size seed)
{
	srand((unsigned int)seed);
	for (Saf::Size i = 0; i < elems; ++i)
	{
		heap.PushBack(Val(rand() % valMax));
	}

	Saf::Algo::Struct::Heap::MakeHeap(heap.Begin(), heap.End());
}

SAF_UNIT_TEST(Remove, Heap)
{
	Saf::Collection::DynamicArray<HEAP_VAL> heap;
	CreateHeap(heap, HEAP_SIZE, HEAP_SIZE, HEAP_SEED);
	SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));

    while (!heap.IsEmpty())
    {
        Saf::Size pos = rand() % heap.Elements();
		HEAP_VAL val = heap[pos];

        Saf::Algo::Struct::Heap::RemoveHeap(heap.Begin(), heap.End(), &heap[pos]);
        
		SAF_ASSERT_TRUE(val == *heap.Back());
		heap.PopBack();
		SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));
    }
}

SAF_UNIT_TEST(Modify, Heap)
{
	Saf::Collection::DynamicArray<HEAP_VAL> heap;
	CreateHeap(heap, HEAP_SIZE, HEAP_SIZE, HEAP_SEED);
	SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));

    for (Saf::Size i = 0; i < HEAP_REPEAT; ++i)
    {
        Saf::Size pos = rand() % heap.Elements();
		HEAP_VAL newVal = HEAP_VAL(rand() % HEAP_SIZE);
		heap[pos] = newVal;

        Saf::Algo::Struct::Heap::ModifyHeap(heap.Begin(), heap.End(), &heap[pos]);        
		SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));
    }
}

SAF_UNIT_TEST(Push, Heap)
{
	Saf::Collection::DynamicArray<HEAP_VAL> heap;

    for (Saf::Size i = 0; i < HEAP_SIZE; ++i)
    {
		HEAP_VAL newVal = HEAP_VAL(rand() % HEAP_SIZE);
		heap.PushBack(newVal);

        Saf::Algo::Struct::Heap::PushHeap(heap.Begin(), heap.End());
		SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));
    }
}

SAF_UNIT_TEST(Pop, Heap)
{
	Saf::Collection::DynamicArray<HEAP_VAL> heap;
	CreateHeap(heap, HEAP_SIZE, HEAP_SIZE, HEAP_SEED);
	SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));

    while (!heap.IsEmpty())
    {
		HEAP_VAL val = *heap.Front();
        Saf::Algo::Struct::Heap::PopHeap(heap.Begin(), heap.End());
        
		SAF_ASSERT_TRUE(val == *heap.Back());
		heap.PopBack();
		SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));
    }
}

SAF_UNIT_TEST(Make, Heap)
{
	Saf::Collection::DynamicArray<HEAP_VAL> heap;
	
	for (Saf::Size i = 0; i < HEAP_REPEAT; ++i)
	{
		heap.Free();
		CreateHeap(heap, i * HEAP_SIZE / 1000, HEAP_SIZE, i * i);
		SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));
	}	
}

SAF_UNIT_TEST(Sort, Heap)
{
	Saf::Collection::DynamicArray<HEAP_VAL> heap;
	
	for (Saf::Size i = 0; i < HEAP_REPEAT; ++i)
	{
		heap.Free();
		CreateHeap(heap, i * HEAP_SIZE / 1000, i * HEAP_SIZE, i * i);
		SAF_ASSERT_TRUE(Saf::Algo::Struct::Heap::IsHeap(heap.Begin(), heap.End()));
		Saf::Algo::Struct::Heap::SortHeap(heap.Begin(), heap.End());
		SAF_ASSERT_TRUE(Saf::Algo::Sort::IsSorted(heap.Begin(), heap.End()));
	}	
}

SAF_TEST_RUNALL;