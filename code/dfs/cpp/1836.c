#include <set>
#include <map>
#include <time.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Graph {

  map<int, set<int> > graph;

  bool search (int src, int dest);

  // implementation specific data structure
  map<int, int> visited; // keep track of the visited nodes

  public:
    bool addNode (int i);
    bool addEdge (int src, int dest);
    bool doesPathExist (int src, int dest);
    void print();

};

bool Graph::addNode (int i) {
  set<int> edges;
  graph[i] = edges;
  return true;
}

bool Graph::addEdge (int src, int dest) {
  graph[src].insert(dest);
}

bool Graph::doesPathExist(int src, int dest) {

  // conduct a dfs through the graph
  // and try to find if the dest is in the
  // path of not

  visited.clear();
  return search (src, dest);

  return false;
}

bool Graph::search (int src, int dest) {

  if (!visited[src]){
    // on visit, do this ....
    set<int>& edges = graph[src];

    set<int>::iterator iter =
      edges.find(dest);

    if (iter != edges.end())
      return true;
  } else
    return false;

  visited[src] = 1;

  // now search the adjacents
  set<int>::iterator iter = graph[src].begin();
  for (;iter != graph[src].end();iter++){
    bool ret = search(*iter, dest);
    if (ret)
      return true;
  }

  return false;
}

void Graph::print() {
  // for all nodes
  for (int i = 0;i < 10;i++) {
    cout << "Node " << i
         << "'s adjacent nodes" << endl;
    cout << "=======================" << endl;

    // print the adjacent nodes ...
    set<int>::iterator iter = graph[i].begin();
    for (;iter!= graph[i].end();iter++) {
      cout << "\t" << *iter << endl;
    }// print this node

  }// for all nodes
}


int main (int argc, char* argv[]) {

  Graph g;
  srand (time(NULL));

  //add some nodes
  for (int i = 0;i < 10;i++)
    g.addNode(i);

  // add some edges
  for (int i = 0;i < 10;i++) {
    for (int j=0;j<4;j++) {
      int edge = rand()%10;
      g.addEdge(i,edge);
    }
  }

  // print the graph
  g.print();


  cout << "Search for adjacent" << endl;

  cout << "Input Source" << endl;
  int src;
  cin >> src;

  while (true) {
    cout << "Input Destination" << endl;
    int dest;
    cin >> dest;

    bool exist = g.doesPathExist(src, dest);

    cout << "Edge " << ((exist) ? "Exists" : "does not exist") << endl;
  }
}
