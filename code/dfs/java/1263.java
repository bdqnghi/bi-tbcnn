package algorithm;

class DFS
   {
   private final int SIZE = 500;
   private int[] st;
   private int top;
  
// ------------------------------------------------------------
   public DFS()           // constructor
      {
      st = new int[SIZE];    // make array
      top = -1;
      }
// ------------------------------------------------------------
   public void push(int j)   // put item on stack
      { st[++top] = j; }
// ------------------------------------------------------------
   public int pop()          // take item off stack
      { return st[top--]; }
// ------------------------------------------------------------
   public int peek()         // peek at top of stack
      { return st[top]; }
// ------------------------------------------------------------
   public boolean isEmpty()  // true if nothing on stack
      { return (top == -1); }
// ------------------------------------------------------------
   }  // end class DFS
////////////////////////////////////////////////////////////////
class Vertex
   {
   public char label;        // label (e.g. 'A')
   public boolean wasVisited;
// ------------------------------------------------------------
   public Vertex(char lab)   // constructor
      {
      label = lab;
      wasVisited = false;
      }
// ------------------------------------------------------------
   }  // end class Vertex
////////////////////////////////////////////////////////////////
class Graph
   {
   private final int MAX_VERTS = 500;
   private Vertex vertexList[]; // list of vertices
   private int adjMat[][];      // adjacency matrix
   private int nVerts;          // current number of vertices
   private DFS theStack;
   public int n=81;
   public int  black;
   public int white; 
   public static int countblack;
   public static int countwhite;
   public int temp;
   
// ------------------------------------------------------------
   public Graph()               // constructor
      {
      vertexList = new Vertex[MAX_VERTS];
                                          // adjacency matrix
      adjMat = new int[MAX_VERTS][MAX_VERTS];
      nVerts = 0;
      for(int y=0; y<MAX_VERTS; y++)      // set adjacency
         for(int x=0; x<MAX_VERTS; x++)   //    matrix to 0
            adjMat[x][y] = 0;
      theStack = new DFS();
     
      }  // end constructor
// ------------------------------------------------------------
   public void addVertex(char lab)
      {
      vertexList[nVerts++] = new Vertex(lab);
      }
// ------------------------------------------------------------
   public void addEdge(int start, int end)
      {
      adjMat[start][end] = 1;
      adjMat[end][start] = 1;
      }
   
   
// ------------------------------------------------------------
   public void displayVertex(int v)
      {
      System.out.print(vertexList[v].label);
      }
// ------------------------------------------------------------
 
   public void beforedfs()//function that calls DFS
   {
        for(int i=0;i<81;i++)
      {if(vertexList[i].wasVisited == false)
        dfs(i);
      if (black==1 )//if black node then add its count to the counter for black
      {
          countblack+=temp;
      }
      else if (white==1)//if white then add the number of empty nodes
      {
          countwhite+=temp;
     }
      else if((white==1)&&(black==1));//if both black and white then do nothing
      black=0;
      white=0;
      temp=0;
      
      }
        System.out.println();
      System.out.println("white"+countwhite+ "black"+countblack);
      
   }
 
   public void dfs(int i)  // depth-first search
      {       
     
      // begin at vertex i
      vertexList[i].wasVisited = true;  // mark it
      System.out.println();
      displayVertex(i); 
       // display it
      theStack.push(i);                 // push it

              // {
          
         // get an unvisited vertex adjacent to stack top
      if   (vertexList[i].label=='B')
      {
          black=1;
           //theStack.pop();
      }
      else if (vertexList[i].label=='W')
      {
          white=1;
         //  theStack.pop();
      }
     
           else {
       int v = getAdjUnvisitedVertex( theStack.peek() );
        dfs(v);
       temp++;
      
         }  }// end while

      // stack is empty, so we're done
// ------------------------------------------------------------
   // returns an unvisited vertex adj to v
   public int getAdjUnvisitedVertex(int v)
      {
      for(int j=0; j<nVerts; j++)
         if(adjMat[v][j]==1 && vertexList[j].wasVisited==false)
            return j;
      return -1;
      }  
// ------------------------------------------------------------
   }  // end class Graph
////////////////////////////////////////////////////////////////
class DFSApp
   {
   public static void main(String[] args)
      {
          int n=9;
          char[][] mymatrix= {
              { 'B','E','B','E','E','E','E','E','E'}, 
              {'E','B','E','E','B','E','E','E','E'}, 
              {'B','E','B','B','B','B','E','E','E' },
              {'B','B','B','W','W','B','B','B','E' },
              {'B','B','W','E','E','W','W','B','E' },
              {'W','W','W','E','E','W','B','B','B' },
              {'E','E','E','W','E','W','W','B','B' },
              {'E','W','E','E','E','E','W','W','B' },
              {'E','E','E','E','E','W','W','W','W'}
      };
      Graph theGraph = new Graph();
      for (int i=0;i<9;i++)
      {
          for(int j=0;j<9;j++)
          {
              theGraph.addVertex(mymatrix[i][j]);
          }
      }

for(int i=0;i<9;i++)
{
    for(int j=0;j<8;j++)
    {
        theGraph.addEdge(j+(9*i),j+1+(9*i));
        theGraph.addEdge((i+(9*j)),(i+(9*(j+1))));
    }
}

      System.out.print("DFS traverses the tree in the following order: ");
     
      theGraph.beforedfs();             // depth-first search
      System.out.println();
      
    
   } } 
////////////////////////////////////////////////////////////////
