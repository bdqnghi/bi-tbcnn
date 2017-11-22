// $Id: linkedlist.java,v 1.1 2012-10-18 13:19:38-07 - - $
//pair programing Alejandro Aguilar (aaguil10@ucsc.edu)
//and Alessio Alba (acalba@ucsc.edu)
import java.util.Iterator;
import java.util.NoSuchElementException;

class linkedlist implements Iterable<pair> {

 private class node {
  pair item;
  node link;
 }
 private node head = null;

 public void getKey (String _key) {
   String key = _key;
  node tmp=head;
  boolean found=false;
  while (tmp!=null){
  if(key.equals(tmp.item.key)){
     found=true;
     System.out.println(tmp.item.key+"="+tmp.item.value);
  }
  tmp=tmp.link;   
  }
  if (!found){
  System.out.println(key+": not found"); 
}
 }
 
 public void getValue (String value) {
  node tmp=head;
  while (tmp!=null){
  if(tmp.item.value.equals(value)){  
    System.out.println(tmp.item.key+"="+tmp.item.value);
  }
  tmp=tmp.link;   
  }
 }

 public String put (String key, String value) {
  node prev=null;
  node curr = head;  
  int cmp =1;
  String result = null;
  while (curr!=null){
  cmp = curr.item.key.compareTo(key);
   if(cmp >=0) break;
    prev = curr;
    curr = curr.link;
  }

  if(cmp!=0){
  node tmp = new node();
  tmp.item = new pair(key,value);
  
 if(prev == null) {
 head = tmp;
 tmp.link = null;
 }else{ 
  prev.link = tmp;
  tmp.link = curr;
 }
 }else{
 result = curr.item.value;
 curr.item.value = value;

  }
 return result;
 }

 public void delete (String key) {
  node prev=null;
  node tmp=head;
  while (tmp!=null){
  if(tmp.item.key.equals(key)){
    prev.link=tmp.link;   
    System.out.println(tmp.item.key+"="+tmp.item.value);
  }
  prev=tmp;
  tmp=tmp.link;   
  }
 }
 
 public void printList (){
  node tmp=head;
  while (tmp!=null){
    System.out.println(tmp.item.key+"="+tmp.item.value);
    tmp=tmp.link;
  }
 }
public void printKeyValue(){
	node tmp=head;
	while(tmp.link!=null){
	tmp=tmp.link;
	}
	System.out.println(tmp.item.key+"="+tmp.item.value);
	
}

 public Iterator<pair> iterator () {
  return new itor ();
 }

 private class itor implements Iterator<pair> {
  private node nextnode = head;

 public boolean hasNext () {
  return nextnode != null;
 }

 public pair next () {
  if (! hasNext()) throw new NoSuchElementException ();
  pair result = nextnode.item;
  nextnode = nextnode.link;
  return result;
 }

 public void remove () {
  throw new UnsupportedOperationException ();
 }
}
}
