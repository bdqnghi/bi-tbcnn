#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;

struct node {
  int erdos;
  vector<int> adj;
  node() : erdos(0){}
};

vector<node> graph;

int main(){
  int nodes,archs;
  ifstream in("input.txt");
  ofstream out("output.txt");
  queue<int> myqueue;

  in >> nodes >> archs;
  graph.resize(nodes);
  bool ary[nodes];

  for(int i=0; i<nodes; i++)
    ary[i] = false;

  for(int i=0; i<archs; i++){
    int index,value;
    in >> index >> value;
    graph[index].adj.push_back(value);
    ary[value] = true;
  }

  int max = 0;

  for(int i=0; i< nodes; i++){
    if(!ary[i]){
      myqueue.push(i);
      graph[i].erdos = 0;
      while(!myqueue.empty()){
	int cur = myqueue.front();
	myqueue.pop();
	for(int j=0; j<graph[cur].adj.size(); j++){
	  int tmp = graph[cur].adj[j];
	  if(graph[cur].erdos + 1 > graph[tmp].erdos)
	    myqueue.push(tmp);
	  graph[tmp].erdos = graph[cur].erdos + 1;
	  if(graph[tmp].erdos > max)
	    max = graph[tmp].erdos;
	}
      }
    }
  }
  
  out << max;


  in.close();
  out.close();

}
