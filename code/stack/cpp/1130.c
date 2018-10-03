#include "Stack.h"

Node* createNode(char* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(data)+1);
	strcpy(newNode->data, data);
	newNode->nextNode = NULL;
	return newNode;
}

void destroyNode(Node* node) {
	free(node->data);
	free(node);
}

void createStack(LinkedListStack** stack) { //�� �������� ��������?
	//printf("%p",stack);
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->head = NULL;
	(*stack)->top = NULL;
}

void destroyStack(LinkedListStack* stack) {
	while (stack -> head != NULL) {//stack�� �ص尡 ���ϋ�����
		Node* poped = pop(stack);
		destroyNode(poped);
	}
	free(stack);
}

void push(LinkedListStack* stack, Node* node) {
	if (stack->head == NULL) {
		stack->head = node;
	}
	else {
		/*Node* current = stack->head;
		while (current->nextNode != NULL) {
			current = current->nextNode;
		}
		current->nextNode = node;*/
		stack->top->nextNode = node;
	}

	stack->top = node;
}

Node* pop(LinkedListStack* stack) {
	Node* oldTop = stack->top;
	if (stack->head == stack->top) {
		stack->head = NULL;
		stack->top = NULL;
	}
	else {
		Node* current = stack->head;
		while (current->nextNode != stack->top) {//������ ž�� ������ ����
			current = current->nextNode;
		}
		stack->top = current;
		current->nextNode = NULL;
	}
	return oldTop;
}

int getCount(LinkedListStack* stack) {
	if (stack->head == NULL) {
		return 0;
	}else{
		int count = 1;
		Node* current = stack->head;
		while (current->nextNode != NULL) {
			current = current->nextNode;
			count++;
		}
		return count;
	}
}

void showAll(LinkedListStack* stack) {
	if (stack->head != NULL) {
		Node* current = stack->head;
		while (current != NULL) {
			printf("���� : %s\n", current->data);
			current = current->nextNode;
		}
	}
}

void main() {

	Node* test;
	LinkedListStack* stack;
	createStack(&stack);

	test = createNode("1��");
	push(stack,test);
	test = createNode("2��");
	push(stack, test);
	test = createNode("3��");
	push(stack, test);
	test = createNode("4��");
	push(stack, test);
	test = createNode("5��");
	push(stack, test);
	test = createNode("6��");
	push(stack, test);
	showAll(stack);
	destroyStack(stack);
}