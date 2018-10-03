#include"stack.h"


void stackInit(stackI *stackP, int maxSize)
{
	stackElementsI *newContents;

	/*Allocate memory in heap to hold the contents*/
	newContents = (stackElementsI*) malloc(sizeof(stackElementsI)*maxSize);

	if(newContents == NULL)
	{
		fprintf(stderr,"Insufficiant memory to allocate stack");
		exit(1);
	}

	stackP->contents = newContents;
	stackP->maxSize  = maxSize;
	stackP->top      = -1;//empty 
}

void StackDestroy(stackI *stackP)
{
	free(stackP->contents);
	stackP->maxSize = 0;
	stackP->top     = -1;
}

int StackIsEmpty(stackI *stackP)
{
	return stackP->top < 0;
}

int StackIsFull(stackI *stackP)
{
	return stackP->top >= stackP->maxSize-1;
}

void StackPush(stackI *stackP,stackElementsI element)
{
	if(StackIsFull(stackP))
	{
		fprintf(stderr,"Stack is full.\n");
		exit(1);
	}

	stackP->contents[++stackP->top] = element;
}

int StackPop(stackI *stackP)
{
	if(StackIsEmpty(stackP))
	{
		fprintf(stderr,"Stack is Empty.\n");
		exit(1);
	}
	return stackP->contents[stackP->top--];
}