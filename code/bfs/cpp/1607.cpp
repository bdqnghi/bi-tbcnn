// Problem: Computing the Minimum Number of Flight Segments
// Problem Introduction
// You would like to compute the minimum number of flight segments to get from one city to another one. For
// this, you construct the following undirected graph: vertices represent cities, there is an edge between two
// vertices whenever there is a flight between the corresponding two cities. Then, it suffices to find a shortest
// path from one of the given cities to the other one.
// Problem Description
// Task. Given an undirected graph with n vertices and m edges and two vertices u and v, compute the length
// of a shortest path between u and v (that is, the minimum number of edges in a path from u to v).
// Input Format. A graph is given in the standard format. The next line contains two vertices u and v.
// Constraints. 2 ≤ n ≤ 10^5 , 0 ≤ m ≤ 10^5 , u != v, 1 ≤ u, v ≤ n.
// Output Format. Output the minimum number of edges in a path from u to v, or −1 if there is no path.

// Compile command:
// g++ -o bfs.exe bfs.cpp -std=c++11
// Execution command:
// ./bfs.exe tests/input*.txt

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::string;
using std::ifstream;
using std::endl;
using std::cout;

int distance(const vector<vector<int> > &adj, int s, int t) {
  // create empty set S
  // create empty queue Q
  //
  // add root to S
  // Q.enqueue(root)
  //
  // while Q is not empty:
  //     current = Q.dequeue()
  //     if current is the goal:
  //         return current
  //     for each node n that is adjacent to current:
  //         if n is not in S:
  //             add n to S
  //             n.parent = current
  //             Q.enqueue(n)
  int n = adj.size();
  vector<bool> visited(n, false);
  vector<int> parent(n, -1);
  std::queue<int> q;

  visited[s] = true;
  q.push(s);

  while (!q.empty()) {

    int current = q.front();
    q.pop();
    if (current == t) {
      break;
    }
    for (int n: adj[current]) {
      if (!visited[n]) {
        visited[n] = true;
        parent[n] = current;
        q.push(n);
      }
    }
  }

  int current = t, count = 0;
  // Traverse parent of t until it reaches s.
  while (true) {
    current = parent[current];
    count++;
    if (current == s) {
      return count;
    } else if (current == -1) {
      break;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Please provide a valid filename for testing." << endl;
  } else {
    ifstream fs;
    fs.exceptions(ifstream::failbit | ifstream::badbit);
    try {
      fs.open(argv[1]);

      // Original main
      int n, m;
      fs >> n >> m;
      vector<vector<int> > adj(n, vector<int>());
      for (int i = 0; i < m; i++) {
        int x, y;
        fs >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
      }
      int s, t;
      fs >> s >> t;
      s--, t--;
      std::cout << distance(adj, s, t) << endl;
    } catch (ifstream::failure& e) {
      std::cerr << "Exception opening/reading file" << endl;
    }
    fs.close();
  }
  return 0;

}
