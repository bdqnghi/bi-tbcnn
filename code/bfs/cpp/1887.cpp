#include <iostream>
using namespace std;

#define MAXN 1000

void convert();
void make_empty();
void push(int x);
void BFS(int r);
void forest();
bool not_empty();
int pop();

int tree_height = 0;
int Q[MAXN], b, e;
int U[MAXN], P[MAXN];
int vertices, edges;
int m[MAXN][MAXN] = {0};


int main()
{
   cin >> vertices >> edges;  
   convert();
   BFS(1);
  // forest();
   for (int z = 1; z <= vertices; ++z)
      cout << z << " " << P[z] << endl;
   cout << "ST height: " << tree_height << endl;
}
void forest()
{
   int i;
   for (i = 1; i<= vertices; ++i)
   {
      if(P[i] == 0)
      {
	 BFS(i);
      }

      
   }
   cout << "NOT CONNECTED!" << endl;
}
void BFS(int r)
{
   int x,y,i,level;
   make_empty();
   push(r);
   U[r] = 1;
   P[r] = -1;
   level = r;
   while (not_empty())
   {
      x = pop();
      for ( i = 1; i <= m[x][0]; ++i)
      {
	 y = m[x][i];
	 if (!U[y])
	 {
	    push(y);
	    U[y] = 1;
	    P[y] = x;
	 }
      }
      if (level == x)
      {
	 level = Q[e];
	 cout << level << endl;
	 tree_height++;
      }
   }

}

void convert()
{
   int a, b, i;
   for ( i = 0; i < edges; i++ )
   {
      cin >> a >> b;

      m[a][++m[a][0]] = b; 
      m[b][++m[b][0]] = a; // if the graph is directed comment this line 

   }

}

void make_empty()
{
   b = 0;
   e = -1;
}

void push(int x)
{
   Q[++e] = x;
}

int pop()
{
   return Q[b++];
}

bool not_empty()
{
   return b <= e;
}
