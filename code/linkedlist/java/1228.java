
class linkedlist 
{   

   private node first;
   private node last;

   public linkedlist()//contruction of an empty list
   { 
       
       first=null;
       last=null; 
    }
   public boolean  isEmpty()//checking if list is empty
    {if ((first==null)&&(last==null))
        {return true;} else {return false;}
        
    }   

    public void insertLast(BinaryNodeWithSize d )//new list node
    {node newNode = new node(d);
        if( isEmpty() ) 
         first = newNode;
         else{
         last.next = newNode;
         newNode.previous = last;
           }
         last = newNode;
        }

    public void deleteFirst()//delete first for queue
    {  
        if(isEmpty())
        {return;}
        
        if (first.next==null)
        {first=null;
        last=null;}
        else
        {first.next.previous=null;
        first=first.next;}
     }
     
     public void deleteLast()//delete last for stack
    {  
        if(isEmpty())
        {return;}
        
        if (first.next==null)
        {first=null;
        last=null;}
        else
        {last.previous.next=null;
        last=last.previous;}
     }
    
   
    public node first()//queue first() method
    {return first;}
    
   public node last()//stack top() or topandpop() method
    {
        
        return last;
    }
}