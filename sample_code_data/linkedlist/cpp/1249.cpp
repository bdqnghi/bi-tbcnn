#include<iostream>
#include<cstdlib>
#include<cstdio>

//#define NODE struct node

using namespace std;

struct node {
	int data;
	struct node *next;
};

typedef struct node NODE

void display(node **start){
	NODE *temp = *start;
	while(temp){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<endl;
}

int push(NODE **start, int data){
	NODE *newElem;
	//newElem = (NODE*) malloc(sizeof(NODE));
	newElem = new (NODE);
	if(!newElem)
		return 0;
	if(*start == NULL){
		newElem->data = data;
		newElem->next = NULL;
		(*start) = newElem;
	}
	else{
		newElem->data = data;
		newElem->next = *start;
		*start = newElem;
	}
	return 1;
}

int pop(NODE **start){
	if(!*start){
		cout<<"empty stack\n";
		return -1;
	}
	NODE *newElem;
	newElem = new NODE;
	newElem = *start;
	//printf("%d %d %d %d\n",start,*start,**start,newElem);
	*start = (*start)->next;
	int data = newElem->data;
	free(newElem);
}

void rev(NODE **start){
	NODE *temp,*head,*tail;
	head = temp = *start;
	while(temp->next != NULL)
		temp = temp->next;
	tail = temp;
	
	if(head == tail)
		return;

	tail->next = head;
	head = head->next;
	tail->next->next = NULL;
		
	while(head != tail){
		temp = head;
		head = head->next;
		temp->next = tail->next;
		tail->next = temp;
	}

	*start = tail;
}

int main(){
	node *start;
	start = (NODE*) malloc(sizeof(NODE));
	start = NULL;
	int res = push(&start,10);
	display(&start);
	res = push(&start,12);
	res = push(&start,11);
	res = push(&start,14);
	display(&start);
	//res = pop(&start);
	//display(&start);
	rev(&start);
	display(&start)	;
}
