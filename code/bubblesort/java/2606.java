
public class bubblesort {
public Node head;

/*
 * checks to see if the list is empty
 */
public boolean isEmpty(){
	return (head==null);
}
/*
 * added the size method 
 * it returns the size of the list anytime something is added
 */
public int size ()
{
	//make a counter 
	int counter = 0;
	//if the list is empty return 0
	if (isEmpty())
	{
		return counter;
	} 
	else
	{
		//store the head inside a temp node
		Node temp = head;
		//loop through the list
		while (temp!=null)
		{
			//increment the counter by 1 
			counter++;
			//go on to the next node in the list until it reaches null and then breaks
			temp = temp.getNext();
		}
		//return the counter
		return counter;
	}
}
/*
 * method that is used to add something to the end of the list
 */
public void addNode (double data)
{
	//creates a new node
	Node newNode = new Node (data);
	
	//if the list is empty 
	if (isEmpty())
	{
		//set the head = to the newnode
		head = newNode;
		
	}
	
	else 
	{
		//store the head inside a temp node
		Node temp = head;
		//loop through the list 
		while (temp.getNext()!=null)
		{
			temp = temp.getNext();
		}
		//set the next null spot to the newNode
		temp.setNext(newNode);
	}
	
}


/*
 * method used to print the whole entire list
 */
public void printList ()
{
	//checks to see if the list is empty
	//if it is empty return
	if (isEmpty())
	{
		return;
	}
	else 
	{
		//make a temp that stores the head
		Node temp = head;
		//loop through the entire list
		while (temp!=null){
			//print out the goods
			System.out.print(temp);
			//make temp equal to the next thing in the list 
			temp = temp.getNext();
		}
	}
}
/*
 * method that sorts the list
 * it compares the first thing in the list to the second thing in the list
 * if the data on the left is greater than the data on the right then it will swap
 */
public void bubblesortList ()
{
	//checks to see if the list is empty
	if (isEmpty())
	{
		return;
	}
	else 
	{

		
		//loops through the list
       for (int i = 0;i<size();i++)
       {
    	   //sets the temp equal to the head
    	   Node temp = head;
    	  
    	     for (int j = 0;j<size()-1;j++)
    	     {
    	    	
    	    //if the data on the left is greater than the data on the right than swap
    		  if (temp.getData()>temp.getNext().getData())
    		  {
    			  /*
    			   * stores the temps data into a temp variable 
    			   * than sets the temp.data equal to the temp.next.data
    			   * then sets the data of temp.next.data equal to the temp variable curr
    			   */
    			  double curr = temp.getData();
    			  temp.setName(temp.getNext().getData());
    			  temp.getNext().setName(curr);
    			 
    		  }
    		  //increments temp to the next thing in the list
    		  temp = temp.getNext();
    		
    	  }
    	 
    	  
      }
     
      
     
      


}
}
}
