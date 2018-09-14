// bfs.java
// demonstrates breadth-first search
//////////////////////////////////////////////////////////////////
class Queue
  {
  private final int SIZE = 20;
  private int[] queArray;
  private int front;
  private int rear;
// --------------------------------------------------------------
  public Queue()
    {
    queArray = new int[SIZE];
    front = 0;
    rear = -1;
    }
// --------------------------------------------------------------
  public void insert(int j) // put item at rear of the queue
    {
    if(rear == SIZE-1)   // deal with wraparound
      rear = -1;
    queArray[++rear] = j;
    }
// --------------------------------------------------------------
  public int remove()  // take item from front of queue
    {
    int temp = queArray[front++];
    if(front == SIZE)  // deal with wraparound
      front = 0;
    return temp;
    }
// --------------------------------------------------------------
  public boolean isEmpty()
    {
    // A. Nothing has been inserted into the queue
    // B. Everything inserted into the queue has been "removed"
    return ( rear+1==front || (front+SIZE-1==rear) );
    }
// --------------------------------------------------------------
  }
//////////////////////////////////////////////////////////////////
class Vertex
  {
  public char label;         // e.g. 'A', 'B', etc
  public boolean wasVisited;
// --------------------------------------------------------------
  public Vertex(char lab)
    {
    label = lab;
    wasVisited = false;
    }
// --------------------------------------------------------------
  }
//////////////////////////////////////////////////////////////////
class Graph
  {
  private final int MAX_VERTS = 20;
  private Vertex vertexList[];      // list of vertices
  private int adjMat[][];           // adjacency matrix
  private int nVerts;               // current number of vertices
  private Queue theQueue;
// --------------------------------------------------------------
  public Graph()
    {
    // create graph
    vertexList = new Vertex[MAX_VERTS];
    // create adjacency matrix
    adjMat = new int[MAX_VERTS][MAX_VERTS];
    nVerts = 0;
    
    // populate adjacency matrix with zeros
    for(int j=0; j<MAX_VERTS; j++)
      for(int k=0; k<MAX_VERTS; k++)
        adjMat[j][k] = 0;
 
    // initialize queue
    theQueue = new Queue();
    }
// --------------------------------------------------------------
  public void addVertex(char lab)
    {
    vertexList[nVerts++] = new Vertex(lab);
    }
// --------------------------------------------------------------
  public void addEdge(int start, int end)
    {
    adjMat[start][end] = 1;
    adjMat[end][start] = 1;
    }
// --------------------------------------------------------------
  public void displayVertex(int v)
    {
    System.out.print(vertexList[v].label);
    }
// --------------------------------------------------------------
  public void bfs()  // breadth-first search
    {
    vertexList[0].wasVisited = true;  // mark first vertex
    displayVertex(0);                 // display it
    theQueue.insert(0);               // insert it into queue
    
    int v2;
    
    /* As long as there is a vertex in the queue, remove the next
       vertex in line (v1).  Try to find an unvisited neighbor and set
       that vertex to v2.  Insert v2 into the queue and repeat.
      */
 
    while( !theQueue.isEmpty() )
      {
      int v1 = theQueue.remove();
      while( (v2=getAdjUnvisitedVertex(v1)) != -1)
        {
        vertexList[v2].wasVisited = true;
        displayVertex(v2);
        theQueue.insert(v2);
        }
      }

    // queue is empty--> we're done (reset visited flags)
    for(int j=0; j<nVerts; j++)
      vertexList[j].wasVisited = false;
    }
// --------------------------------------------------------------
  // return an unvisited vertex adjacent to v
  public int getAdjUnvisitedVertex(int v)
    {
    for(int j=0; j<nVerts; j++)
      if(adjMat[v][j]==1 && vertexList[j].wasVisited==false)
        return j;
    return -1;
    }
// --------------------------------------------------------------
  }
//////////////////////////////////////////////////////////////////
class BFSApp
  {
  public static void main(String[] args)
    {
    Graph theGraph = new Graph();
    theGraph.addVertex('A');    // 0
    theGraph.addVertex('B');    // 1
    theGraph.addVertex('C');    // 2
    theGraph.addVertex('D');    // 3
    theGraph.addVertex('E');    // 4

    theGraph.addEdge(0, 1);     // AB
    theGraph.addEdge(1, 2);     // BC
    theGraph.addEdge(0, 3);     // AD
    theGraph.addEdge(3, 4);     // DE

    System.out.print("Visits: ");
    theGraph.bfs();
    System.out.println();
    }
  }
//////////////////////////////////////////////////////////////////
