#include "Queue.h"


CQueue::CQueue(void)
{
}

CQueue::~CQueue(void)
{
}

void CQueue::push(int value_)
{
	if (head != nullptr)
	{
		Container* tmp = new Container(value_, nullptr);
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		head = new Container(value_, nullptr);
		tail = head;
	}
}

int CQueue::pop()
{
	int response;
	if (head != nullptr)
	{
		response = head->value;
		Container* tmp = head;
		head = head->next;
		delete tmp;
	}
	return response;
}

bool CQueue::empty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}