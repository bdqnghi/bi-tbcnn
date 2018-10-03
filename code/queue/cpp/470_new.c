/*
Eugene Auduchinok (c) 2013

Test 1.1.2
Increasing Spaces
*/

#include <utility>
#include <cstring>
#include "queue.h"
using namespace queue;

Queue *queue::createQueue()
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

		delete[] toDelete->string;
		delete toDelete;
	}

	delete queue;
}

void queue::push(Queue *queue, char *string)
{
	QueueElement *toAdd = new QueueElement;
	toAdd->string = string;
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

	(queue->words)++;
	(queue->length) += strlen(string);
}

void queue::pop(Queue *queue)
{
	if (isEmpty(queue))
	{
		return;
	}

	QueueElement *toDelete = queue->front;
	delete[] toDelete->string;
	queue->front = toDelete->next;

	delete toDelete;
}

char *queue::front(Queue *queue)
{
	return queue->front->string;
}

bool queue::isEmpty(Queue *queue)
{
	return queue->front == nullptr;
}