package linkedlist;


import java.util.Iterator;

import nodo.node;

public class linkedlist <T>{
	private node<T> sentinel=null;
	
	public linkedlist() { //constructor default
		sentinel = new node<T>(); //nodo centinela
		sentinel.setIndex(-1); //indice nodo centinela
	}
	
	public linkedlist(T value) {
		this(); //Llama al constructor con la firma del metodo
		node<T> tmp = new node<T>(value); //creacion de nodo. Nodo valor de tipo T
		//tmp.setIndex(0);
		sentinel.setNext(tmp);
	}
	
	//Agregar al inicio de la lista
	public void AddStart(T value) {

		node<T> tmp= sentinel.getNext();
		node <T> _new=new node<T>(value);
		
		_new.setNext(tmp);
		
		sentinel.setNext(_new);
		
	}
	
	//Agregar al final de la lista
	public void AddEnd(T value) {
		node<T> tmp = sentinel;
		
		while(tmp.getNext()!=null) //recorre la lista, cuando llegue al final agrega el nuevo nodo (while sin llaves)
			tmp = tmp.getNext();
			tmp.setNext(new node<T>(value));
		
	}
	//AddEnd recursivo
	public void AddEndR(T value) {
		AddEndR(value,sentinel);			
		
	}
	
	private void AddEndR(T value,node<T> list) {
		if (list.getNext()==null) { //Si es nulo se agrega
			list.setNext(new node<T>(value));
			return;
		}
		AddEndR(value,list.getNext());
	}
	
	//Eliminar de la lista
	public node<T> remmove(T value){
		node<T> tmp = sentinel;
		while(tmp.getNext() != null){
			if (tmp.getNext().getValue().equals(value)) {
				tmp.setNext(tmp.getNext().getNext());
			}else {
				tmp = tmp.getNext();
			}
		}
		
		return null;
	}
	
	public boolean remove(T value) {
		node<T> tmp = sentinel;
		while(tmp.getNext() != null){
			if (tmp.getNext().getValue().equals(value)) {
				tmp.setNext(tmp.getNext().getNext());
			}else {
				tmp = tmp.getNext();
			}
		}
			
		return false; //No encontro el nodo a borrar
		
	}
	/////////Remover recursivo/////////////////
	
	public boolean remover(T value) {
		return remover(value,sentinel);
	}
	
	private boolean remover (T value, node<T> list) {
		if (list.getNext()==null) 
			return false; //No lo encontro
		
		if (list.getNext().getValue().equals(value)) {
			list.setNext(list.getNext().getNext());
			return true; //Si lo encontro
		}
		return remover (value, list.getNext());
	}

	//Buscar en la lista
	public node<T> search(T value) {
		
		return search(value,sentinel);
		
	}
	
	private node<T> search(T value, node<T>list) {
		if (list.getNext()==null) 
			return null;
		if (list.getNext().getValue().equals(value)) 
			return list.getNext();
		return search(value,list.getNext());
		
	}
	
	//Imprimir
	public void printer() {
		printer(sentinel);
	}
	
	
	public void pronter() {
		node<T> tmp=sentinel;
		while(tmp.getNext()!=null) {
			tmp=tmp.getNext();
			System.out.println(tmp.getValue());
		}
	}
	
	private void printer(node<T> tmp) {
		if (tmp.getNext()==null) {
			return;
		}else{
			System.out.println(tmp.getNext().getValue());
			printer(tmp.getNext());
		}
	}
	
	//Agrega despues de un valor
	public boolean AddLast(T value, T newvalue) {
		node<T> finder = search(value); //busca el valor
		if(finder != null)
			return AddLast(new node<T>(newvalue),finder);
		else
			return false;//no lo encontro
	}
	
	public boolean AddLast(T value,node<T> nodo) {
		node<T> finder = search(value);
		if(finder!=null)
			return AddLast(nodo,finder);//agrega el nodo
		else
			return false;
	}
	private boolean AddLast(node<T> nodo, node<T> list) {
		nodo.setNext(list.getNext());
		list.setNext(nodo);
		
		return true;
	}
	
	////Agrega antes de un valor /////////////
	public boolean AddBefore(T value, T newvalue) {
		node<T> tmp = sentinel;
		
		while(tmp.getNext()!=null && !tmp.getNext().getValue().equals(value))
			tmp = tmp.getNext();
		
		return (tmp.getNext()!=null)?AddLast(new node<T>(newvalue),tmp):false;
			
	}
	
	
	
	///////////////////////Metodos faltantes////////////////////////////////////////////////////////////////////////
	
	//Reindexar
		public void reindex() {
			node<T> tmp=sentinel;
			int cont=-1;
			
			while(tmp.getNext()!=null) {
				tmp=tmp.getNext();
				tmp.setIndex(++cont);
				//System.out.println(tmp.getIndex());
			}
		}
	
	
	
	//remover despues de un valor
	public boolean removeAfter(T value){
		node<T> finder = search(value);
		
		if(finder.getNext()!=null){
			return remover(finder.getNext().getValue());
		}else{
			return false;
		}
	}
	
	//Remover antes de un valor
	public boolean removeBefore(T value){
		node<T> tmp = sentinel;
		
		while(tmp.getNext()!=null && !tmp.getNext().getValue().equals(value))
			tmp=tmp.getNext();
			
		
		return remove(tmp.getValue());
			
	}
	
	//Remplazar
		public boolean replace(T value, T newvalue){
			node<T> tmp = sentinel;
			
			while(tmp.getNext()!=null && !tmp.getNext().getValue().equals(value))
				tmp=tmp.getNext();
			
			
			return AddLast(value,newvalue)&&remover(value);
			
		}
		
		//Obtener ultimo nodo
		public void getLast(){
			node<T> tmp = sentinel;
			
			while(tmp.getNext()!=null)
				tmp=tmp.getNext();
			
			System.out.println(tmp.getValue()); 
		}
		
		//Obtener primer nodo
		
			public void getFirst(){
				node<T> tmp = sentinel;
				
				if(tmp.getNext()!=null)
					System.out.println(tmp.getNext().getValue());
					
				
			}
		
	
	//Remover primer nodo
	public boolean removeFirst(){
		node<T> tmp = sentinel;
		
		if(tmp.getNext()!=null){
			return remover(tmp.getNext().getValue());
		}else{
			return false;
		}
	}
	
	//Remover ultimo nodo
	public boolean removeLast(){
		node<T> tmp = sentinel;
		
		while(tmp.getNext()!=null)
			tmp=tmp.getNext();
			
		return remover(tmp.getValue());
		
	}
	
		
	//Tama�o de la lista
	public void size(){
		node<T> tmp = sentinel;
		reindex();
		while(tmp.getNext()!=null){
			tmp=tmp.getNext();
			
		}
		
		System.out.println(tmp.getIndex());
		
	}
	
	
	//Esta vacio
	public boolean isEmpty(){
		node<T> tmp = sentinel;
		
		if(tmp.getNext()!=null)
			return true;
		
		return false;
		
	}
	
	//Indice del nodo
	public void indexOf(T value){
		node<T> finder = search(value);
		reindex();
		if(finder!=null){
			System.out.println(finder.getIndex());
		}
		
	}
	
	///Vaciar lista
		public void clear(){
			node<T> tmp = sentinel;
			
			while(tmp.getNext()!=null){
				tmp=tmp.getNext();
				remove(tmp.getValue());
				reindex();
			}	
		}

}