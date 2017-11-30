//Linked list in c++
#include <iostream>
using namespace std;
//Defination Linked List node 
struct node{
	int data;
	struct node* next;
	struct node* prev; 
};

// Linked List Defination contains node* varible declaration and functions  
class linkedlist
{
	struct node* List;
public:	
	linkedlist(){
		List = NULL;
	};
// insert inserts elements to begining of Linked List
	void insert(int data){
		struct node* temp = new node;
		temp->data = data;
		if(List == NULL){
			List = temp;
			List->next = NULL;
			List->prev = NULL;
		} 
		else{
			temp->next = List;
			temp->prev = NULL;
			List->prev = temp;
			List = temp;
		}
	}

//implements selection sort on Linked List
	void selectionsort(){
		struct node* i = List;
		struct node* j = List;
		struct node* min = List;
    	while(i->next != NULL){
			while(j->next != NULL){
				if(j->data < i->data){
					min = j;
				}
				j = j->next;
			}
			int temp = min-> data;
			min->data = List->data;
			List->data = temp;  
			i = i->next;
		}


	}

// Prints Linked List
	void printlist(){
		struct node* element = List;
		while(element->next != NULL){
			cout<<element->data<<"  ";
			element = element->next;
		}
		cout<<element->data;
	}

	~linkedlist(){
		delete []List;
	}
};



int main(){
	linkedlist L;
	int e,n;
	cout<<"Enter number of elements to be added in linkedlist";
	cin>>n;
	cout<<"Enter"<<n<<"elements of list:";
	for(int i=0;i<n;i++){
		cin>>e; 
		L.insert(e);
	}
	L.selectionsort();
	L.printlist();
	return 0;
}