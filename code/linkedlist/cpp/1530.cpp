/*
 * linkedlist.cpp
 *
 *  Created on: Sep 27, 2011
 *      Author: ymkim
 */

#include <iostream>
#include "linkedlist.h"

using namespace std;

Node::Node()
{

}

Node::~Node()
{

}

Node::Node(void* data)
{
	SetPrev(NULL);
	SetNext(NULL);
	SetData(data);
}

void Node::SetData(void* data)
{
	this->data = data;
}

void Node::SetPrev(Node* nd)
{
	this->prev = nd;
}

void Node::SetNext(Node* nd)
{
	this->next = nd;
}

void* Node::GetData()
{
	return this->data;
}

Node* Node::GetPrev()
{
	return this->prev;
}

Node* Node::GetNext()
{
	return this->next;
}

LinkedList::LinkedList()
{
	list_size = 0;
	SetHead(NULL);
	SetTail(NULL);
}

LinkedList::~LinkedList()
{
	if(list_size != 0)
		RemoveAllLinkedList();
}

void LinkedList::SetHead(Node* nd)
{
	this->head = nd;
}

void LinkedList::SetTail(Node* nd)
{
	this->tail = nd;
}

int LinkedList::GetLastIndex()
{
	return GetLinkedListSize()-1;
}

Node* LinkedList::GetHead()
{
	return this->head;
}

Node* LinkedList::GetTail()
{
	return this->tail;
}

void LinkedList::AddLinkedList(void* data)
{
	Node* nd = new Node(data);

	if(list_size == 0){
		nd->SetPrev(NULL);
		SetHead(nd);
	}
	else{
		GetTail()->SetNext(nd);
		nd->SetPrev(GetTail());
	}

	SetTail(nd);
	list_size++;
}

void LinkedList::RemoveLinkedList(int position)
{
	if(position < 0 || position > list_size)
		cout << "Invalid Value" << endl;

	Node* tempNode = GetHead();
	for(int i=0; i<list_size; i++)
	{
		if(i == position){
			if(i == 0)
				SetHead(tempNode->GetNext());
			else{
				tempNode->GetPrev()->SetNext(tempNode->GetNext());
			}

			if(i == GetLastIndex()){
				SetTail(tempNode->GetPrev());
			}

			delete tempNode;
			list_size--;
			break;
		}
		tempNode = tempNode->GetNext();
	}
}

void LinkedList::RemoveAllLinkedList(void)
{
	for(int i=0; i<list_size; i++)
	{
		RemoveLinkedList(i);
	}
	list_size=0;
}

int LinkedList::GetLinkedListSize(void)
{
	return list_size;
}

void* LinkedList::GetLinkedListData(int position)
{
	return GetLinkedList(position)->GetData();
}

Node* LinkedList::GetLinkedList(int position)
{
	Node* tempNode = GetHead();
	if(position < 0 || position > list_size)
		return NULL;

	for(int i=0; i<list_size; i++)
	{
		if(i == position){
			return tempNode;
		}
		tempNode = tempNode->GetNext();
	}

	cout << "Invalid value : " << position << endl;
	return NULL;
}

void LinkedList::ShowAllData()
{
	cout << "===== Show All Data =====" << endl;

	int i=0;
	Node* tempNode = GetHead();
//	for(int i=0; i<GetLinkedListSize(); i++)
	while(tempNode)
	{
		cout << "Data[" << i << "] = " << (char*)tempNode->GetData() << endl;
		i++;
		tempNode = tempNode->GetNext();
	}
	cout << "=========================" << endl;
}

#if 0
int main()
{
	LinkedList list;

	char* str = "Kim young min";

	list.AddLinkedList(str);
	char* str1 = (char*)list.GetLinkedListData(0);

	cout << str1 << endl;

	return 0;
}
#endif


