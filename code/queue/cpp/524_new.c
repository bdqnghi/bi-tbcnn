#include "Queue.h"

void Queue::push(element inData, unsigned int p)
{
	if(_queue._size == 0)
	{
		_queue.insert(inData);
		_queue._curr->setPriority(p);
	}
	else
		{
			_queue.head();
			while ( (_queue._curr->getPriority() >= p) )
			{
				if(_queue._curr == _queue._tail)
					break;
				_queue.next();
			}

			if ( (_queue._curr == _queue._head) && (_queue._head->getPriority() < p) )
			{
				_queue.insertBefore(inData);
				_queue._head->setPriority(p);
			}
			else
			{
				_queue.insert(inData);
				_queue._curr->setPriority(p);
			}
		}
}

void Queue::pop()
{
	_queue.head();
	_queue.remove();
}
void Queue::print()
{
	_queue.print();
}