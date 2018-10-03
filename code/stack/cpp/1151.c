
#define all(c) (c).begin(), (c).end()
#define tr(c,x) for(typeof(c).begin() x=(c).begin();x!=(c).end();x++)
typedef vi vector<int>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class node { 
   public:
      int x,y; 
      node(int a=0,int b=0) { x=a; y=b; }
};

// 
// DFS Search using Stack 
// Ref: http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=graphsDataStrucs2#depth
//
int doFill(int limx, int limy) {

   int result = 0;

   int fill[limx][limy];

   for ( int i=0; i<limx; i++)
      for ( int j=0; j<limy; j++)
         fill[i][j] = 0;


   stack<node> s;
   s.push(node(0,0));

   while( !s.empty() ){

      node top = s.top(); s.pop();
      
      if ( top.x < 0 || top.x >= limx ) continue;
      if ( top.y < 0 || top.y >= limy ) continue;
      if ( fill[top.x][top.y]==1 )      continue;

      fill[top.x][top.y]=1;

      result++;

      s.push(node(top.x+1,top.y));
      s.push(node(top.x,top.y+1));
      s.push(node(top.x-1,top.y));
      s.push(node(top.x,top.y-1));
   }

   return result;
}

int main(){

   cout << doFill(400,600) << endl; 

   return 0;
}
