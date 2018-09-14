#include <iostream>
#include "linkedlist.hpp"

using namespace std;

//contructor makes a head node with 0 as the default value and next set to NULL as default
LinkedList::LinkedList(){
  head->value = 0;
  head->next =NULL;
  listLength = 0;
}

bool LinkedList::insertNode(node * newNode, int position){
  if( (position<=0) || (position >listLength+1)){
    cout<<"error, position ot of range!";
    exit(1);
  }
}
