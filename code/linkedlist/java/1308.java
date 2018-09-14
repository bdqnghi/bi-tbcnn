/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication22;

public class linkedlist {
    node head;
    int count;
    
    public linkedlist(){
     head=null;
     count=0;
    }
    
    public linkedlist(node newnode){
     head=newnode;
     count=1;
    }
    //method to add newnode and data
    public void add(int newdata){
        node temp=new node(newdata);
        node current=head;
        while(current.getnext()!=null){
         current=current.getnext();
        }
        //current.setdata(newdata);
        current.setnext(temp);
        count++;
    }
    
    public int count(int index){
    if(index<0){
        return -1; 
    }
    node current=head;
    for(int i=1;i<index;i++){
    current=current.getnext();
        }
     return current.getdata();
}
    public int size()
    {
     return count;
    }
    public String isempty()
    {
     if(head==null)
      {
       return("empty!!");
      }
     else
         return("not empty");
    }
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}
