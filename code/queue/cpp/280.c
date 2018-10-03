//Brett Lindenberg
//7836-3841
//COP3530 Assignment 4
//Queue.cpp file

/*
#include <stdio.h>
#include <ostream>
#include <sstream>
#include "Queue.h"
#include <cstddef>


using namespace std;

//template <class T>
Queue::Queue() 
{
	first,last=NULL;
}



//template <class T>
bool Queue::empty()
{
	return (first==NULL && last==NULL);
}

//template <class T>
int Queue::size()
{
	int count=0;
	tempNode = first;
	while (tempNode->next !=NULL)
	{
		count++;
		tempNode = tempNode->next;
	}

	return count;
}

//template <class T>
int& Queue::back() 
{
	return first-> data;
}

//template <class T>
int& Queue::front() 
{
	return last->data;
}

//template <class T>
int Queue::pop() 
{	
	if (first!=NULL && last!=NULL)
	{
	tempNode=last;
	last = last->prev;
	last->next=NULL;
	}
	cout<<"Pop "<<tempNode->data<<endl;
	return tempNode->data;
}

//template <class T>
void Queue::push(int element) 
{
	if(first==NULL)
	{
		first=new Node(element);
		last=first;
		first->next=NULL;
		first->prev=NULL;
	} 

	else
	{
		tempNode = first;
		first = new Node(element);
		first->next = tempNode;
		tempNode->prev = first;
	}

}
/*
void Queue::show() 
{	
	if (last!=NULL)
	{	
	tempNode=first;
	cout<<"The queue is ";
	while(tempNode !=NULL)
	{	cout<<(tempNode->data)<<" ";
		tempNode=tempNode->next;
	}
		
	cout<<"\n";
	}
}
*/




