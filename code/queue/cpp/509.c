#include <iostream>
using namespace std;

template<class T>
class Queue {
public:
	Queue(int MaxQueueSize = 10);
	
	~Queue() {
		delete []queue;
	}

	bool IsEmpty() const {
		return front == rear;
	}
	//队列数组不能满
	bool IsFull() const {
		return ((rear+1)%MaxSize == front) ? 1 : 0;
	}

	T First() const;

	T Last() const;

	Queue<T> &Add(const T &x);

	Queue<T> &Delete(T &x);
private:
	int front;
	int rear;
	int MaxSize;
	T *queue;
};

template<class T>
Queue<T>::Queue(int MaxQueueSize) {
	MaxSize = MaxQueueSize + 1;
	queue = new T[MaxSize];
	front = rear = 0;
}

template<class T> 
T Queue<T>::First() const {
	if (IsEmpty()) {
		throw OutOfBounds();
	} else {
		return queue[(front+1)%MaxSize];
	}

}

template<class T>
T Queue<T>::Last() const {
	if (IsEmpty()) {
		throw OutOfBounds();
	} else {
		return queue[rear];
	}
}

template<class T>
Queue<T> &Queue<T>::Add(const T &x) {
	if(IsFull()) {
		throw NoMem();
	} else {
		rear = (rear + 1) % MaxSize;
		queue[rear] = x;
		return *this;
	}
}


template<class T>
Queue<T> &Queue::Delete(T &x) {
	if (IsEmpty()) {
		throw OutOfBounds();
	} else {
		front = (front + 1) % MaxSize;
		x = queue[front];
		return *this;
	}
}