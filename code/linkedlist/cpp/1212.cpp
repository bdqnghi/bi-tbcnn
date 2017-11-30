#include "object.h"
#include "tdalist.h"
#include "dllnode.h"
#include "linkedlist.h"

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// Para tener la definición del NULL sin declarar más identificadores
// innecesarios
#include <stddef.h>

// Constructor por defecto de LinkedList
LinkedList::LinkedList(){
    head = NULL;
}
// Super Destructor de LinkedList, nótese que llamará al destructor
// de la clase DLLNode, que liberará todos los nodos siguientes...
LinkedList::~LinkedList(){
    if (head)
        delete head;
}
/* 
* Inserción en la lista
* En esta operación se consideran cuatro casos generales de inserción:
* (A) La Lista está Vacía
* (B) Se desea Insertar antes de head (pos = 0)
* (C) Se desea Insertar en Medio de la Lista
* (D) Se desea Insertar al Final (pos = ssize)
*/
bool LinkedList::insert(Object* data, int pos) {
    // Si se desa meter en una posición inválida
    if (pos < 0 || pos > ssize)
        return false; // Fracaso en esta Operación
    
    // Creación del Nodo que insertaremos en la lista
    DLLNode* neo = new DLLNode(data);
    
    if (!head) // La lista está vacía
        head = neo;
    else { // La Lista tiene elementos
        if (pos == 0){ // Desea insertar al principio de la lista
            // Enlace de neo a la lista
            head->setPrev(neo);
            neo->setNext(head);
            // Actualizar la cabeza
            head = neo;
        }else if (pos > 0 && pos < ssize){ // Desea Insertar en medio
            DLLNode* tmp = head;
            // Recorrer hasta la posición anterior a la que deseamos insertar
            for (int i=1; i<pos; i++)
               tmp = tmp->getNext();
            // Enlazar el Nodo neo
            neo->setPrev(tmp);
            neo->setNext(tmp->getNext());
            tmp->getNext()->setPrev(neo);
            tmp->setNext(neo);
        }else { // Desea insertar al final
            DLLNode* tmp = head;
            // Recorrer la Lista hasta el final
            for (int i=1; i<pos; i++)
               tmp = tmp->getNext();
            // Enlazar el Nodo neo
            tmp->setNext(neo);
            neo->setPrev(tmp);        
        }    
    }
    // Incremento del tamaño
    ssize++;
    // Éxito en la operación
    return true;
}
/*
* Búsqueda del índice (posición) de un objeto
* Para que esta operación tenga éxito es necesario que los objetos que sean
* insertados en la lista tengan bien definido el método equals, pues es este
* método el que determinará la igualdad de un objeto con otro.
*/
int LinkedList::indexOf(Object* other)const {
    DLLNode* tmp = head;
    for (int i=0; i < ssize; i++){
        // Compara cada uno de los elementos con el parámetro
        if (tmp->getData()->equals(other))
                return i;
        tmp = tmp->getNext();
    }    
    // En el caso de no encontrarlo
    return -1;
}
// Consigue el elemento index de la lista, si index es una posición válida
Object* LinkedList::get(unsigned index)const {
    if (index < 0 || index >= ssize)
        return NULL;
    DLLNode* tmp = head;
    for (int i=0; i < index; i++)
        tmp = tmp->getNext();
    return tmp->getData();
}
/*
* Borra un elemento de la lista, dada la posición del mismo. Se consideran
* tres casos:
* (A) El Elemento es la Cabeza
* (B) El Elemento es el Último
* (C) El Elemento está en Medio
* Es importante recalcar que para borrar un elemento es necesario primero
* desenlazarlo de la lista y luego liberar su memoria, pues en caso contrario
* liberaríamos todos los elementos siguiente a este elemento.
*/



Object* LinkedList::remove(unsigned pos) {
    
Object* ret = NULL;

// Si es una posición Inválida
    if (pos < 0 || pos >= ssize)
        return NULL; // Indicar fracaso en la operación
    DLLNode* tmp;
    if (pos == 0){ 

	ret = head->getData();
	head->setData(NULL);

// Desea Borrar la Cabeza
        // Desenlazar
        tmp = head->getNext();
        tmp->setPrev(NULL);
        head->setNext(NULL);
        // Liberar Memoria
        delete head;
        // Actualizar head
        head = tmp;
    }else if (pos == ssize - 1){ 


// Desea Borrar el último
        // Recorrer hasta el final
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->getNext();
        // Desenlazar
        DLLNode* toErase = tmp->getNext(); 

	ret = toErase->getData();
	toErase->setData(NULL);
  
        tmp->setNext(NULL);
        toErase->setPrev(NULL);
        // Liberar Memoria
        delete toErase;
    }else { // Desea Borrar de enmedio
        // Recorrer hasta el nodo anterior al que se desea borrar
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->getNext();
        // Desenlazar
        DLLNode* toErase = tmp->getNext();

	ret = toErase->getData();
	toErase->setData(NULL);

        tmp->setNext(toErase->getNext());
        toErase->getNext()->setPrev(tmp);
        toErase->setNext(NULL);
        toErase->setPrev(NULL);
        // Liberar Memoria
        delete toErase;        
    }
    ssize--; // Disminuir Tamaño
    return ret; // Indicar Éxito
}



// Retorna el anterior a la posición pos
// Implementado de la manera más sencilla, pues podría haberse usado
// DLLNode*
int LinkedList::prev(int pos) const {
    return pos - 1;
}
// Retorna el siguiente a la posición pos
// Implementado de la manera más sencilla, pues podría haberse usado
// DLLNode*
int LinkedList::next(int pos) const {
    return pos + 1;
}
// Elimina todos los elementos de la lista, coloca ssize en cero, y la cabeza
// en NULL, o sea que hace un poco más que el destructor.
void LinkedList::clear() {
    if (head)
        delete head;
    head = NULL;
    ssize = 0;
}
// Retorna el primer elemento de la lista, si es que hay alguno
Object* LinkedList::first()const {
    if (head)
        return head->getData();
    return NULL;
}
// Retorna el último elemento de la lista, si es que hay alguno
Object* LinkedList::last()const {
    if (!head)
        return NULL;
    DLLNode* tmp = head;
    for (int i=0; i < ssize-1; i++)
    { 
	//cout << "Vuelta dentro de last(): " << i << endl;
        tmp = tmp->getNext();
    }
    return tmp->getData();
}

// Imprime cada uno de los elementos que hay en la lista, llamando al método
// print de cada nodo.
void LinkedList::print()const {
    DLLNode* tmp = head;
    for (int i=0; i < ssize-1; i++){
        tmp->print();
        tmp = tmp->getNext();
    }    
}

// Retorna si la lista está llena, como nunca es así, retorna false siempre.
bool LinkedList::isFull()const {
    return false;
}
