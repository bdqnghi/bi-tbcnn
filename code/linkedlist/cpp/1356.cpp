
#include "linkedlist.h"
#include <iostream>

#ifndef NULL
#define NULL 0 //defino null
#endif 

namespace KangaParty
{

          
LinkedList::LinkedList()
{
	_length=0;
	_cursor=NULL;
}

LinkedList::~LinkedList()
{
    cout << "Se destruyo la casita Linked de los canguros. Se acabo la fiesta." << endl;
    _cursor->preDestroy();
	delete _cursor;
}


//Copia
LinkedList::LinkedList(const LinkedList& source)
{            
             _cursor=source._cursor;
            _length=source._length; 
            //cout << "se copia" << endl;
}

//Sobrecarga =
LinkedList& LinkedList::operator= (const LinkedList &source)
{
            
            if (this== &source)
            {
                       return *this;
            }
            _cursor=source._cursor;
            _length=source._length;
            //cout << "se sobrecarga" << endl;
            
            return *this;
}


int LinkedList::size()
{
    return this->_length;
}

void LinkedList::add(int index, Canguro * nuevoCang)
{
     
     if(index>=0 && index <=_length)
     {
         if (index==0)
         {
                      addFirst(nuevoCang);
                      _length++;
         }
         else
         {
             LinkedNode* tmp=_cursor;
             for(int i=0; i<index-1; i++)
        	{
                     tmp=tmp->getNext();
            }
            _length++;
            tmp->setNext(new LinkedNode(nuevoCang,tmp->getNext()));
         }
     }
     else
     {
          cout << "Error: Out Of Range" << endl;
          }
}
 
void LinkedList::addFirst(Canguro * nuevoCang)
{
     this->_cursor= new LinkedNode(nuevoCang,_cursor);
} 
 
Canguro LinkedList::get(int index)
{
        
        if( index >= 0 && index <_length)
        {
         LinkedNode* tmp= _cursor;
         for(int i=0; i<index; i++)
         {
                 tmp=tmp->getNext();
                 }
         return *tmp->getContent();
        }
        else
        {
            cout << "Error: Out of Range" << endl;
            return Canguro();
        }
}//=========================================================================================================

Canguro* LinkedList::getPointer(int index)
{
   if( index >= 0 && index <_length)
        {
         LinkedNode* tmp= _cursor;
         for(int i=0; i<index; i++)
         {
                 tmp=tmp->getNext();
                 }
         return &(*tmp->getContent());
        }
        
        else
        {
            cout << "Error: Out of Range" << endl;
            return NULL;
        }      
}

bool LinkedList::isEmpty()
{
     if(_length==0)
     {
     return true;
     }
     else
     {
         return false;
     }
 }
 
void LinkedList::remove(int index)
{
     if(index>=0 and index <_length)
     {
     
     
             if(index==0)
             {
              LinkedNode * tmp=_cursor;
              _cursor=_cursor->getNext();
              cout << "Se elimino al Canguro en la posicion " << index << " de la lista" << endl;
              (tmp->getContent())->printInfo(true);
              tmp->setNext(NULL);
              delete tmp;
             }
             else
             {
             LinkedNode * tmp=_cursor;
               for(int i=0; i<index-1;i++)
               {
                   tmp=tmp->getNext();    
               }
               LinkedNode* tmp1=tmp->getNext();
               tmp->setNext(tmp1->getNext());
               cout << "Se elimino al Canguro en la posicion " << index << " de la lista" << endl;
              (tmp1->getContent())->printInfo(true);
               tmp1->setNext(NULL);
               delete tmp1;
             }
             _length--;
             
     }
     else
     {
         cout << "Error: Out of Range" << endl;
     }
 }
 
void LinkedList::print(int index)
{
     if(index>=0 and index <_length)
     {
                 Canguro tmp=get(index);
     //cout << endl << "===Posicion "<<index<<": Puntero a direccion: " << canguroList[index] <<"==="<<endl;
     cout <<endl <<"     info: -id: "<<tmp.show("id")<<endl;
     cout <<"           -nombre: " <<tmp.show("nombre")<<"   -altura de salto: "<<tmp.show("jumpHeight")<<endl;
     }
     else
     {
         cout << "Error: Out of Range" << endl;
     }
}

void LinkedList::print()
{
     cout << "******************************************************"<< endl;
     cout << "POSICION\tID\t\tNOMBRE\t\tALTURA DE SALTO"<<endl;
     LinkedNode* tmp=_cursor;
     int post=0;
     while(tmp!=NULL)
     {
     cout << post++ << "\t\t";
     (tmp->getContent())->printInfo(false);    
     tmp=tmp->getNext();
     }
}

void LinkedList::printList()
{
     print();
 }
 
void LinkedList::consulta()
{
     int option = 0;
     cout << endl << "Desea consultar por Existencia(1) o por una Lista(2)? " << endl;
     cin>>option;
     
     if(option == 2) //============CONSULTA POR LISTA==================
     {
     
               cout << endl << "Elija un parametro de consulta\n  1: Nombre\n  2: Altura de salto\n  3: Ambos\n" << endl;
     
     
               cin >> option;
               if(option == 1)
               {
                string param = "";
                
                cout << endl << "Ingrese el nombre que busca"<< endl;
                cin >> param;
               
                cout << "******************************************************"<< endl;
                cout << "POSICION\tID\t\tNOMBRE\t\tALTURA DE SALTO"<<endl;
                LinkedNode* tmp=_cursor;
                int post=0;
                while(tmp!=NULL)
                {
                               
                                              if((tmp->getContent())->show("nombre")==param){ cout << post << "\t\t"; (tmp->getContent())->printInfo(false); }
                                              post++;    
                                              tmp=tmp->getNext();
                }
                cout << endl;
               }
               else if(option == 2)
               {
                double param = 0;
               
                cout << endl << "Ingrese la altura de salto que busca"<< endl;
                cin >> param;
               
                cout << "******************************************************"<< endl;
                cout << "POSICION\tID\t\tNOMBRE\t\tALTURA DE SALTO"<<endl;
                LinkedNode* tmp=_cursor;
                int post=0;
                while(tmp!=NULL)
                {                     
                               if((tmp->getContent())->getJH()==param){ cout << post << "\t\t"; (tmp->getContent())->printInfo(false); }
                               post++;    
                               tmp=tmp->getNext();
                }
               cout << endl;
               }
               else if(option == 3)
               {
                string param1 = "";
                double param2 = 0;
               
                cout << endl << "Ingrese el nombre que busca"<< endl;
                cin >> param1;
                cout << endl << "Ingrese la altura de salto que busca"<< endl;
                cin >> param2;
               
                cout << "******************************************************"<< endl;
                cout << "POSICION\tID\t\tNOMBRE\t\tALTURA DE SALTO"<<endl;
                LinkedNode* tmp=_cursor;
                int post=0;
                while(tmp!=NULL)
                {
                               
                               if((tmp->getContent())->show("nombre")==param1 && (tmp->getContent())->getJH()==param2){ cout << post << "\t\t"; (tmp->getContent())->printInfo(false); }
                               post++;    
                               tmp=tmp->getNext();
                }
               cout << endl;
               }
               else cout << "Opcion invalida, volviendo al menu" << endl << endl;
               return;
     }
     
     else if(option == 1) //================CONSULTA POR EXISTENCIA===============
     {
          cout << endl << "Elija un parametro de consulta\n  1: Nombre\n  2: Altura de salto\n  3: Ambos\n" << endl;    
          cin >> option;
     
          if(option == 1) 
          {
               string param = "";
               
               cout << endl << "Ingrese el nombre que busca"<< endl;
               cin >> param;
               
               LinkedNode* tmp=_cursor;
               int post=0;
               while(tmp!=NULL)
               {
                               
                               if((tmp->getContent())->show("nombre")==param){ cout << "Existe" << endl; return; }
                               post++;    
                               tmp=tmp->getNext();
               }
               cout << "No Existe";
               cout << endl;
          }
          else if(option == 2)
          {
               double param = 0;
               
               cout << endl << "Ingrese la altura de salto que busca"<< endl;
               cin >> param;
               
               LinkedNode* tmp=_cursor;
               int post=0;
               while(tmp!=NULL)
               {                     
                               if((tmp->getContent())->getJH()==param){ cout << post << "Existe" << endl; return;}
                               post++;    
                               tmp=tmp->getNext();
               }
               cout << "No Existe";
               cout << endl;
          }
          else if(option == 3)
          {
               string param1 = "";
               double param2 = 0;
               
               cout << endl << "Ingrese el nombre que busca"<< endl;
               cin >> param1;
               cout << endl << "Ingrese la altura de salto que busca"<< endl;
               cin >> param2;
               
               LinkedNode* tmp=_cursor;
               int post=0;
               while(tmp!=NULL)
               {
                               
                               if((tmp->getContent())->show("nombre")==param1 && (tmp->getContent())->getJH()==param2){ cout << "Existe" << endl; return; }
                               post++;    
                               tmp=tmp->getNext();
               }
               cout << "No Existe";
               cout << endl;
          }
          else cout << "Opcion invalida, volviendo al menu" << endl << endl;
          return;
     
     
     }
     
     else cout << "Opcion invalida, volviendo al menu" << endl << endl;
     
}



}
