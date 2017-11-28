#include <iostream>

using namespace std;

//Node has data(int type) and pointer to the next node
struct node
    {
    int data;
    node *next;
    }*p; //p is the object to the struct


class list
{
    public: //These member function will be called in main class. So, public.
    list(); //constructor to the class
    void addatend(int num);
    int deleteatend();
    void deletenum(int num);
    void show();
    ~list(); //destructor to the class
};

list::list()
{
    p = NULL; //Initialize p to NULL. Initialized when it is first called.
}

void list::addatend(int num)
{
    node *t, *q;
    if (p==NULL)
    {
        p = new node;
        p->data = num;
        p->next = NULL;
        return;
    }
    t = new node;
    t->data = num;
    t->next = NULL;

    q = p;
    while (q->next!=NULL)
    {
        q = q->next;
    }

    q->next = t;
}

int list::deleteatend()
{
    node *tmp, *t;
    int val;
    if (p==NULL)
    {
        cout <<"Empty list. Nothing to delete" <<endl;
        return NULL;
    }

    t = p;
    while (t->next!=NULL)
    {
        t = t->next;
    }
    tmp = t;
    val = t->data;
    t = t->next;

    delete tmp;
    return val;

}

void list::deletenum(int num)
{
    node *q, *tmp;
    if (p==NULL)
    {
        cout << "Empty list" <<endl;
        return;
    }
    q = p;
    while (q->next!=NULL)
    {
        if (q->data == num)
        {
            tmp = q;
            q = q->next;
            delete tmp;
            return;
        }
        q = q->next;
    }
    cout << "Element not found in the list" <<endl;
}


void list::show()
{
    node *q;
    q = p;
    while (q!=NULL)
    {
        cout << q->data <<endl;
        q = q->next;
    }
}

list::~list()
{
    node *del, *s;
    s = p;
    while (s!=NULL)
    {
        del = s;
        s = s->next;
        delete del;

    }
}

int main()
{
    list mylinks;
    mylinks.addatend(32);
    mylinks.addatend(22);
    mylinks.addatend(43);
    mylinks.addatend(76);
    cout << "-----Append to linked list---" <<endl;
    mylinks.show();

    cout << "-----specific number deletion---" <<endl;
    mylinks.deletenum(43);
    mylinks.show();

    cout << "-----Delete the number at the end---" <<endl;
    cout << mylinks.deleteatend() <<"is deleted" <<endl;
    mylinks.show();

    return 0;

}
