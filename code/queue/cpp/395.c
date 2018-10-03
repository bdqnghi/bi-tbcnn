//
// Quick Notes
// 4/5 (Trey): Created Queue.cpp file and sent to others
// for compilation/linking testing
// 4/5 (Joshua: Identified this as source of linking
// problems and had to create workaround. See Queue.h
// for more details.
//
/*
#include "Queue.h"
#include <cstddef>
template <class T>
Queue<T>::Queue()
{
	front = NULL;
	rear = NULL;
	numItems = 0;
}

template <class T>
Queue<T>::~Queue()
{
	clear();
}

template <class T> 
void Queue<T>::enqueue(T item)
{
	QueueNode *newNode = NULL;
	newNode = new QueueNode;
	newNode->value = item;
	newNode->next = NULL;

	if (isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	numItems++;
}

template <class T>
void Queue<T>::dequeue(T &item)
{
	QueueNode *temp = NULL;
	if (isEmpty())
	{

	}
	else
	{
		item = front->value;
		temp = front;
		front = front->next;
		delete temp;

		numItems--;
	}
}

template <class T> 
bool Queue<T>::isEmpty() const
{
	bool status;

	if (numItems > 0)
	{
		status = false;
	}
	else
	{
		status = true;
	}
	return status;
}

template <class T>
void Queue<T>::clear()
{
	T value;
	while (!isEmpty)
	{
		dequeue(value);
	}
}

*/