#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct _min_heap{
	int cost;
	int height;
	struct bin_search_tree* left;
	struct bin_search_tree* right;
}min_heap;

int main()
{
	int i;
	min_heap* heap = (min_heap *)malloc(sizeof(min_heap));
	heap->left = NULL;
	heap->right = NULL;
	heap->cost = -1;
	heap->height = 0;
	for(i=0;i<10;i++)
	{
		cin>>n;
		insert_to_heap(heap, n);
	}
	return 0;
}

void insert_to_heap(min_heap * heap, int n)
{
	if(height<=0)
	{
		if(heap->left == NULL)
		{
			heap->left = (min_heap*)malloc(sizeof(min_heap));
			heap->left->left = NULL;
			heap->left->right = NULL;
			heap->left->cost = n;
			heapify(heap, 
		}
		else 
			insert_to_heap(heap->left, n);
		heap->height += 1;
	}
	else 
	{
		if(heap->right == NULL)
		{
			heap->right = (min_heap*)malloc(sizeof(min_heap));
			heap->right->left = NULL;
			heap->right->right = NULL;
			heap->right->cost = n;
		}
		else 
			insert_to_heap(heap->right, n);
		heap->height += 1;
	}
	
	
}
