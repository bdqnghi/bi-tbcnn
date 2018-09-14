package linkedlist;

public class Linkedlist {



	public static void main(String[] args) {

		int[] data={0,7,305,1050,680,9000};
//declaring values using an array
		//returns an array to the object
		Object[][] linkedList=new Object[1][2];
//we are creating and printing a linked list with a parameter 		
		createLinkedList(data,linkedList);
		//data is being stored in a node
		printLinkedList(linkedList);
	}
		
		public static void createLinkedList(int[] data, Object[][] linkedList) 
	{
//public keyword is an access modifier
//static allows main() to be called without having to instantiate a particular instance of the class
//void simply says the compiler that main() does not return a value
//data will be stored in the form of integer array
		Object node[][]=null;
//object have states and behavior. An object is instance of class.
//node is a primary data type.It represents single node in a tree
		Object newnode[][]=null;
//new node means creating a new node and pretends it as beginning of the list
		node=new Object[1][2];
//creating a node with new object and initializing an array
		linkedList[0][1]=node;
//assigning the nodes in linked list with size of an array
		for(int i=0;i<data.length;i++)
			//by using for loop we are implementing linked list
			//here i is declared inside of the for loop
		{
			node[0][0]=new Integer(data[i]);
//creating an object by this if the one head points to the first node of the list
			newnode=new Object[1][2];
			node[0][1]=newnode;
			node=newnode;
		}
		node=null;
		newnode=null;
	}
	public static void printLinkedList(Object[][] linkedList){
			Object node[][]=null;
//here taking a object node as null
			node=linkedList;
//we first insert the node then insert the last node in the linked list
			node=(Object[][]) node[0][1];
			while(node[0][1]!=null)
				//we are using while loop that is not equal to null
			{
				System.out.print(" "+node[0][0]+"--->");
	//here we print the values and it helps to form the values in the form of linked list
				node=(Object[][]) node[0][1];
				
			}System.out.print("null");
//in last it prints null that the node is empty
		}	
//this is a single linked list contains nodes which have data fields as well as next field
//which points to the next node in the line of nodes
	
}