/*
 * linkedlist.cpp
 *
 *  Created on: Sep 27, 2011
 *      Author: ymkim
 */

#include <iostream>
#include "linkedlist.h"

using namespace std;

#define Q_ cout << "LINE : " << __LINE__ << endl;

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

Node* LinkedList::GetHead()
{
	return this->head;
}

Node* LinkedList::GetTail()
{
	return this->tail;
}

int LinkedList::GetLastIndex()
{
	return GetLinkedListSize()-1;
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
	int list_cnt = GetLinkedListSize();
	Node* tempNode = GetHead();
	if(position < 0 || position > list_cnt)
		cout << "Invalid Value" << endl;
	for(int i=0; i<list_cnt; i++)
	{
		if(i == position){
			if(i == 0){
				SetHead(tempNode->GetNext());
			}
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
	int list_cnt = GetLinkedListSize();
	for(int i=0; i<list_cnt; i++)
	{
		RemoveLinkedList(0);
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
	while(tempNode)
	{
		cout << "Data[" << i << "] = " << (char*)tempNode->GetData() << endl;
		i++;
		tempNode = tempNode->GetNext();
	}
	cout << "=========================" << endl << endl;
}

int main()
{
	LinkedList* list = new LinkedList;

	char* str1 = "str1";
	char* str2 = "str2";
	char* str3 = "str3";

	list->AddLinkedList(str1);
	list->ShowAllData();
	list->AddLinkedList(str2);
	list->ShowAllData();
	list->RemoveLinkedList(list->GetLinkedListSize()-1);
	list->ShowAllData();

	list->AddLinkedList(str2);
	list->ShowAllData();

	delete list;
	return 0;
}


