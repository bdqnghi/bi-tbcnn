#include "linkedlist.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
    _count = 0;
    _head = nullptr;
    _tail = nullptr;
}

LinkedList::~LinkedList() {
    ListNode *delNode = _head;
	ListNode *temp;

    while( delNode != nullptr) {
        temp = delNode->next(); // получаем указатель на следующий узел
		delete delNode; // Удаляем текущий узел
		delNode = temp; // теперь слудующий узел стал текущим
	}

}

void LinkedList::push_back(int d) {
    if (_count == 0) { 					// в списке нет элементов
        _head = _tail = new ListNode();
        _head->setData(d);
	} else {
        _tail->insertNext(d);
        _tail = _tail->next();
	}
    _count++;
}

void LinkedList::push_front(int d) {
    if(_count == 0) {
        _head = _tail = new ListNode();
        _head->setData(d);
	} else {
		ListNode *new_node = new ListNode();
        new_node->setData(d);
        new_node->setNext(_head);
        _head = new_node;
	}
    _count++;
}

void LinkedList::pop_front() {
    if( _count != 0) {
        ListNode *temp = _head;
        _head = _head->next();
		delete temp;
        _count--;
        if(_head == nullptr) {
            _tail = _head;
		}
	}
}

void LinkedList::pop_back() {
    if(_count == 1) {
        delete _tail;
        _head = _tail = nullptr;
        _count--;
	} 
    if (_count > 1) {
		ListNode *temp = new ListNode();
        temp = _head;
        while(temp->next() != _tail) {
            temp = temp->next();
		}
        _tail = temp;
        delete temp->next();
        _tail->setNext(nullptr);
        _count--;
	}
}

bool LinkedList::isEmpty() {
    return (_count == 0);
}

ListNode *LinkedList::begin() {
    return _head;
}

ListNode *LinkedList::end() {
    return _tail;
}

int LinkedList::count(){
    return _count;
}

void LinkedList::display() const {
    ListNode *node = _head;
    for(int i=0; i < _count; i++) {
       std::cout << node->data() << " ";
       node = node->next();
    }
    std::cout << '\n';
}

void LinkedList::initialization() {
    int data = -1;
    while(data != 0){
      std::cin >> data;
      if(std::cin.good()){
        if(data != 0){
          push_back(data);
        }
      } else {
        std::cout << "Неверный ввод"<< '\n';
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        data = -1;
      }
    }
}
