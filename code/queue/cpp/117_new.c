/*
Eugene Auduchinok (c) 2013

Test 1.1.2
Increasing Spaces
*/

#include <utility>
#include "queue.h"
using namespace queue;

Queue *queue::create()
{
	Queue *result = new Queue;
	result->front = nullptr;
	result->back = nullptr;

	return result;
}

void queue::deleteQueue(Queue *queue)
{
	QueueElement *tmp = queue->front;

	while (tmp != nullptr)
	{
		QueueElement *toDelete = tmp;
		tmp = tmp->next;

		delete toDelete;
	}

	delete queue;
}

void queue::push(Queue *queue, int value)
{
	QueueElement *toAdd = new QueueElement;
	toAdd->value = value;
	toAdd->next = nullptr;

	if (isEmpty(queue))
	{
		queue->front = toAdd;
		queue->back = toAdd;
	}
	else
	{
		queue->back->next = toAdd;
	}
	
	queue->back = toAdd;
}

void queue::pop(Queue *queue)
{
	if (isEmpty(queue))
	{
		return;
	}

	QueueElement *toDelete = queue->front;
	queue->front = toDelete->next;

	delete toDelete;
}

int queue::front(Queue *queue)
{
	return queue->front->value;
}

bool queue::isEmpty(Queue *queue)
{
	return queue->front == nullptr;
}