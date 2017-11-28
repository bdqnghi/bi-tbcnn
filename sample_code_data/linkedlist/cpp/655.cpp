#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};
void inputdata(node *&l);
void addatbegin(node *&l);
void addatend(node *&l);
void addafter(node *&l);
void addbefore(node *&l);
void delete_el(node *&l);

void printlist(node *l);

int main()
{node *lst,*x,*startpos;

inputdata(lst);
startpos=lst;

int ans;
do{
cout<<"\nEnter 1.Add at beg 2. Add at end 3.Add after 4.Add before 5.Print list 6.del 7.Exit: ";
cin>>ans;
lst=startpos;
switch(ans)
{
case 1:addatbegin(lst);break;
case 2:addatend(lst);break;
case 3:addafter(lst);break;
case 4:addbefore(lst);break;
case 5:printlist(lst);break;
case 6:delete_el(lst);break;
case 7:exit(1);

}
}while(ans!=7);



return 0;


}

void inputdata(node *&l)
{ node *s,*temp;
 l=new node;
s=l;
cout<<"Enter elements.press -1 to stop entering  : \n";
cin>>l->data;
l->next='\0';


do {
    temp=new node;
    cin>> temp->data;
    if(temp->data!=-1)
      {
       temp->next='\0';
       l->next=temp;
       l=temp;
      }
    } while(temp->data!=-1);

l=s;
}


void printlist(node *l)
{
while(l!='\0')
       {
       cout<<l->data<<"   ";
       l=l->next;
       }
}

void addatend(node *&l)
{int el;
 cout<<"Enter element :";
 cin>>el;
while(l->next!='\0')
l=l->next;
    l->next=new node;
    l->next->data=el;
    l->next->next='\0';
    l=l->next;


}
void addatbegin(node *&l)
{    node *t;
     t=new node;
    cout<<"Enter element :";
     cin>>t->data;
       t->next=l;
       l=t;
}
void addafter(node *&l)
{int el,x;
cout<<"Add After which element :";
cin>>x;
 cout<<"Enter element :";
 cin>>el;
    node *t;
    t=new(node);
    while(l->data!=x)
        l=l->next;
    t->data=el;
    t->next=l->next;
    l->next=t;
    l=t;

}
void addbefore(node *&l)
{int el,x;
cout<<"Add before which element :";
cin>>x;
 cout<<"Enter element :";
 cin>>el;
    node *t;
    t=new(node);
    while(l->next->data!=x)
        l=l->next;
       t->data=el;
    t->next=l->next;
    l->next=t;
    l=t;
}

void delete_el(node *&l)
{
    int el;
    cout<<"Which element u want to delete  : ";
    cin>>el;

    while(l->next->data!=el);
    l->next=l->next->next;

}


