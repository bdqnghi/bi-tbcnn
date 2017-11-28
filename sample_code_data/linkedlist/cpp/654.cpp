//linkedlist.cpp
#include "std.h"

#include "employee.h"
#include "linkedlist.h"

//Node =============================================
Node::Node(Employee* _data, Node* _next, Node* _prev)
:data(_data), next(_next), prev(_prev)
{
	
}

Node::Node()
{
}


// LinkedLIst ========================================
LinkedList::LinkedList()
{
	head	= NULL;
	tail	= NULL;
	count	= 0;
}

LinkedList::~LinkedList()
{

}

bool LinkedList::insertNode(Employee* data)
{
	Node *newnode = new Node(data, NULL, NULL);	

	if( head	== NULL)
	{
		head	= newnode;
		tail	= newnode;
	}
	else
	{
		newnode->next	= head;

		head->prev      = newnode;
		head			= newnode;
	}
	++count;
	return true;
}

bool LinkedList::insertNode(int idx, Employee* data)
{
	Node *cur = retrieveNode(idx);
	if( cur != NULL)
	{
		// ��� ����
		Node *newnode = new Node(data, NULL, NULL);		//2

		// ���� ======================================
		if(cur == tail)
		{
			newnode->prev   = cur;
			cur->next		= newnode;
			tail			= newnode;
		}
		else 
		{
			newnode->next	= cur->next;
			newnode->prev   = cur;

			cur->next->prev  = newnode;
			cur->next        = newnode;			
		}
		++count;	
		return true;
	}
	else
	{
		return false;
	}
}


Employee* LinkedList::deleteNode(int idx)
{
	Node *cur = retrieveNode(idx);
	if( cur != NULL)
	{
		// ���� =====================
		Node *prev = cur->prev;

		if( cur == head)
		{
			cur->next->prev = NULL;
			head	= cur->next;
		}
		else if( cur == tail)
		{
			prev->next = NULL;
			tail	= prev;
		}
		else
		{
			prev->next = cur->next;
			cur->next->prev = prev;
		}
		Employee *pData = cur->data;
		free(cur);
		return pData;	
		//==============================
	}
	else
	{
		return NULL;
	}
}


Node* LinkedList::retrieveNode(int idx)
{
	if( idx > 0 && idx <= count)		// 1
	{
		Node *cur = head;		
		for(int i=0; i<idx-1; i++)		cur = cur->next;
		return cur;
	}
	else
		return NULL;
}

bool LinkedList::isEmpty()
{
	if(head == NULL) return true;
	else			 return false;
}


void LinkedList::display()
{
	Node *cur = head;

	while( cur != NULL)
	{
		//=================
		Employee *pData = cur->data;
		pData->printdata();
		//(cur->data)->printdata();
		//=================
		cur = cur->next;
	}
}