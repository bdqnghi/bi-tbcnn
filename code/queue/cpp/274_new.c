#include"Queue.h"
Queue::Queue(){
	size=0;
}

Queue::~Queue(){
	makeitempty();
}

Queue::Queue(const Queue& queue){
	copy(queue);
}

Queue& Queue::operator = (const Queue& queue){
	if (this!=&queue){
		makeitempty();
		copy(queue);
	}
	return *this;
}

void Queue::putin(const Stack& stack){
	los.addtobegin(stack);
	size++;
}

void Queue::takeout(){
	los.toend();
	los.erase();
	size--;
}

void Queue::makeitempty(){
	los.makeitempty();
	size=0;
}

bool Queue::isempty()const{
	return los.isempty();
}

Stack& Queue:: viewlast(){
	los.toend();
	return los.getcur();
}

void Queue::copy(const Queue& queue){
	size=queue.size;
	los=queue.los;
}