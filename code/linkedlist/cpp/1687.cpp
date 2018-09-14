#include <iostream>
#include "linkedlist.h"
using namespace std;

int LinkedList::getSize() {
	int counter = 0;
	Node* temp;
	temp = head;	
	
	// Iterate through the list
	while (temp != NULL) {
		temp = temp->next;
		counter++;
	}
	return counter;
}

void LinkedList::insertAt(int value, int pos) {
	Node* temp;
	if (pos == 0) {
		// list is currently empty
		if (head == NULL) {
			// create a new node named head
			head = new (struct Node);
			head->value = value;
			head->next = NULL;			
		}
		// list is not empty
		else {
			temp = new (struct Node);
			Node* ptr;
			ptr = head;
			head = temp;
			// Set members
			head->value = value;
			head->next = ptr;		
		}	
	}
	else if (pos > 0 && pos <=getSize()) {
		Node* prev, *curr;
		curr = head;
		for (int i = 0; i < pos; i++) {
			prev = curr;
			curr = curr->next;		
		}
		temp = new(struct Node);
		prev->next = temp;
		temp->next = curr;
		temp->value = value;
	}
	else {
		cout << "Out of range" << endl;	
	}
}

void LinkedList::deleteAt(int pos) {
	if (head==NULL) {
		cout << "Empty list" <<endl;	
	}
	else {
		Node* prev, *curr;
		curr = head;
		if (pos==0) {
			head = curr->next;		
		} else {
			if (pos > 0 && pos < getSize()) {
				for (int i = 0; i < pos; i++) {
					prev = curr;
					curr = curr->next;
				}
				prev->next = curr->next;
			}
			else {
				cout << "Out of range" << endl;			
			}
		}
	}
}

int LinkedList::search(int value) {
	Node* temp = head;
	int index = -1;
	int counter = 0;
	
	while (temp->next != NULL) {
		if (temp->value == value) {
			index = counter;
			return index;		
		} else {
			counter++;
			temp = temp->next;		
		}	
	}
	return index;
}


int LinkedList::findAt(int pos) {
	Node* temp = head;
	if (pos >= getSize()) {
		cout << "Out of range" << endl;
		return -1;	
	}
	for (int i = 0; i < pos; i++) {
		temp = temp->next;	
	}
	return temp->value;
}

void LinkedList::print() {
	// Iterate through list and print out each one
	Node* temp = head;
	cout << "Head->"<<head->value<<"->";
	while (temp->next != NULL) {
		temp = temp->next;
		cout << temp->value << "->";
	}
	cout << "NULL" << endl;
}

void LinkedList::updateAt(int newValue, int pos) {
	Node* temp = head;
	int posCounter = 0;
	
	while (temp->next != NULL) {
		if (posCounter == pos) {
			temp->value = newValue;
			return;
		}
		else {
			temp = temp->next;
			posCounter++;		
		}	
	}
	if (pos>posCounter) {
		cout << "Index " << pos << " is out of range." << endl;	
	}
}



















