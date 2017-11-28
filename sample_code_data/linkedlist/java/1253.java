/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package doublelinkedlist;

/**
 *
 * @author jeselfalan
 */
public class linkedlist {
    node curr;
    node head;
   
    
    public linkedlist(){
        this.head = null;
        this.curr = null;
    }
    
    public linkedlist(node h){
        this.head = h;
        this.curr = this.head;
    }
    
    public void appendNode(node n){
        this.curr.next = n;
        n.prev = this.curr;
        this.curr = n;
        n.next = this.head;
        
    }
    
}
