#include <iostream>

using namespace std;

class node {
	
public: 

	int data;
	node *next;
	
}; //end node

int main() {
	
	node *n = new node;
	n->data = 1;
	n->next = 0;
	node *temp = n;
	node *root = n;
	
	
	n = new node;
	n->data = 2;
	n->next = 0;
	temp->next = n;
	temp = n;
	
	
	n = new node;
	n->data = 3;
	n->next = 0;
	temp->next = n;
	temp = n;
	
	
	cout << root->data << endl;
	cout << root->next->data << endl;
	cout << root->next->next->data << endl;

	node *i = root;
	
	while (i->next != 0)
		
	
	return 0;
}