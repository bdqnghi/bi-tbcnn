#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
};
class abc{
    node *temp,*p,*head,*n;
    int len=0;
public:
    void inserting(){
        if(len==0){
            node *temp=new node;
            cout<<"Enter number: ";
            cin>>temp->data;
            p=temp;
            head=temp;
            len++;
        }
        else{
        node *temp=new node;
        cout<<"Enter number: ";
        cin>>temp->data;
        p->next=temp;
		p=temp;
        len++;
        }
    }

    void display(){
    cout<<"Value\tAddress\n";
    for(temp=head;temp->next!=NULL;temp=temp->next){
    cout<<temp->data<<"\t"<<temp->next<<"\n";
    }
    cout<<temp->data<<"\t"<<temp->next<<"\n";
    }

	void findlen(){
	cout<<"The current length of linked list is:"<<len<<endl;
	}


	void inserting(int pos){
        int val;
        cout<<"Enter Data to insert at "<<pos<<": "<<endl;
        cin>>val;
        int x = len-pos;
        node *temp=new node;
        temp->data = val;
        p=head;
        for(int i=1;i<x+1;p=p->next){
            i++;
        }
        n=p->next;
        p->next=temp;
        temp->next=n;
        //delete n; Find out the issue.

    }
    /*
	remove(){



	}
	remove(position){



	}
	search(){


	}
*/
};

main(){
abc k;
k.inserting();
k.inserting();
k.inserting();
k.inserting();
k.display();
k.findlen();
k.inserting(3);
k.display();
k.findlen();
}

