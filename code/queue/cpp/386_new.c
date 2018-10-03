#include "priqueue.hpp"
#include <stdio.h>

int main(int argc, char *argv[]) {
	PriorityQueue *queue = new PriorityQueue(10);
	queue->insert(10);
	queue->insert(8);
	queue->insert(9);
	queue->insert(1);
	queue->insert(6);
	queue->insert(4);

	printf("extract=%d\n", queue->extractmin());
	printf("extract=%d\n", queue->extractmin());
	printf("extract=%d\n", queue->extractmin());
	printf("extract=%d\n", queue->extractmin());
	printf("extract=%d\n", queue->extractmin());
	printf("extract=%d\n", queue->extractmin());
	return 0;
}
