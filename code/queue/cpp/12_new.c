#include <stdio.h>

typedef char ElementType;

struct QueueElement
{
	ElementType value;
	QueueElement * next;
};

struct Queue
{
	QueueElement * head;
	QueueElement * tail;
	int count;
};

Queue * createQueue()
{
	Queue * result = new Queue;
	result->head = NULL;
	result->tail = NULL;
	result->count = 0;
	return result;
}

ElementType dequeue(Queue * queue)
{
	if (queue->head == NULL)
		return 0;
	else 
	{
		ElementType result = queue->head->value;
		QueueElement * temp = queue->head;
		queue->head = queue->head->next;
		queue->count--;
		delete temp;
		return result;
	}
}

void enqueue(Queue * queue, ElementType value)
{
	QueueElement * last = new QueueElement;
	last->value = value;
	last->next = NULL;
	queue->count++;
	if (queue->tail == NULL)
	{
		queue->tail = last;
		queue->head = last;
	}
	else
	{
		queue->tail->next = last;
		queue->tail = last;
	}
}

void deleteQueue(Queue * queue)
{
	QueueElement * temp = queue->head;
	while (temp != NULL)
	{
		queue->head = queue->head->next;
		delete temp;
		temp = queue->head;
	}
	delete queue;
}

QueueElement * headQ(Queue * queue)
{
	return queue->head;
}

int count(Queue * queue)
{
	return queue->count;
}