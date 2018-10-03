#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

class ListNode{
    public:
        ListNode():data(0), next(NULL){}

        int data;
        ListNode *next;
};

// Stack by List
class Stack {

    public:
        Stack():top(NULL){}
        ~Stack(){ DeleteStack(); }

        void Push(int data){
            ListNode *tmp = new ListNode;
            if (!tmp) return;
            tmp->data = data;
            tmp->next = top;
            top = tmp;
        }

        bool IsEmptyStack(){
            return top == NULL;
        }

        int Pop(){
            int data;
            ListNode *tmp;
            if(IsEmptyStack()) return INT_MIN;
            tmp  = top;
            top  = top->next;
            data = tmp->data;
            delete tmp;
            return data;
        }

        int Top(){
            if(IsEmptyStack()) return INT_MIN;
            return top->data;
        }

        void DeleteStack(){
            ListNode *tmp, *p = top;
            while(p->next){
                tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            }
            delete p;
        }
    
    private:
        ListNode *top; 
};

// Queue by Two Stacks
class Queue{
    public:
        Queue():s1(new Stack()), s2(new Stack()){}

        void EnQueue(int data){
            s1->Push(data);
        }

        int DeQueue(){
            if(!s2->IsEmptyStack()) 
                return s2->Pop();
            else {
                while(!s1->IsEmptyStack())
                    s2->Push(s1->Pop());
                return s2->Pop();
            }
        }

    private:
        Stack *s1;
        Stack *s2;
};

int main(){

    Stack s;
    s.Push(5);
    s.Push(4);
    s.Push(2);
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    s.Push(9);
    cout << s.Top() << endl;

    Queue q;
    q.EnQueue(9);
    q.EnQueue(2);
    q.EnQueue(4);
    cout << q.DeQueue() << endl;
    cout << q.DeQueue() << endl;
    q.EnQueue(5);
    cout << q.DeQueue() << endl;
    cout << q.DeQueue() << endl;

    return 0;
}
