#include "Stack.h"

Stack::Stack()
{
  top=-1;  
  size=5; 
  p = new int[size]; 
              
}

Stack::Stack(int s)
{
  size=s; 
  top=-1;
  p=new int[s]; 
                 
}

bool Stack::isEmpty()
{
  if(top==-1)
  {
   return true;
   }
   else 
   return false;   
              
}

void Stack::push(int value) 
{  
  if(top<size)
  {
  top++;
  p[top]=value;
  }
  else
  {
  int* temp = new int[2*size];
  for(int i=0;i<size;i++)
    {
    temp[i]=p[i];
    }
   delete[] p;
   p=temp;
   }
}


int Stack::pop()
{
 return p[top--];           
}


                 
