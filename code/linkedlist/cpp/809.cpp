#include <iostream>

using namespace std;

template<class T>
    
class node{
    public:
        T item;
        node *next;
    
    node(){
        item = 0;
        next = NULL;
    }
    node(int x){
        item = x;
        next = NULL;
    }
};
    
    
template<class T>    
class Linkedlist{
    private:
        int size;
        node<T> *head,*tail;
    public:
        Linkedlist();
        Linkedlist(const Linkedlist&);
//~Linkedlist();
        bool insert(T, int);
        bool remove(int);
        bool setItem(T,int);
        T getItem(int);
        int getSize();

};

void display(Linkedlist<int>);

template<class T>
Linkedlist<T>::Linkedlist(){
    size=0;
    head = NULL;
    tail = NULL;
}


template<class T>
bool Linkedlist<T>::setItem(T x,int pos){
    if(pos<0 || pos>size)
        return false;
    
    else{
        node<T> *tmp = head;
        int i=0;
        
        while(i<pos-1){
            tmp = tmp->next;
            i++;
        }
        
        tmp->item = x;
       
    }
    return true;
}

template<class T>
Linkedlist<T>::Linkedlist(const Linkedlist& l){
    size = 0;
    head = NULL;
    tail = NULL;
    
    node<T> *tmp = l.head;
    
    for(int i=0;i<l.size;i++){
        insert(tmp->item,i);
        tmp=tmp->next;
    }
    
    
}



template<class T>
bool Linkedlist<T>::insert(T x, int pos){
    
    if(pos<0 || pos>size)
        return false;
    
    else{
         node<T> *n = new node<T>(x);

        if(size==0){
            head=tail=n;
        }
    
        else if(pos==0){
            n->next = head;
            head = n;
           
           
        }
        else if(pos == size){
            tail->next = n;
            tail = n;
        }
        else{
            node<T> *tmp = head;
            node<T> *tmp2;
            int i = 0;
        
            while(i<pos-1){
               tmp = tmp->next;
                i++;
            }
        
        tmp2 = tmp->next;
        n->next = tmp2;
        tmp->next = n;
       
        
        }
              
    }
           size++;

     return true;
 }

template<class T>
int Linkedlist<T>::getSize(){
    
    return size;
}

 
 void display(Linkedlist<int> l){
    
     int i=0;
     while(i<l.getSize()){
        cout<<l.getItem(i)<<" ";
        i++;
     }
     cout<<endl;

 }

template<class T>
bool Linkedlist<T>::remove(int pos){
    if(pos<0 || pos>size)
        return false;
    
    else{
    
         if(pos==0){
              node<T> *del;
              del = head;
              head = head->next;
              del->next = NULL;
         }
        
         else{
              node<T> *tmp = head;
              node<T> *del;
              int i=0;
            
             while(i<pos-1){
                tmp = tmp->next;
                i++;
             }
         
             del = tmp->next;
             tmp->next = del->next;
             del->next = NULL;
         
           if(del == tail)
               tail = tmp;
         
               
       delete del;
       size--;         
         }

    }     
       return true;
}

template<class T>
 T Linkedlist<T>::getItem(int pos){
        
    
         int i=0;
         node<T> *tmp=head;
         
         while(i<pos){
             tmp=tmp->next;
            i++;
         }
         
         return tmp->item;
     
 }

int main() {
    Linkedlist<int> l;
    int testcases, x;
    int item=0, pos=0;
    
    cin>>testcases;
        while(testcases>0){
            cin>>pos;
            cin>>item; 
            
            l.insert(item,pos);
          // cout<<l.getSize()<<endl;
            display(l);      
          
         testcases--;     
        }
     
    
     return 0;
}