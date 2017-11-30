#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void push_front(Node* &head,int k);
void Merge_Sort(Node* &head);
void divide(Node* t, Node* &a, Node* &b);
Node* merger_two_sublist(Node* a, Node* b);

int main() {
    Node* head = NULL;
    push_front(head,7);
    push_front(head,10);
    push_front(head,1);
    push_front(head,5);
    push_front(head,4);
    cout << "Before: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> value << " ";
        temp = temp -> next;
    }
       
    cout << endl;
    cout << "After: ";
    Merge_Sort(head);
    Node* temp1 = head;
    while (temp1 != NULL) {
        cout << temp1 -> value << " ";
        temp1 = temp1 -> next;
    }
    cout << endl;
}

void push_front(Node* &head,int k) {

    if (head == NULL) {
        //cout << "yes";
        Node* temp = new Node();
        temp -> next = NULL;
        temp -> value = k;
        head = temp; 
    } else {
        Node* temp = new Node();
        temp -> value = k;
        temp -> next = head;
        head = temp;
    }
}

void Merge_Sort(Node* &head) {
    Node* a = NULL;
    Node* b = NULL;
    Node* temp = head;
    if ((head -> next == NULL)) {
        return;
    }    
    divide(temp,a,b);
    Merge_Sort(a);
    Merge_Sort(b);
    head = merger_two_sublist(a,b);
}
//the last one node like: [5] -> null
void divide(Node* t, Node* &a, Node* &b) {
    Node* slow = NULL;
    Node* fast = NULL;
         
    slow = t;
    fast = slow -> next;
    while (fast != NULL) {
        fast = fast -> next;
        if (fast != NULL) {
	    fast = fast -> next;
	    slow = slow -> next;   
	}
	   
    }
    a = t;
    b = slow -> next;
    slow -> next = NULL;
     
    /* 
    Node* a_1 = a;
    while (a_1 != NULL) {
        cout << a_1 -> value << " ";
        a_1 = a_1 -> next;
    }
   
    cout << ", ";
    Node* b_1 = b;
    while (b_1 != NULL) {
        cout << b_1 -> value << " ";
        b_1 = b_1 -> next;
    }
    cout << endl;*/
   
}   

Node* merger_two_sublist(Node* a, Node* b) {
    Node* result = NULL;
    if(a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;   
    }
    if (a -> value <= b -> value) {
        result = a;
        result -> next = merger_two_sublist(a->next,b);
    } else {
        result = b;
        result -> next = merger_two_sublist(a,b->next);
    }
    return result;
}
