#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Link{
	int data;
	struct Link *next;
};
struct Stack{
	struct Link *head;
	int size;
};
void StackInit(struct Stack *stack){
	stack->head=NULL;
	stack->size=0;
}
void StackPush(struct Stack *stack,const int data){
	struct Link *node;
	node = (struct Link*)malloc(sizeof(struct Link));
	assert(node!=NULL);
	node->data=data;
	node->next=stack->head;
	stack->head=node;
	++stack->size;
}
int StackEmpty(struct Stack *stack){
	return stack->size==0;
}
int StackPop(struct Stack *stack,int *data){
	if(StackEmpty(stack)){
		return 0;
	}
	struct Link *tmp = stack->head;
	*data=stack->head->data;
	stack->head=stack->head->next;
	free (tmp);
	--stack->size;
	return 1;
}
void StackCleanup(struct Stack *stack){
		struct Link *tmp;
		while(stack->head){
			tmp=stack->head;
			stack->head=stack->head->next;
			free (tmp);
		}
	stack->size=0;
}
int main(void){
	struct Stack stack;
	StackInit(&stack);
	int i;
	for(i=0;i<5;i++){
		StackPush(&stack,i);
	}
	while(!StackEmpty(&stack)){
		StackPop(&stack,&i);
		printf("%d ",i);
	}
	printf("\n");
	return 0;
}