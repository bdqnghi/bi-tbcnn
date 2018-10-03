//1862_heap.cpp

#include<iostream>
#include<cmath>

double heap[200];

void up(double *heap, int index){
	int parent = index/2;
	if(parent == 0)return;
	if(heap[index]>heap[parent]){
		std::swap(heap[index], heap[parent]);
		up(heap, parent);
	}
}

void down(double *heap, int index){
	int left = 2 * index;
	int right = left + 1;
	if(left<=heap[0]){
		if(right<=heap[0]){
			if(heap[left]<heap[right]){
				if(heap[index]<heap[right]){
					std::swap(heap[index], heap[right]);
					down(heap, right);
				}
				else{
					return;
				}
			}
			else{
				if(heap[index]<heap[left]){
					std::swap(heap[index], heap[left]);
					down(heap, left);
				}
				else{
					return;
				}
			}
		}
		else{
			if(heap[index]<heap[left]){
				std::swap(heap[index], heap[left]);
				down(heap, left);
			}
			else{
				return;
			}
		}
	}
	else{
		return;
	}
}

void make_heap(double *heap, int n){
	heap[0] = n;
	for(int i=n/2; i!=0; --i){
		down(heap, i);
	}
}

void push(double * heap,double value){
	int n = int(++heap[0]);
	heap[n] = value;
	up(heap, n);
}

int size(double *heap){
	return (int)heap[0];
}

double top(double * heap){
	return heap[1];
}

void pop(double * heap){
	int n = int(--heap[0]);
	std::swap(heap[1], heap[n+1]);
	down(heap, 1);
}

int main(int argc, char ** argv){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%lf", &heap[i]);
	}
	make_heap(heap, n);
	double t1, t2;
	while(size(heap)>1){
		t1 = top(heap);
		pop(heap);
		t2 = top(heap);
		pop(heap);
		
		t1 = 2 * sqrt(t1 * t2);
		push(heap, t1);
	}
	printf("%.3lf\n", top(heap));

	return 0;
}
