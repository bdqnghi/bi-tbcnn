#include "head.h"

void init(Stack &stack){
	stack.base = stack.top = (ElemType *)malloc(INITSIZE * sizeof(ElemType));
	stack.stacksize = INITSIZE;
}


void push(Stack &stack,ElemType data){
	if(stack.top - stack.base >= stack.stacksize){
		stack.base = (ElemType *)realloc(stack.base,(stack.stacksize + INCREMENT) * sizeof(ElemType));
		stack.top = stack.base + stack.stacksize;
		stack.stacksize += INCREMENT;
	}
	*stack.top++ = data;
}


void pop(Stack &stack,ElemType &data){
	if(stack.base == stack.top){
		cout << "ջΪ��\n";
		return;
	}
	data = *(--stack.top);
}


ElemType GetTop(Stack &stack){
	return *(stack.top - 1);
}

bool empty(Stack &stack){
	return stack.base == stack.top;
}
