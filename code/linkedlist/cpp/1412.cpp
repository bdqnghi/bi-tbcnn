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

template <typename T>
Node<T>::Node()
{

}

template <typename T>
Node<T>::~Node()
{

}

template <typename T>
Node<T>::Node(T* data)
{
	SetPrev(NULL);
	SetNext(NULL);
	SetData(data);
}

template <typename T>
void Node<T>::SetData(T* data)
{
	this->data = data;
}

template <typename T>
void Node<T>::SetPrev(Node<T>* nd)
{
	this->prev = nd;
}

template <typename T>
void Node<T>::SetNext(Node<T>* nd)
{
	this->next = nd;
}

template <typename T>
T* Node<T>::GetData()
{
	return this->data;
}

template <typename T>
Node<T>* Node<T>::GetPrev()
{
	return this->prev;
}

template <typename T>
Node<T>* Node<T>::GetNext()
{
	return this->next;
}

template <typename T>
LinkedList<T>::LinkedList()
{
	list_size = 0;
	SetHead(NULL);
	SetTail(NULL);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	if(list_size != 0)
		RemoveAllLinkedList();
}

template <typename T>
void LinkedList<T>::SetHead(Node<T>* nd)
{
	this->head = nd;
}

template <typename T>
void LinkedList<T>::SetTail(Node<T>* nd)
{
	this->tail = nd;
}

template <typename T>
Node<T>* LinkedList<T>::GetHead()
{
	return this->head;
}

template <typename T>
Node<T>* LinkedList<T>::GetTail()
{
	return this->tail;
}

template <typename T>
void LinkedList<T>::AddLinkedList(T* data)
{
	Node<T>* nd = new Node<T>(data);

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

template <typename T>
void LinkedList<T>::RemoveLinkedList(int position)
{
	if(position < 0 || position > list_size)
		cout << "Invalid Value" << endl;

	Node<T>* tempNode = GetHead();
	for(int i=0; i<list_size; i++)
	{
		if(i == position){
			if(i==0)
				SetHead(tempNode->GetNext());
			else if(tempNode->GetNext() == NULL){
				tempNode->GetPrev()->SetNext(tempNode->GetNext());
			}
			else{
				tempNode->GetPrev()->SetNext(tempNode->GetNext());
			}
			delete tempNode;
			list_size--;
			break;
		}
		tempNode = tempNode->GetNext();
	}
}

template <typename T>
void LinkedList<T>::RemoveAllLinkedList(void)
{
	for(int i=0; i<list_size; i++)
	{
		RemoveLinkedList(i);
	}
	list_size=0;
}

template <typename T>
int LinkedList<T>::GetLinkedListSize(void)
{
	return list_size;
}

template <typename T>
T* LinkedList<T>::GetLinkedListData(int position)
{
	return GetLinkedList(position)->GetData();
}

template <typename T>
Node<T>* LinkedList<T>::GetLinkedList(int position)
{
	Node<T>* tempNode = GetHead();
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

template <typename T>
void LinkedList<T>::ShowAllData()
{
	for(int i=0; i<list_size; i++)
	{
		cout << "Data[" << i << "] = " << GetLinkedListData(i) << endl;
	}
}

int main()
{
	LinkedList<char> list;

	char* str = "Kim young min";

	list.AddLinkedList(str);
	char* str1 = (char*)list.GetLinkedListData(0);

	cout << str1 << endl;

//	LinkedList<int> list_int;
//	list_int.AddLinkedList(10);

	return 0;
}


