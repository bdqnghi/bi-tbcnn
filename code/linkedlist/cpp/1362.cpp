#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include"linkedlist.hpp"

#define __LINKEDLIST

//explicit instantiation 
template class	LinkedList<int> ;
template class	LinkedList<char> ;
template class  LinkedList<double>;

template <class T>
LinkedList<T>::LinkedList()
{
	//constructor
	head = tail = NULL;
}
template <class T>
LinkedList<T>::LinkedList(const T value)
{
	//constructor
	head = new Node<T>(value);
	tail = head;
}
template <class T>
LinkedList<T>::~LinkedList()
{
	deleteList();
}
template <class T>
void LinkedList<T>::deleteList()
{
	if(isEmpty()) {/*cout<< "Empty list: Nothing to delete"<<endl;*/ return;}
	Node<T> *curr ;
	curr = head;//= head;
	Node<T> *temp;

	while(curr!=NULL)
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	head = tail = NULL;
	//cout << "List deleted"<<endl;
}
template <class T>
void LinkedList<T>::push(const T value)
{
	//add a node to the head of a linked list
	if (head == NULL)
	{
		tail = head = new Node<T>(value);
		return;
	}

	Node<T> * newNode = new Node<T>(value);
	newNode->next = head;
	head = newNode; //update the head node
}
template <class T>
void LinkedList<T>::push(const T value,Node<T> *node)
{
	//push after given node with the given data
	if(node!=NULL)
		node->next = new Node<T>(value,node->next);
}
template <class T>
void LinkedList<T>::push_at_tail(const T value)
{
	if(head == NULL)
	{
		tail = head = new Node<T>(value);
		return;
	}

	tail->next = new Node<T>(value);
	tail = tail->next;

}
template <class T>
unsigned int LinkedList<T>::length()
{
	if(isEmpty()) {std::cout << " Empty list "<<std::endl;return 0;}
	Node<T> *curr;
	curr = head;//= head;
	unsigned int len=0;
	while(curr!= NULL)
	{
		curr = curr->next;
		len++;		
	}
	//cout << "Length of list : "<<len<<endl;
	return len;
}
template <class T>
T LinkedList<T>::search(const T value)
{
	if(isEmpty()){std::cout << " Empty list "<<std::endl; return -1;}
	Node<T> *curr = head;
	int loc=1;
	while(curr!=NULL)
	{
		if(curr->data == value)
		{
			std::cout<< "Data "<<value<<" found at location :"<<loc<<std::endl;
			return loc;
		}
		loc++;
		curr = curr->next;
	}
	std::cout<< "Data "<< value<<" not found in the list"<<std::endl;
	return -1;

}
template <class T>
T LinkedList<T>::pop()
{
	//removes node at the head;
	T data;
	if(isEmpty()){std::cout << "Cannot pop : Empty list"<<std::endl; return -1;}

	if(tail == head) // only one node in the list
	{

	}
	Node<T> *temp = head;
	data = temp->data;
	head = head->next;
	delete temp;
	return data;

}
template <class T>
T LinkedList<T>::pop_tail()
{
	//removes node at the tail;
	Node<T> *prev=NULL,*curr=NULL;
	T data;
	if(isEmpty()){std::cout << "Cannot pop : Empty list"<<std::endl; return -1;}
	if(tail == head) // only one node in the list
	{

	}
	curr = head;
	while(curr->next!=NULL)
	{
		prev = curr;
		curr= curr->next;
	}
	prev->next = NULL;
	tail = prev;
	data = curr->data;
	delete curr;
	return data;
}
template <class T>
T LinkedList<T>::get_node_at_loc(const unsigned int idx)
{
	// gets the data stored at location idx from the head
	if(isEmpty()){std::cout << "Empty list: Nothing to get."<<std::endl; return -1;}

	if(idx > length())
	{
		std::cout<<"Invalid index: List is smaller than the index"<<std::endl;
		return -1;
	}

	Node<T> *curr = head;
	int count=1;
	while(count!=idx && curr!=NULL)
	{
		curr = curr->next;
		count++;
	}
	if (curr == NULL)
	{
		return -1;
	}

	//cout << "Data at location "<<idx<<": "<<curr->data<<endl;
	return curr->data;
}
template <class T>
void LinkedList<T>::delete_node(const T value)
{
	Node<T> *prev=NULL,*temp=NULL;
	if(head->data == value)
	{
		temp = head;
		head = head->next;
		delete temp;
		return;
	}
	prev = head;
	temp = head->next;
	while(temp!=NULL)
	{
		if(temp->data == value)
		{
			prev->next = temp->next;
			if(temp == tail)
			{
				tail = prev;
			}
			delete temp;
			break;
		}
		prev = temp;
		temp = temp->next;
	}

}
template <class T>
void LinkedList<T>::print_list()
{
	Node<T> *curr = head;

	if(isEmpty()){std::cout << "Empty list"<<std::endl; return;}
	while(curr!=NULL)
	{
		std::cout<< curr->data<<" ";
		curr=curr->next;
	}
	std::cout<<std::endl;
}
template <class T>
void LinkedList<T>::reverse()
{
	if(head == NULL)
	{
		std::cout << "Empty list : Cannot reverse"<<std::endl;
		return;
	}
	Node<T> *curr,*next,*prev = NULL;

	curr = head;
	tail = curr;
	if(curr == NULL) return;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	tail->next = NULL; //  not necessary just for safety
	std::cout << "Reverse list " << std::endl;

}
template <class T>
void LinkedList<T>::rotate_list(int k)
{
	/*
	Rotate the link list counter-clock wise by k times.
	Eg: 10->4->34->5->36->9 rotated by 3 should be
	5->36->9->10->4->34
	For this we need to store (k+1)th node, last node and kth node
	*/
	if (isEmpty()) { std::cout << "Empty list: Nothing to rotate" << std::endl; return; }
	k %= length(); // make sure that k is less than the length of the list
	int count = 1;
	Node<T> *curr = head;

	while (count != k && curr!=NULL)
	{
		count++;
		curr = curr->next;
	}


	tail->next = head;
	head = curr->next;
	tail = curr;
	tail->next = NULL;

	std::cout << "List rotate counter-clock wise by " << k << std::endl;

}
template <class T>
void LinkedList<T>::sort()
{
	// ascending order
	// only works for decimal and interger inputs
	if (isEmpty()) { std::cout << "Empty list: Nothing to sort" << std::endl; return; }

	Node<T> *curr = head;

	while(curr!=NULL)
	{
		Node<T> *nxt = curr->getNext();

		while(nxt!=NULL)
		{
			if(curr->getData() > nxt->getData())
			{
				T temp = curr->getData();
				curr->setData(nxt->getData());
				nxt->setData(temp);
			}
			nxt = nxt->getNext();
		}
		curr = curr->getNext();
	}
}
template <class T>
T middle_of_list(LinkedList<T> *list)
{
	Node<T> *slow = list->gethead();
	Node<T> *fast = list->gethead();

	while(fast->getNext()!=NULL)
	{
		slow = slow->getNext();
		if(fast->getNext()->getNext() == NULL)
			break;
		fast = fast->getNext()->getNext();
	}

	return slow->getData();
}



void runLinkedList()
{

	LinkedList<int> list;
	list.push(3);
	list.push(9);
	list.push(10);
	list.push(1);
	list.push(4);
	list.push(34);
	list.push(453);
	list.print_list();
	list.sort();	
	list.print_list();

	std::cout<< "Middle of list ="<<middle_of_list(&list)<<std::endl;
}
