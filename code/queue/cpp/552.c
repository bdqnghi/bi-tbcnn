#include "Queue.h"

Queue::Queue()
{
	front = back = NULL;
}

Queue::Queue(Queue& copyFrom)
{
	cout << "oops" << endl;
	if (copyFrom.front == NULL)
		cout << "oops" << endl;
		return;
	Node *from = copyFrom.front;
	back->setNext(new Node(from->getData(), NULL));
	from = from->getNext();
	Node *to = front;
	while (from != NULL) {
		Node *temp = new Node(from->getData(), NULL);
		cout << "copy = " << temp->getData() << endl;
		to->setNext(temp);
		to = to->getNext();		//increment
		from = from->getNext();
	}
}

Queue::~Queue()
{
}

void Queue::print()
{
	Node *temp = front;
	if (front) {
		cout << "Here is the Queue:" << endl;
		while (temp->getNext()) {
			Student temp2 = temp->getData();
			cout << temp2.getID()
				<< "\t\t" << temp2.getName() << "\t\t\t" << temp2.getGPA() << endl;

			temp = temp->getNext();
		}
		Student temp2 = temp->getData();
		cout << temp2.getID()
			<< "\t\t" << temp2.getName() << "\t\t\t" << temp2.getGPA() << endl << endl;
	}
	else {
		cout << "There are no Students in the Queue!" << endl << endl;
	}

}

void Queue::enqueue(Student s)
{
	Node *temp = new Node(s, NULL);
	if (back != NULL) {
		back->setNext(temp);
		//cout << "Added the following: " << endl << s.getID() << "\t\t" << s.getName() << "\t\t\t" << s.getGPA() << endl;
	}
	back = temp;
	if (front == NULL) {
		front = temp;
		//cout << "Added the following: " << endl << s.getID() << "\t\t" << s.getName() << "\t\t\t" << s.getGPA() << endl;
	}
}

Student Queue::dequeue()
{
	if (front != NULL) {
		Student item = front->getData();
		Node *discard = front;
		front = front->getNext();
		delete discard;
		return item;
	}
	return Student();
}



//#include "Queue.h"
//
//
//template<class T>
//Queue<T>::Queue()
//{
//	front = back = NULL;
//}
//
//template<class T>
//Queue<T>::~Queue()
//{
//}
//
//template<class T>
//void Queue<T>::add(T item)
//{
//	cout << "old back = " << back << endl;
//	Node<T> *temp = new Node<T>(item, NULL);
//	if (back != NULL) {
//		back->setNext(temp);
//	}
//	back = temp;
//	if (front == NULL) {
//		front = temp;
//	}
//	cout << "new back = " << back << endl;
//}
//
//template<class T>
//T Queue<T>::remove()
//{
//	if (front != NULL) {
//		T item = front->getData();
//		Node<T> * discard = front;
//		front = front->getNext();
//		delete discard;
//		return item;
//	}
//	return T();
//}
