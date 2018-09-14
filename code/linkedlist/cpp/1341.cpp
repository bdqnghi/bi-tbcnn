#include "LinkedList.hpp"
LinkedList::LinkedList(){
	head = NULL;
	node = NULL;
	_size = 0;
}

LinkedList::~LinkedList(){
 	clear()
}

void LinkedList::add(E e){
	if(tail == NULL){
		head = new node(e);
		tail = head;
	}else{
		tail = new node(e,NULL, tail);
		(tail->prev)->next = tail;
	}
	_size++;
}
void LinkedList::clear(void){
 	node* todelNode = head;
 	while(todelNode != NULL){
 		node* delNode = todelNode;
 		todelNode = todelNode->next;
 		delete delNode;
 	}
 	head = NULL;
 	tail = NULL;
 	_size = 0;
}

bool LinkedList::contain(E e);
bool LinkedList::isEmpty(void){return !_size;}
void LinkedList::remove(E e);

E& LinkedList::operator[](int index){
	return get(index);
}

E& LinkedList::get(int index){
	node *seaNode = head;
	int pos = 0;
	while(seaNode != NULL){
		if(pos == index)return seaNode->data;
		seaNode = seaNode->next;
		pos++;
	}
}

int LinkedList::indexOf(E element){
	node *seaNode = head;
	int pos = 0;
	while(seaNode != NULL){
		if(seaNode->data == element)return pos;
		seaNode = seaNode->next;
		pos++;
	}
	return -1;
}
void LinkedList::sort(void);
int LinkedList::size(void){return _size;}
