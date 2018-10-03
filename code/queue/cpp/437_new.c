#include "LinkedQueue.h"

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->nextNode = NULL;
	return newNode;
};

void createQueue(LinkedQueue** queue) {
	(*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*queue)->count = 0;
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
};

void destroyQueue(LinkedQueue* queue) {
	Node* pop = deQueue(queue);
	while (pop != NULL) {
		free(pop);
		pop = deQueue(queue);
	}
	free(queue);
};

void enQueue(LinkedQueue* queue, int data) {
	if (queue->front == NULL) {
		Node* newNode = createNode(data);
		queue->front = newNode;
		queue->rear = newNode;
		queue->count++;
	}
	else {
		Node* newNode = createNode(data);
		queue->rear->nextNode = newNode;
		queue->rear = newNode;
		queue->count++;
	}
};

Node* deQueue(LinkedQueue* queue) {
	if (queue->front == NULL) {
		return NULL;
	}
	Node* pop = queue->front;
	if (queue->front->nextNode == NULL) {//�Ѱ��ΰ��
		queue->front = NULL;
		queue->rear = NULL;
	}
	else {
		queue->front =  queue->front->nextNode;
	}
	queue->count--;
	return pop;
};

void showAll(LinkedQueue* queue) {
	Node* current = queue->front;
	printf("%d\n", current->data);
	while (current->nextNode != NULL) {
		current = current->nextNode;
		printf("%d\n", current->data);
	}
};

void main() {

	LinkedQueue* queue;
	createQueue(&queue);
	for (int i = 0; i < 20; i++) {
		enQueue(queue, i);
	}

	free(deQueue(queue));
	free(deQueue(queue));
	free(deQueue(queue));
	free(deQueue(queue));
	free(deQueue(queue));
	free(deQueue(queue));
	free(deQueue(queue));

	enQueue(queue, 200);
	showAll(queue);

	destroyQueue(queue);
}