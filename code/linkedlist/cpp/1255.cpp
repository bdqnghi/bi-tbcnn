#include <iostream>
using namespace std;

template <typename E>
class node							//Class node
{
public:
	E data;
	node *nextElement;
	node()
	{
		data=0, nextElement=NULL;	
	}
};

template <typename E> 
class List
{
	private:
		void operator=(const List&){}
		List(const List&){}
	public:
		List(){}					//constructor
		virtual ~List(){}				//destructor
		virtual int NumberOfElements() const=0;		//Return number of elements in the list
		virtual int CurrentLocation() const=0;		//Return the current location of the element
		virtual const E& getData() const=0;		//Return the data of current element
		virtual void clear() =0;			//clear all data from the list
		virtual void insert(const E& Data)=0;		//Insert data in list at current location
		virtual void append(const E& Data)=0;		//Insert data at the end of list
		virtual E remove()=0;				//Delete the data at current location
		virtual void setListLocationToStart()=0;	//Set the current location to the start of the list
		virtual void setListLocationToEnd()=0;		//Set the current location to the end of the list
		virtual void previousElement()=0;		//Set current location to the element on the left side
		virtual void NextElement()=0;			//Set current location to the element on the right side
		virtual void setToNewLocation(int location)=0;	//Set current location to a new location
};

template <typename E>
class linkList : public List<E> 
{
	node<E>* firstElement; 
	node<E>* lastElement; 
	node<E>* currentElement;
	int sizeOfList;
public:
	linkList()
	{
		firstElement=lastElement=currentElement=new node<E>;
		sizeOfList=0;
	}
	~linkList() 						//destructor
	{
		node<E>* temp = firstElement;
		for(currentElement=firstElement;currentElement!=NULL;currentElement = temp)
		{
			temp = temp->nextElement;
			delete currentElement;
		}
		temp = NULL;
	}
	int NumberOfElements() const 		//Number of elements				
	{
		return sizeOfList;
	}
	int CurrentLocation() const			//Current location index
	{
		node<E>* head;
		head=new node<E>;
		int i=1;
		head=firstElement;
		while(head!=currentElement)
		{
			i++;
			head=head->nextElement;
		}
		return i;
	}
	const E& getData() const 			//Value of the current location node
	{
		return currentElement->data;
	}
	void clear() 						//Clear the linked list
	{
		node<E> *temp;
		temp= new node<E>;
		temp=firstElement;
		currentElement=temp;
		while(temp!=lastElement)
		{
			temp=temp->nextElement;
			delete currentElement;
			currentElement=temp;
		}
		delete currentElement;
	}
	void insert(const E& Data)				//Insert a node at current location
	{
		node<E> *temp;
		node<E> *n;
		temp=new node<E>;
		n=new node<E>;
		if(CurrentLocation()==1)
		{
			if(sizeOfList==0)
			{
				firstElement->data=Data;
				lastElement=firstElement;
			}
			else
			{
				n->data=Data;
				n->nextElement=firstElement;
				firstElement=n;
			}
		}
		else
		{
			temp=firstElement;
			while(temp->nextElement!=currentElement)
			{
				temp=temp->nextElement;
			}
			n->data=Data;
			n->nextElement=temp->nextElement;
			temp->nextElement=n;
			currentElement=n;
		}
		sizeOfList++;
	}
	void append(const E& Data)			//Add a node at last
	{
		node<E> *n;
		n=new node<E>;
		n->nextElement=NULL;
		n->data=Data;
		if(sizeOfList==0)
		{
			firstElement->data=Data;
			lastElement=firstElement;
		}
		else
		{
			lastElement->nextElement=n;
			lastElement=n;
		}
		sizeOfList++;
	}
	E remove()					//Remove node at current location
	{
		node<E> *temp;
		temp=new node<E>;
		temp=firstElement;
		if(currentElement==firstElement)
		{
			firstElement=temp->nextElement;
			temp->nextElement=NULL;
		}
		else
		{
			while(temp->nextElement!=currentElement)
				temp=temp->nextElement;
			temp->nextElement=currentElement->nextElement;
			currentElement->nextElement=NULL;
			currentElement=temp->nextElement;
		}
		sizeOfList--;	
		return currentElement->data;	
	}
	void setListLocationToStart()			//Current nod is set to the first node
	{
		currentElement=firstElement;
	}
	void setListLocationToEnd()			//Current node is set to the last node
	{
		currentElement=lastElement;
	}
	void previousElement()				//Current node is set to the previous node
	{
		node<E> *temp;
		temp=new node<E>;
		temp=firstElement;
		if(currentElement==firstElement)
		{
			cout<<"Not possible"<<endl;
			return;
		}
		while(temp->nextElement!=currentElement)
		{
			temp=temp->nextElement;
		}
		currentElement=temp;
	}
	void NextElement()				//Current node is set to next node
	{
		node<E> *temp;
		temp=new node<E>;
		temp=currentElement;
		if(currentElement==lastElement)
		{
			cout<<"Not possible"<<endl;
			return;
		}
		currentElement=temp->nextElement;
	}
	void setToNewLocation(int location)		//Current location is set to the given location
	{
		node<E> *temp;
		temp=new node<E>;
		temp=firstElement;
		for(int i=1;i<location;i++)
		{
			temp=temp->nextElement;
		}
		currentElement=temp;
	}
	void display()					//Display list
	{
		node<E> *temp;
		temp=new node<E>;
		temp=firstElement;
		for(int i=1;i<=sizeOfList;i++)
		{
			cout<<temp->data<<" ";
			temp=temp->nextElement;
		}
		cout<<endl;
	}
};

int main()
{
	linkList <int> l;
	l.append(9);
	cout<<l.CurrentLocation()<<endl;
	l.insert(2);
	l.setListLocationToStart();
	cout<<l.CurrentLocation()<<endl;
	l.insert(1);
	l.append(3);
	l.append(4);
	l.display();
	cout<<l.NumberOfElements()<<endl;;
	cout<<l.CurrentLocation()<<endl;
	l.display();
	cout<<l.getData()<<endl;
	l.setListLocationToStart();
	l.insert(0);
	l.append(5);
	l.display();
	l.setListLocationToEnd();
	l.insert(6);
	int a=l.getData();
	cout<<a<<endl;
	l.display();
	l.previousElement();
	l.remove();
	l.display();
	l.setListLocationToStart();
	l.NextElement();
	l.insert(-1);
	l.display();
	cout<<l.NumberOfElements()<<endl;
	l.setToNewLocation(2);
	l.remove();
	l.display();
	return 0;
}
