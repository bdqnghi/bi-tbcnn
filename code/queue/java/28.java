import java.util.*;
public class Queue
{	
	int f=0;
	int r=-1;
	int a[]=new int[50];
	
	public void insert(int item)
	{
		if(r<49)
			a[++r]=item;
		else System.out.println("Queue is full");
	}
	
	public void delete()
	{
		if(f>r)System.out.println("Queue is empty");
		else System.out.println(a[f++]+" is deleted");
	}
	
	public void display()
	{
	 System.out.println("Queue contents :");
	 for(int i=f;i<=r;i++)
		 System.out.println(a[i]);
	}

 

	public static void main(String []args)
	{Queue s=new Queue();
	 int x;
	 Random rand=new Random();
	 
	  for(int i=0;i<=50;i++)
	  { 
		  x=rand.nextInt(50);
		  s.insert(x);
	  }
	 s.display();
	 for(int i=0;i<=50;i++)
	 {s.delete();}
	}
}