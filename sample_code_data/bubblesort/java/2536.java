package Algoritmos;


import EstructurasDeDatosDash.Link;
import EstructurasDeDatosDash.LinkList;
import org.junit.Test;

public class bubblesort {
	public static LinkList bubbleSort(LinkList lista){
		int x = lista.getTamaño();
		return bubbleSort2(lista,x-1);
	}
	private static LinkList bubbleSort2(LinkList lista, int nElements){
    	int in;//limite de comparacion izquierdo
    	int out;//limite de comparacion derecho
    	for (out = nElements; out>=1;out--){//comparacion de in con out
    		for (in = 0; in<out;in++){
    			//if (((String) ((Ingrediente) lista.obtenerPorPosicion(in).getDataT()).getNombre()).compareToIgnoreCase((String) ((Ingrediente) lista.obtenerPorPosicion(out).getDataT()).getNombre())>0){
				if(lista.getNodoEspecifico(in).getT().compareTo(lista.getNodoEspecifico(out).getT())>0){// si in es mayor
    				swap(in,out,lista);//intercambio en la lista
    			}
    		}}
    		return lista;

    	}
	public static void swap(int posicion1, int posicion2, LinkList lista) {
        Link link1 = lista.getNodoEspecifico(posicion1);
        Link link2 = lista.getNodoEspecifico(posicion2);
        Link temp = new Link(link1.getT());
        link1.setT(link2.getT());
        link2.setT(temp.getT());
    }

	public static void main(String[] args) {
		LinkList lista = new LinkList();
		lista.insertFirstLink(10);
		lista.insertFirstLink(5);
		lista.insertFirstLink(7);
		lista.insertFirstLink(2);
		lista.insertFirstLink(15);
		lista = bubbleSort(lista);
		lista.display();
	}
}
