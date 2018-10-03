/* sinple stack */

#include <iostream>
#include "stack.h"

void init_stack(Stack *stack) {
	stack->size = 0;
	stack->top = NULL;
}

void push(Stack *stack, int value) {
	StackNode *t = (StackNode*)malloc(sizeof(StackNode));
	t->next = stack->top;
	t->value = value;

	if (stack->size == 0) t->min = value;
	else t->min = (value < stack->top->min ? value : stack->top->min);

	stack->top = t;
	stack->size++;
}

int pop(Stack *stack) {
	if (stack->top == NULL) return -1;
	if (stack->size == NULL) return -1;
	int retval = stack->top->value;
	StackNode *t = stack->top;
	stack->top = stack->top->next;
	free(t);
	stack->size--;
	return retval;
}

int peek(Stack *stack) {
	if (stack->top == NULL) return -1;
	if (stack->size == NULL) return -1;
	return (stack->top->value);
}

void free_stack(Stack *stack) {
	for (int i = 0; i < stack->size; i++) {
		pop(stack);
	}
	stack->top = NULL;
}

int stack_min(Stack *stack) {
	return (stack->top->min);
}