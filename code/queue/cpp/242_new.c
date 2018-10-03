#include "stdafx.h"
#include "App.h"
#include <ostream>
#include <iostream>
#include "Queue.h"

int main()
{
	std::cout << "Hello world" << std::endl;
	Queue<int> queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);

	queue.Dequeue();
	queue.Dequeue();
	queue.Dequeue();
	queue.Print();

	queue.Enqueue(6);
	queue.Print();

	queue.Enqueue(7);
	queue.Enqueue(8);
	queue.Enqueue(9);
	queue.Enqueue(10);
	queue.Enqueue(11);
	queue.Enqueue(12);
	queue.Enqueue(13);
	queue.Enqueue(14);
	queue.Enqueue(15);

	queue.Print();

	queue.Dequeue();

	queue.Dequeue();
	queue.Enqueue(16);

	queue.Print();

	return 0;
}
