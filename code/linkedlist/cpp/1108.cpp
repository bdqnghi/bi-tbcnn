#include <iostream>
#include <string>
#include <iomanip>
#include "linkedlist.h"

using namespace std;

Node::Node() {
  data = 0;
  next = NULL;
  initialized = 1;
}

Node *create() {
  return new Node();
}

void write_list(Node *head) {
  Node *cur = head;

  if (! cur->initialized) {
    cout << "Uninitialized";
  }
  else {
    while (cur->next != NULL) {
      cout << cur->data << " ";
      cur = cur->next;
    }
    cout << cur->data << " ";
  }
}

void read_list(Node *head, int m_size, ifstream &inputFile) {
  Node *cur = head;
  int i=0;
  float elt;
  
  if (! cur->initialized) {
    cur=new Node();
  }
  for (i = 0; i < m_size*m_size; i++) {
    inputFile >> elt;
    cur->data = elt;
    cur->next = new Node();
    cur=cur->next;
  }
}



void write_column(Column *column, int m_size) {
  // float elt;
  // for (int i = 0; i < m_size; i++) {
  //   if (column==NULL) {
  //     elt = 0.00;      
  //   }
  //   else {
  //     cout << "P";
  //     elt = column->c == i ? column->data : 0;
  //     column=column->next;
  //   }
  //   cout << elt << " ";
  // }
}

void read_matrix(SparseMatrix *m, int m_size, ifstream &inputFile) {

  // float elt;
  // Row *row = m->rows;
  // Column *column = row->columns;
  // Column *temp;
  // int i, j;

  // for (i = 0; i < m_size; i++) {
  //   column = row->columns;
  //   cout << "Row " << i << ": ";
  //   for (j = 0; j < m_size; j++) {
  //     inputFile >> elt;
  //     if (elt != 0) {
  //       if (column == NULL)  {
  //         column = new Column(j, elt);
  //         cout << "N";
  //       }
  //       else {
  //         temp = new Column(j, elt);
  //         column->next = temp;
  //         column = column->next;
  //         cout << "X";
  //       }
  //     }
  //     else {
  //       cout << "z";
  //     }
  //   }
  //   write_column(row->columns, m_size);
  //   row = row->next;
  //   cout << endl;
  // }
}



void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size) {
  cout << "unimplemented" << endl;
}

