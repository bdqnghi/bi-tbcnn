#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int n): data(n), next(NULL){}
};

class Stack{
public:
	Node* top;

	Node* pop(){
		if(top!=NULL){
			Node* temp = top;
			top = top->next;
			temp->next=NULL;
			return temp;
		}
		return NULL;
	}

	void push(int data){
		Node* node = new Node(data);
		node->next = top;
		top = node;
	}
};

void main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	Node* temp = s.pop();
	cout << temp->data;
}