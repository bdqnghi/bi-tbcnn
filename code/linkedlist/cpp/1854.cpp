#include<bits/stdc++.h>
using namespace std;
class link
{
    int data;
    link *next;
    public:
        link *start,*rear;
        link()
        {
            start=NULL;
            rear=NULL;
        }
        void insert_node();
        void delete_node();
        void display();

};
void link::insert_node()
{
    link *np=new link;
    int n;
    cout<<"Enter the data:";
    cin>>n;
    np->data=n;
    np->next=NULL;
    if(start==NULL)
    {
        start=np;
        start->next=NULL;
        rear=start;
    }
    else
    {
        rear->next=np;
        rear=np;
    }
}
void link::display()
{
    link *np;
    np=start;
    while(np!=NULL)
    {
       cout<<np->data<<" ";
       np=np->next;
    }
}
void link::delete_node()
{
   link *save;
   save=start;
   start=start->next;
   delete save;
}
int main()
{
    int choice=1;
    link ll;
    while(choice)
    {
        cout<<"1.Insert a node\n";
        cout<<"2.Delete a node\n";
        cout<<"3.Display the list\n";
        //cout<<"0 to abort\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                ll.insert_node();
                break;
            case 2:
                ll.delete_node();
                break;
            case 3:ll.display();
                break;
        }
        cout<<"Press 1 to continue/0 to abort:";
        cin>>choice;
    }
    return 0;
}

