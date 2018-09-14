/*
 * Linked list implementation c++
 * The list illustration
 * Node0 -> Node1 -> Node2 -> ... -> NodeNth -> NULL
 *   ^                                  ^
 * First                              Last
 */

#include <iostream>
#include <string.h>

using namespace std;

//Node structure
struct node{
    int val;
    node *next;
};

//LinkedList class
class linkedlist{
    struct node *start;
    struct node *end;

    public:
    linkedlist();
    int lenlist();
    void addFirst(int val);
    void addLast(int val);
    void addNth(int val, int idx);
    void removeFirst();
    void removeLast();
    void removeNth(int idx);
    void show();
    void swapNode(node * &node1, node * &node2);
    void swapIdx(int idx1, int idx2);
    void sort();
};

//Lenght of the list
int linkedlist::lenlist(){
    node *cur;
    int len = 0;
    cur = start;
    if (start == NULL){
        return 0;
    }
    while(cur != NULL){
        len++;
        cur = cur->next;
    }
    return len;
}

//list
linkedlist::initlist(){
    start = NULL;
    end = NULL;
}

//Add to First
void linkedlist::addFirst(int val){
    struct node *ptr;
    ptr = new node;
    ptr->val = val;
    ptr->next = NULL;
    if (start != NULL){
        ptr->next = start;
        start = ptr;
    }else{
        start = ptr;
        end = ptr;
    }
}

//Add to Last
void linkedlist::addLast(int val){
    struct node *ptr;
    ptr = new node;
    ptr->val = val;
    ptr->next = NULL;
    if (start == NULL){
        start = ptr;
        end = ptr;
    }else{
        end->next = ptr;
    }
    end = ptr;
}

//Add to Nth
void linkedlist::addNth(int val, int idx){
    struct node *ptr;
    ptr = new node;
    ptr->val = val;
    ptr->next = NULL;
    int len = this->linkedlist::lenlist();
    if(len < idx){
        cout<<"Index exceeded"<<endl;
    }else if(idx == 0){
        this->linkedlist::addFirst(val);
    }else{
        node *cur;
        cur = start;
        for(int i = 1; i < idx; i++){
            cur = cur->next;
        }
        ptr->next = cur->next;
        cur->next = ptr;
    }
}

//remove First
void linkedlist::removeFirst(){
    struct node *ptr;
    if(start == NULL){
        cout<<"The list is empty"<<endl;
    }else{
        ptr = start;
        start = start->next;
        cout<<"Deleted first list is: "<<ptr->val<<endl;
        delete ptr;
    }
}

//remove Last
void linkedlist::removeLast(){
    struct node *ptr;
    struct node *toEnd;
    if(start == NULL){
        cout<<"The list is empty"<<endl;
    }else{
        ptr = start;
        while(ptr->next != end){
            ptr = ptr->next;
        }
        cout<<"Deleted last list is: "<<end->val<<endl;
        end = ptr;
        delete ptr;
        end->next = NULL;
    }
}

//remove Nth
void linkedlist::removeNth(int idx){
    struct node *ptr;
    int len = this->linkedlist::lenlist();
    if(len < idx){
        cout<<"Index exceeded"<<endl;
    }else{
        node *cur;
        cur = start;
        for(int i = 0; i < idx; i++){
            cur = cur->next;
        }
        ptr = cur->next;
        cout<<"Deleted Nth list is: "<<ptr->val<<endl;
        cur->next = ptr->next;
        delete ptr;
    }
}

//Show the linked list
void linkedlist::show(){
    struct node *cur;
    cout<<"The lists: "<<endl;
    cout<<"Start-> ";
    for(cur = start; cur != NULL; cur = cur->next){
        cout<<cur->val<<"-> ";
    }
    cout<<"End"<<endl;
}

//Swap node1 and node2
void linkedlist::swapNode(node * &node1, node * &node2){
    struct node * prev1;
    struct node * prev2;
    struct node * cur;
    cur = start;
    bool check1, check2;
    check1 = check2 = true;
    while(check1 || check2){
        if(cur->next == node1){
            prev1 = cur;
            check1 = false;
        }
        if(cur->next == node2){
            prev2 = cur;
            check2 = false;
        }
        cur = cur->next;
    }
    node1->next = node2->next;
    node2->next = prev1->next->next;
    prev1->next = node2;
    prev2->next = node1;
}

//Swap by index
void linkedlist::swapIdx(int idx1, int idx2){
    int len = this->linkedlist::lenlist();
    if (idx1 > len || idx2 > len){
        cout<<"Index exceeded"<<endl;
    }else{
        node * cur;
        node * node1;
        node * node2;
        cur = start;
        for (int i = 0; i < max(idx1, idx2); i++){
            if(i == idx1){
                node1 = cur;
            }
            else if(i == idx2){
                node2 = cur;
            }
            cur = cur->next;
        }
        this->linkedlist::swapNode(node1, node2);
    }
}

//Sort the list using merge sort
void linkedlist::sort(){

}


int main(){
    linkedlist l;
    char op[8];
    int data;
    int idx;
    cout<<"         Linked list Implementation"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Use with these arguments:"<<endl;
    cout<<"addF <val>           add val from first list"<<endl;
    cout<<"addL <val>           add val from last list"<<endl;
    cout<<"addN <val> <idx>     add val from idx-index list"<<endl;
    cout<<"removeF              remove first list"<<endl;
    cout<<"removeL              remove last list"<<endl;
    cout<<"removeN <idx>        remove idx-index list"<<endl;
    cout<<"quit                 quit the program"<<endl;
    while(1){
        cin>>op;
        if(strcmp(op, "addF") == 0){
            cin>>data;
            l.addFirst(data);
        }else if(strcmp(op, "addL") == 0){
            cin>>data;
            l.addLast(data);
        }else if(strcmp(op, "addN") == 0){
            cin>>data;
            cin>>idx;
            l.addNth(data, idx);
        }else if(strcmp(op, "removeF") == 0){
            l.removeFirst();
        }else if(strcmp(op, "removeL") == 0){
            l.removeLast();
        }else if(strcmp(op, "removeN") == 0){
            cin>>idx;
            l.removeNth(idx);
        }else if(strcmp(op, "quit") == 0){
            break;
        }else{
            cout<<"Please use the correct arguments"<<endl;
        }
        l.show();
    }
    return 0;
}
