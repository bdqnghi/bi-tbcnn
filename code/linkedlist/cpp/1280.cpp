#include <cstdlib>
#include <iostream>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
	size = 0;
}

LinkedList::LinkedList(const LinkedList &orig)
{
	head = NULL;
	size = 0;
	
	Node *current = orig.head;

	while(current)
	{ 
		appendNode(current->data); 
		current = current->next; 
	}
}

LinkedList::~LinkedList()
{
	emptyList();
}


void LinkedList::appendNode(const int d)
{
	Node *newNode = new Node;
	Node *current = head;
	
	newNode->data = d;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(!head)
		head = newNode;
	else
	{
		while(current->next)
			current = current->next;
		
		current->next = newNode;
		newNode->prev = current;
	}

	size++;
}

bool LinkedList::insertNode(const int d, const int i)
{
	if(i > size)
	{
		return false;
	}
	
	Node *current = head;
	Node *newNode = new Node;

	newNode->data = d;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(i == 0)
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else
	{
		for(int pos = 0; pos < i; pos++)
		{
			current = current->next;
		}

		newNode->prev = current->prev;
		newNode->next = current;

		current->prev->next = newNode;
		current->prev = newNode;
	}
	
	size++;
	return true;
}

bool LinkedList::deleteNode(const int i)
{
	Node *current = head;
	
	if(current == NULL)
	{
		return false;
	}
	
	if(i > size)
	{
		return false;
	}
	
	if(i == 0)
	{
		
		head = current->next;
		head->prev = NULL;
	}
	else
	{
		for(int pos = 0; pos < i; pos++)
		{
			current = current->next;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	
	delete current;
	size--;
	
	return true;
}

void LinkedList::emptyList()
{
	Node *nodePtr;
	Node *nextNode;

	nodePtr = head;

	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}
	
	head = NULL;
	
	size = 0;
}

void LinkedList::print()
{
	Node *current = head;

	if(!head)
	{
		cout << "List empty.";
		return;
	}
	
	while(current)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

void LinkedList::printReverse(){
	Node *current = head;

	if(!head){
		cout << "List empty.";
		return;
	}
	
	while(current->next)
	{
		current = current->next;
	}
	
	while(current)
	{
		cout << current->data << endl;
		current = current->prev;
	}
}

void LinkedList::printOne(const int i)
{
	Node *current = head;
	
	if(i > size)
	{
		cout << "Given index is larger than list size." << endl;
		return;
	}
	
	for(int a = 0; a < i; a++)
	{
		current = current->next;
	}
	
	cout << current->data << endl;
}

LinkedList LinkedList::operator=(const LinkedList &orig)
{
	if(this == &orig)
		return *this;
	
	Node *current = orig.head;

	emptyList();
	
	while(current)
	{
		appendNode(current->data);
		current = current->next;
	}
	
	return *this;
}

int LinkedList::operator[](int i)
{
	Node *current = head;
	
	if(i > size)
	{
		return -1;
	}
	
	for(int a = 0; a < i; a++)
	{
		current = current->next;
	}
	
	return current->data;
}
