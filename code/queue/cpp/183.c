#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>
#include "node.h"

using namespace std;

class queuetype
{
	public:
		queuetype();
		~queuetype();
		void enqueue(const int&,const int&);
		void dequeue(int&,int&);
		void dequeue();
		bool isFull();
		bool isEmpty();
		void makeEmpty();

	private:
		nodetype* qFront;
		nodetype* qRear;
};
//------------------------------------------------------------------------------
queuetype::queuetype()
{
	qFront = NULL;
	qRear  = NULL;
}
//------------------------------------------------------------------------------
void queuetype::enqueue(const int& enqi,const int& enqj)
{
	nodetype* newnode;
	newnode = new nodetype;
	newnode->i = enqi;
	newnode->j = enqj;
	newnode->next = NULL;

	if(qRear == NULL)
	{
		qFront = newnode;
	}
	else
		qRear->next = newnode;
	
	qRear = newnode;
}
//------------------------------------------------------------------------------
void queuetype::dequeue(int& deqi, int& deqj)
{
	nodetype* temp;

	temp = qFront;
	deqi = qFront->i;
	deqj = qFront->j;
	qFront = qFront->next;
	if(qFront == NULL)
	{
		qRear = NULL;
	}
	delete temp;
}
//------------------------------------------------------------------------------
void queuetype::makeEmpty()
{
	nodetype* temp;

	while(qFront !=NULL)
	{
		temp = qFront;
		qFront = qFront->next;
		delete temp;
	}

	qRear = NULL;
}
//------------------------------------------------------------------------------
bool queuetype::isEmpty()
{
	return(qFront==NULL);
}
//------------------------------------------------------------------------------
bool queuetype::isFull()
{
	nodetype* temp;
	temp = new nodetype;
	if(temp == NULL)
	{
		return true;
	}
	else
	{
		delete temp;
		return false;
	}
}
//------------------------------------------------------------------------------
void queuetype::dequeue()
{
	nodetype* temp;

	temp = qFront;
	//deqi = qFront->i;
	//deqj = qFront->j;
	qFront = qFront->next;
	if(qFront == NULL)
	{
		qRear = NULL;
	}
	delete temp;
}
//------------------------------------------------------------------------------
queuetype::~queuetype()
{
	makeEmpty();
}
#endif
