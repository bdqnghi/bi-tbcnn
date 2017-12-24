//#include "stack.h"

Node* createNode(double data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->nextNode = NULL;
	return newNode;
}; 

void createStack(LinkedListStack** stack) {
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->head = NULL;
	(*stack)->top = NULL;
};

void destroyStack(LinkedListStack* stack) {
	int cnt = getCount(stack);
	for (int i = 0; i < cnt; i++) {
		Node* current = stack->head;
		if (current->nextNode == NULL) {
			free(stack->head);
			stack->head = NULL;
		}
		else {
			while (current->nextNode->nextNode != NULL) {
				current = current->nextNode;
			}
			free(current->nextNode);
			current->nextNode = NULL;
		}
	}
	free(stack);
};

Node* pop(LinkedListStack* stack) {
	Node* topNode = stack->top;
	if (stack->head == stack->top) {
		stack->head = NULL;
		stack->top = NULL;
	}
	else {
		Node* current = stack->head;
		while (current->nextNode->nextNode != NULL) {
			current = current->nextNode;
		}
		stack->top = current;
		current->nextNode = NULL;
	}
	return topNode;
};

void push(LinkedListStack* stack, Node* newNode) {
	
	if (stack->head == NULL) {
		stack->head = newNode;
		stack->top = newNode;
	}
	else {
		stack		->top->nextNode = newNode;
		stack->top = newNode;
	}
};

int getCount(LinkedListStack* stack) {
	int cnt = 1;
	Node* current = stack->head;
	while (current->nextNode != NULL) {
		current = current->nextNode;
		cnt++;
	}
	return cnt;
}

