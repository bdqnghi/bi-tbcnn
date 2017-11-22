#include "object.h"
#include "tdalist.h"
#include "linkedlist.h"
#include <iostream>

using namespace std;

Linkedlist::Node::Node(Object* data_b, Node* next_b){
    data = data_b;
    next = next_b;
}

Linkedlist::Node::~Node(){
    if(data){
        delete data;
    }

    if(next){
        delete next;
    }
}

Linkedlist::Linkedlist(){
    if(head){
        head = NULL;
    }else{

    }
}

Linkedlist::~Linkedlist(){
    if(head){
        delete head;
    }else{

    }
}

bool Linkedlist::insert(Object* other, int pos) {
    if (pos > size || pos < 0){
        return false;
    }else {
        Node* neo = new Node(other);
        if(!neo){
            return false;
        }else if(size == 0){
            neo->next = head;
            head = neo;
            size++;
            return true;
        }else{
            Node* tmp = head;
            
            for(int i = 0; i < pos-1; i++){
                tmp = tmp->next;
            }
            neo->next = tmp->next;
            tmp->next = neo;
            size++;
            return true;
        }
    }
}

int Linkedlist::indexOf(Object* other)const {
    Node* tmp = head;
    for(int i = 0; i < size; i++){
        if(tmp->data->equals(other)){
            return i;
        }else{
            if(!(tmp->data)->equals(other)){
                return -1;
            }
        }
        tmp = tmp->next;
    }
}

Object* Linkedlist::get(unsigned index)const {
    if(index > size || index == size || index == size){
        return NULL;
    }else{
        Node* tmp = head;
        for(int i = 0; i < index; i++){
            tmp = tmp->next;
        }
        return NULL;
    }
}

bool Linkedlist::erase(unsigned pos) {
    return true;
}

Object* Linkedlist::first()const {
    if(size == 0){
        return NULL;
    }else{
        return NULL;
    }
}

Object* Linkedlist::last()const {
    if(size == 0){
        return NULL;
    }
}