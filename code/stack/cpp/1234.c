#include <stdio.h>
#include "Headers/Stack.h"

Stack::Stack(){ 
	start=NULL; 
}

Stack::~Stack(){
	List_of_Return_Addresses *p1=start;
	List_of_Return_Addresses *p2;
	while (p1!=NULL){
		p2=p1->pointer;
		delete p1;
		p1=p2;
	}
}

void Stack::Push(const int a){
	if (start==NULL){
		start=new List_of_Return_Addresses;
		start->address=a;
		start->pointer=NULL;
		return;
	}
	List_of_Return_Addresses* p=start;
	while(p->pointer!=NULL){
		p=p->pointer;
	}
	p->pointer=new List_of_Return_Addresses;
	p=p->pointer;
	p->address=a;
	p->pointer=NULL;
	return;
}

void Stack::Pop(int & a){
	if (start==NULL){
		//printf("Stack is empty! Don't know where to go!\n");
		//exit(0);
		//exit(33);
		a=-1;
		return; 
	}
	List_of_Return_Addresses* p=start;
	List_of_Return_Addresses* p2=start;
	int kol=0;
	while(p->pointer!=NULL){
		p2=p;
		p=p->pointer;
		kol++;
	}
	a=p->address;
	delete p;
	if (kol==0)
		start=NULL;
	else
		p2->pointer=NULL;
	return;
}

void Stack::Print(){
	List_of_Return_Addresses* p=start;
	while (p!=NULL){
		//printf("Address=%d\n", p->address);
		p=p->pointer;
	}
}

