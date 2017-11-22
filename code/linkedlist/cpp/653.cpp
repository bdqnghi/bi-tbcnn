#include "linkedlist.h"

linkedlist::linkedlist(){
  head = NULL;
  count = 0;
}
void linkedlist::insert(robot *rp){
  node *n;
  n = new node;
  n->set_data(rp);
  n->set_next(head);
  head = n;
  count++;
}
void linkedlist::remove(int n){
  if(head == NULL)
    return;
  if((head->get_data())->getID()==n){
    node *temp;
    temp = head;
    head = head->get_next();
    temp -> remove_data();
    delete temp;
    count--;
  }
  else{
    if(head->remove(n) == 1)
      count--;
  }
}
void linkedlist::print(){
    std::cout << "There are " << count;
    std::cout << " robots in the list: \n";
  if(head !=NULL)
    head->print();
}

void linkedlist::turnWest() {
  if(head != NULL)
     head->turnWest();
}
void linkedlist::turnEast() {
  if(head != NULL)
     head->turnEast();
}
void linkedlist::turnNorth() {
  if(head != NULL)
     head->turnNorth();
}
void linkedlist::turnSouth() {
  if(head != NULL)
     head->turnSouth();
}

int linkedlist::turnRobotWest(int n){
  if(head != NULL)
    head->turnRobotWest(n);
}
int linkedlist::turnRobotEast(int n){
  if(head != NULL)
    head->turnRobotEast(n);
}
int linkedlist::turnRobotSouth(int n){
  if(head != NULL)
    head -> turnRobotSouth(n);
}
int linkedlist::turnRobotNorth(int n){
  if(head != NULL)
    head -> turnRobotNorth(n);
}