
#ifndef NULL
#define NULL 0
#endif

#include "atomics.h"
#include <stdlib.h>
#include <unistd.h>

template<typename obj>
class stack{
private:
	class node{
	public:
		obj data;
		node* next;
		node(const obj& d):data(d),next(NULL){ }
	};
	node *head;
public:
	stack(void){
		head=NULL;
	}
	
	obj top(void){
		return head->data;
	}
	
	int size(void) const {
		volatile node* ptr = head;
		int counter = 0;
		while(ptr!=NULL){
			counter++;
			ptr = ptr->next;
		}
		return counter;
	}
	void clear(void){
		volatile node* ptr = head,*next;
		while(ptr!=NULL){
			next=ptr->next;
			delete ptr;
			ptr = next;
		}
		head = NULL;
		return ;
	}
	bool empty(void) const{
		return head==NULL;
	}
	
	void pop(void) {
		int backoff = 2;
		while(1) {
			const node* const old_head = head;
			if (!old_head){
				head = NULL;
				return;
			}
			if (compare_and_set(&head, old_head, old_head->next)) {
				delete old_head;
				return;
			}else{
				usleep(rand()&(backoff-1));
				backoff <<= 1;
			}
		}
	}
	void atomic_pop(obj* target) {
		int backoff = 2;
		while(1) {
			const node* const old_head = head;
			if (!old_head){
				head = NULL;
				return;
			}
			if (compare_and_set(&head, old_head, old_head->next)) {
				*target = old_head->data;
				delete old_head;
				return;
			}else{
				usleep(rand()&(backoff-1));
				backoff <<= 1;
			}
		}
	}
	
	void push(const obj& element) {
		volatile node *newnode = new node(element);
		volatile node *old_head;
		while(1) {
			old_head = head;
			newnode->next = const_cast<node*>(old_head);
			
			if (__sync_bool_compare_and_swap(&head, old_head , newnode)) {
				return;
			}
		}
	}
	
	~stack(){
		while(size() > 0){
			pop();
		}
	}
};


#include "thread_pool.hpp"
#include "gettime.h"
#include <stdio.h>
#define MAX 20000000

stack<int> st;


void popper(int id){
	for(int i=0;i<MAX/4;i++){
		int data;
		st.atomic_pop(&data);
		//printf("%d:%d,",id,data);
	}
}

int main(void){
	for(int i=0;i<MAX;i++){
		st.push(i);
	}
	
	threadpool<int> threads(4);
	printf("%d items push and pop\n ",MAX);
	
	double start = gettime();
	
	threads.run(popper,1);
	threads.run(popper,2);
	threads.run(popper,3);
	threads.run(popper,4);
	
	threads.wait();
	double end = gettime();
	
	
	printf("\n time:%f\n ",end-start);
}
