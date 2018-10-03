#include "Queue.h"

void createQueue(CircularQueue** queue, int capacity) {

	(*queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	
	//�Էµ� capacity + 1 ��ŭ�� ��带 ���� ����ҿ� ����
	(*queue)->nodes = (Node*)malloc(sizeof(Node)*(capacity + 1));

	// ť�� ���� ������ ����� ����
	(*queue)->capacity = capacity;

	//���۰� ���� �ε����� 0���� ����
	(*queue)->front = 0;
	(*queue)->rear = 0;
};

void destroyQueue(CircularQueue* queue) {
	free(queue->nodes);
	free(queue);
}

void enQueue(CircularQueue* queue, ElementType data) {
	int pos = 0;

	if (queue->rear == queue->capacity) {// �Ĵܰ� ���뷮�� ������? �������� �ֳ�?
		//�ƹ�ư �Ĵ��� ���� ���������Ƿ� �Ĵ��� �ٽ� ���������� �Ȱ��ش�
		pos = queue->rear;
		queue->rear = 0;
	}
	else {
		pos = queue->rear++;
	}
	queue->nodes[pos].data = data;
};
ElementType deQueue(CircularQueue* queue) {
	//���ܿ��� �ϳ�����
	int pos = queue->front;
	if (queue->front == queue->capacity)
		queue->front = 0;
	else
		queue->front++;
	return queue->nodes[pos].data;
}

int isEmpty(CircularQueue* queue) {
	return (queue->front == queue->rear);
}

int isFull(CircularQueue* queue) {
	if (queue->front < queue->rear) {
		return(queue->front) - (queue->rear) == queue->capacity;
	}
	else {
		return (queue->rear + 1) == queue->front;
	}
}

int getSize(CircularQueue* queue) {
	if (queue->front < queue->rear) {
		return queue->rear - queue->front;
	}else{
		return queue->rear + (queue->capacity - queue->front) + 1;
	}
}

void showAll(CircularQueue* queue) {
	for (int i = 0; i < queue->capacity; i++) {
		printf("%d\n", queue->nodes[i].data);
	}
};
void main() {

	CircularQueue* queue;
	createQueue(&queue,10);
	for (int i = 0; i < 8; i++) {
		enQueue(queue, i);
	}
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);

	showAll(queue);

	printf("������� %d\n", getSize(queue));

	destroyQueue(queue);

}