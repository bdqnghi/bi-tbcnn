#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int v; //vertices
	list<int> *adj;
	public :
	Graph(int v);
	void addEdge(int v,int w);
	void BFS(int v);
};

Graph::Graph(int v){
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w); // Add w to v's list
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main(){
	 Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}