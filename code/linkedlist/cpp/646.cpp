#include <stdio.h>
#include <stdlib.h>

class LinkedList {

	struct Node {
		int value;		// data in node 
		Node *next;		// pointer to next node 
	};

public:
	//constructor
	LinkedList() {
		first = NULL;	// make first node a null pointer
		ListLength = 0;
	}
	// getter for first
	Node* getHead() {
		return first;
	}
	//setter for first 
	void setHead(Node* n) {
		first = n;
	}

	// adds node with specified value to beginning of list
	void addToHead(int value) {
		Node *n = new Node;
		n->next = first;
		n->value = value;
		setHead(n);
		ListLength++;
	}

	// adds value to list at specified position and shifts list accordingly.
	void addToListAtPosition(int position, int value) {
		if (getListLength() < position) {
			return;
		}
		if (getListLength() == 0) {
			addToHead(value);
			return;
		}
		if (getListLength() == position + 1) {
			appendToList(value);
			return;
		}

		Node* curr = getHead();			//gets head of list 
		Node* prev = NULL;
		for (int i = 0; i < position; i++) {
			prev = curr;
			curr = curr->next;
		}
		// now prev points to the node before the place where I'll add a new node
		// and curr points to the node that'll need to be shifted "forward"

		Node *newNode = new Node;
		prev->next = newNode;
		newNode->next = curr;
		newNode->value = value;
		ListLength++;

	}

	// adds given value to end of list
	void appendToList(int value) {
		Node *temp = getHead();		// gets head of list

		while (temp->next != NULL) {
			temp = temp->next;
		}
		Node *n = new Node;
		n->next = NULL;
		temp->next = n;
		ListLength++;
	}

	// removes node at specified position
	void removeFromListAtPosition(int position) {
		if (position == getListLength() - 1) {
			removeFromEnd();
			return;
		}
		if (position == 0) {
			removeFromHead();
			return;
		}
		Node* prev = NULL;
		Node* curr = getHead();
		for (int i = 0; i < position; i++) {
			prev = curr;
			curr = curr->next;
		}
		// at this point, prev points to the node before the one to be deleted
		// and curr to the one to be deleted
		prev->next = curr->next;
		delete curr;
		ListLength--;
	}

	// removes node at the beginning of linked list
	void removeFromHead() {		
		Node *temp = getHead();
		setHead(getHead()->next);		// creates new first 
		delete temp; 
		ListLength--;
	}

	// removes node from end of linked list 
	void removeFromEnd() {
		Node *curr = getHead(); 
		Node *prev = NULL;
		while (curr->next != NULL) {
			prev = curr; 
			curr = curr->next;
		}
		// here, curr points to node to delete and prev the node before it. 
		
		prev->next = NULL; 
		delete curr; 
		ListLength--;
	}

	// returns true if given value is contained within the linked list
	bool find(int value) {
		bool flag = false; 
		Node *temp = getHead();
		while (temp != NULL) {
			if (temp->value == value) {
				flag = true;
				break;
			}
			temp = temp->next;
		}
		return flag;
	}

	// reverses the linked list in place
	void reverseList() {
		Node* prevNode = NULL; 
		Node* currNode = getHead();
		Node* nextNode = NULL; 

		while (currNode != NULL) {
			nextNode = currNode->next;
			currNode->next = prevNode;
			prevNode = currNode;
			currNode = nextNode; 
		}
		setHead(prevNode);
	}

	// returns length of linked list 
	int getListLength() {
		return ListLength;
	}

private:
	Node *first;		// first node in list
	int ListLength;			// length of list
};