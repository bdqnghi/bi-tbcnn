#include <iostream>
#include <memory>
#include <vector>
using namespace std;


//MIN-HEAP implementation using vector(similar to array)

class MinHeap{
	public:
	MinHeap(){
	}
	
	void insert(int value){ //values are inserted at the end and then heapify-up
		heap.push_back(value); 	
		heapifyUp(heap.size()-1); //parameter: index of last value just inserted 
	}
	
 	int deleteMin(){ //return top element and put last in root. Then heapify down
		int ret=heap[0];
		heap[0]=heap.back();
		heap.pop_back();
		heapifyDown();
		return ret;
	}
	
	int peekMin(){
		return heap[0];
	}
	
	void print(){
		cout<<"Heap: ";
		for(int i=0;i<heap.size();i++){
			cout<<heap[i]<<" ";
		}
		cout<<endl;
	}

	int heapSize(){
		return heap.size();
	}
	
	private:
	vector<int> heap;
	
	//return parent node of the given 
	int parent(unsigned int son){ //unsigned because of right shift
		if(son!=0)
			return (son-1)>>1; //minus 1 because root is 0,not 1
		else
			return 0; 
	}
	
	//return left child
	int left(int parent){
		int index=2*parent+1;
		return index<heap.size()? index : parent;
	}
	
	int right(int parent){
		int index=2*parent+2;
		return index<heap.size()? index : parent;
	}
	
	void swap(int & a, int & b){
		a^=b;
		b^=a;
		a^=b;
	}
	
	//called after insertions. Restores heap property from last element to root
	void heapifyUp(int index){
		while(index>0 && parent(index)>=0 && heap[parent(index)]>heap[index]){
			swap(heap[parent(index)],heap[index]);
			index=parent(index);
		}
	}
	
	//called after deletions. Delete at root, and bring last to top. Thean heapify down, replace largest of its children on top
	//In the worst case, the new root has to be swapped with its child on each level until it reaches the bottom level of the heap, meaning that the delete operation has a time complexity relative to the height of the tree, or O(log n).
	void heapifyDown(){
		int index=0;
		while(heap[index]>heap[left(index)] || heap[index]>heap[right(index)]){
			int smallest=index;
			if(heap[smallest]>heap[left(index)]){
				smallest=left(index);
			}
			if(heap[smallest]>heap[right(index)]){
				smallest=right(index);
			}
			swap(heap[index],heap[smallest]);
			index=smallest;
		} 
		
		
	}
	
	
}; //end of class


int main(){

	MinHeap* myheap = new MinHeap();
    myheap->insert(700);
    myheap->print();
    myheap->insert(500);
    myheap->print();
    myheap->insert(100);
    myheap->print();
    myheap->insert(800);
    myheap->print();
    myheap->insert(200);
    myheap->print();
    myheap->insert(400);
    myheap->print();
    myheap->insert(900);
    myheap->print();
    myheap->insert(1000);
    myheap->print();
    myheap->insert(300);
    myheap->print();
    myheap->insert(600);
    myheap->print();

    // Get priority element from the heap
    int heapSize = myheap->heapSize();
    for ( int i = 0; i < heapSize; i++ ){
    	cout << "Get min element = " << myheap->deleteMin() << endl;
    	myheap->print();	
    	cout<<endl;
    }
	
	delete myheap;






	return 0;
}





























