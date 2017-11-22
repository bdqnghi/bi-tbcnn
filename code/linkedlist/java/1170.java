import java.util.Scanner;
public class Linkedlist {
	node Head;
	class node{
		int data;
		node next;
		node(int d){
			data=d;
			next= null;
		}
	}
	void push(int ndata){
		node newnode=new node(ndata);
		newnode.data= ndata;
		newnode.next= Head;
		Head= newnode;
		
	}
    void traverse(node Head){
    	if( Head==null){
    		return;
    	}
    	else {  
    		System.out.print(Head.data+" ");
    		traverse(Head.next);
    	}
    }
    int count_d(node Head,int d){
    	if(Head==null)
    	{
    		return 0;
    	}
    	if(Head.data==d){
    		return 1+count_d(Head.next,d);
    	}
    	else{
    		return count_d(Head.next,d);
    	}
    }
    int add_list(node Head)
    {
    	if(Head==null)
    	{
    		return 0;
    	}
    	else {
    		return Head.data+add_list(Head.next);
    	}
    }
    
    
    public static void main(String[] args){
    	int id[]= new int[100];
    	int p,q=0;
    	System.out.println("1) Enter your input: ");
    	Scanner s= new Scanner(System.in);
    	p= s.nextInt();
    	while(p>0)
    	{
    		id[q]=p%10;
    		p=p/10;
    		q++;
    	}
       	Linkedlist altlist= new Linkedlist();
    	int i,j=0;
    	for(i=0;i<q*2;i++)
		{
			if(i%2==0){
				altlist.push(5);
				
			}
			else{
				altlist.push(id[j]);
				j++;
				
			}
		}
    	altlist.traverse(altlist.Head);
    	int r,add,f,fi;
    	r=altlist.count_d(altlist.Head,5);
    	System.out.println("\n"+"2)Number of 5's in the list: "+r);
    	System.out.println(" Enter the no. you need to find:");
    	f=s.nextInt();
    	fi=altlist.count_d(altlist.Head,f);
    	System.out.println("\n"+" Number of "+f+"'s in the list: "+fi);
    	add=altlist.add_list(altlist.Head);
    	System.out.println("3)Sum of all elements in list: "+add);
    }
}

