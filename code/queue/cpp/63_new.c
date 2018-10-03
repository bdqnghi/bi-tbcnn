#include"QueueSeq.h"
#include<iostream>
#include<climits>

using queueseq::Queue;
using std::cout;
using std::endl;


int main()
{
	Queue<double, 3> queue;
	queue.enQueue(2.0);
	queue.enQueue(3.0);
	queue.enQueue(5.0);
	queue.enQueue(2.2);
	queue.enQueue(2.5);
	queue.enQueue(2.9);

	if (queue.top() != INT_MIN)
	{
		cout << queue.top() <<std::endl;
	}
	queue.deQueue();
	if (queue.top() != INT_MIN)
	{
		cout << queue.top() << std::endl;
	}
	queue.deQueue();
	if (queue.top() != INT_MIN)
	{
		cout << queue.top() << std::endl;
	}
	queue.deQueue();
	if (queue.top() != INT_MIN)
	{
		cout << queue.top() << std::endl;
	}
	queue.deQueue();

	queue.enQueue(2.2);
	queue.enQueue(2.5);
	queue.enQueue(2.9);
	if (queue.top() != INT_MIN)
	{
		cout << queue.top() << std::endl;
	}
	queue.deQueue();
	if (queue.top() != INT_MIN)
	{
		cout << queue.top() << std::endl;
	}
	queue.deQueue();
	if (queue.top() != INT_MIN)
	{
		cout << queue.top() << std::endl;
	}
	queue.deQueue();
	if (queue.top() != INT_MIN)
	{
		cout << queue.top() << std::endl;
	}
	queue.deQueue();

 	return 0;

}
