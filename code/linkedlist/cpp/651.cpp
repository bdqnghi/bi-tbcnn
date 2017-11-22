#include <iostream>

using namespace std;

class linkedlist 
{
  private:
  
    struct node
	{
	   int data;
	   node *link;
	} *p;

  public:

    linkedlist();
    void append(int num);
    void addfirst(int num);
    void addafter(int c, int num);
    void del(int num);
    void display();
    int count();
    ~linkedlist();
};

linkedlist::linkedlist() 
{
  p=NULL;
}

void linkedlist::append(int num)
{
  node *q, *t;
  
  if (p=NULL)
  {
    p = new node;
    p->data = num;
    p->link = NULL;
  }

  else 
  {
    q = p;
    while (q->link!=NULL)
    {
      q=q->link;
    } 
  
  t = new node;
  t->data = num;
  t->link = NULL;
  q->link = t;
  }
}

void linkedlist::addfirst(int num)
{
  node *q;
  
  q = new node;
  q->data = num;
  q->link = p;
  p = q;    
}

void linkedlist::addafter(int c, int num)
{
  node *q, *t;  

  int i;
  for (i=0, q=p; i<c; i++)
  {
    q = q->link;
    if (q == NULL)
    {
     cout << "List not that large" << endl;
    }
  }
  
  t = new node; 
  t->data = num;
  t->link = q->link;
  q->link = t;
}

void linkedlist::del(int num) 
{

  node *q, *r;
  q = p;
  
  if (q->data = num)
  {
    r->link = q->link; 
    delete q;
    return;
  }
 
  r = q;

  while (q!=NULL)
  {
    if (q->data = num)
    {
      r->link = q->link;
      delete q;
      return;
    }
  
    r = q;
    q = q->link;
  }

  cout << "Element no:"<< num << "not found";
}

void linkedlist::display()
{
  node *q;
  
  for (q = p; q!=NULL; q=q->link)
  {
    cout << q->data << endl;
  }
}

int linkedlist::count()
{
  node *q;
  int c = 0;
  for (q = p; q!=NULL; q = q->link)
  {
    c++;
  }

  return c;
}

linkedlist::~linkedlist()
{
  node *q;
  if (p->link = NULL)
  {
   cout << "Empty linked list" <<endl;
   return;
  }
  
  while (p!= NULL)
  {
    q = p->link;
    delete p;
    p = q;
  }
}

int main()
{
  linkedlist ll;
  cout << " No.of elements is" << ll.count() <<endl;
  ll.append(10);
  ll.append(20);
  ll.append(30);
  ll.append(40);

  ll.addfirst(2);
  ll.addfirst(3);

  ll.addafter(2, 100);

  ll.display();

  cout << " No.of elements is " << ll.count();
  
  ll.del(30);
  cout << "No.of elements is :" << ll.count();
  return 0;
}
 




        



  




