# Graph Word ladder problem: Building the Word Ladder Graph

# Author: Pradeep K. Pant, ppant@cpan.org
# Ref: http://interactivepython.org/runestone/static/pythonds/Graphs/BuildingtheWordLadderGraph.html

# let’s consider the following puzzle called a word ladder. Transform the 
# word “FOOL” into the word “SAGE”. In a word ladder puzzle you must make 
# the change occur gradually by changing one letter at a time. At each step 
# you must transform one word into another word, you are not allowed to 
# transform a word into a non-word. 
# The following sequence of words shows one possible solution to the problem posed above.
#FOOL
#POOL
#POLL
#POLE
#PALE
#SALE
#SAGE
# There are many variations of the word ladder puzzle. For example you might 
# be given a particular number of steps in which to accomplish the transformation, 
# or you might need to use a particular word. In this section we are interested in 
# figuring out the smallest number of transformations needed to turn the starting word 
# into the ending word.

# This is impemented using dictionary

# The labels on the buckets we have just described are the keys in our 
# dictionary. The value stored for that key is a list of words. Once we 
# have the dictionary built we can create the graph. We start our graph by 
# creating a vertex for each word in the graph. Then we create edges 
# between all the vertices we find for words found under the same key in the dictionary 

# Import vertex and Graph class
# Vetex class
class Vertex:
    # constructor simply initializes the id, which will typically be a string
    # and the connectedTo dictionary
    def __init__(self,key): 
        self.id = key
        self.connectedTo = {}
    # add a connection from this vertex to another
    def addNeighbor(self,nbr,weight=0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id) + ' connectedTo: ' + str([x.id for x in self.connectedTo])
    # returns all of the vertices in the adjacency list, as represented by the 
    # connectedTo instance variable
    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id
    # returns the weight of the edge from this vertex to the vertex passed as a parameter
    def getWeight(self,nbr):
        return self.connectedTo[nbr]

# Grpah class
# The Graph class, contains a dictionary that maps vertex names to vertex objects.
# Graph() creates a new, empty graph.
class Graph:
    def __init__(self):
        self.vertList = {}
        self.numVertices = 0
    # adds an instance of Vertex to the graph
    # addVertex(vert)
    def addVertex(self,key):
        self.numVertices = self.numVertices + 1
        newVertex = Vertex(key)
        self.vertList[key] = newVertex
        return newVertex
    # finds the vertex in the graph named vertKey.
    # getVertex(vertKey)
    def getVertex(self,n):
        if n in self.vertList:
            return self.vertList[n]
        else:
            return None

    def __contains__(self,n):
        return n in self.vertList
    # Adds a new, directed edge to the graph that connects two vertices
    # addEdge(fromVert, toVert)
    # addEdge(fromVert, toVert, weight) Adds a new, weighted, directed edge to 
    # the graph that connects two vertices.
    def addEdge(self,f,t,cost=0):
        if f not in self.vertList:
            nv = self.addVertex(f)
        if t not in self.vertList:
            nv = self.addVertex(t)
        self.vertList[f].addNeighbor(self.vertList[t], cost)
    # getVertices() returns the list of all vertices in the graph.
    def getVertices(self):
        return self.vertList.keys()

    def __iter__(self):
        return iter(self.vertList.values())


def buildGraph(wordFile):
    d = {}
    g = Graph()
    wfile = open(wordFile,'r')
    # create buckets of words that differ by one letter
    for line in wfile:
        word = line[:-1]
        for i in range(len(word)):
            bucket = word[:i] + '_' + word[i+1:]
            if bucket in d:
                d[bucket].append(word)
            else:
                d[bucket] = [word]
    # add vertices and edges for words in the same bucket
    for bucket in d.keys():
        for word1 in d[bucket]:
            for word2 in d[bucket]:
                if word1 != word2:
                    g.addEdge(word1,word2)
    return g
#BFS begins at the starting vertex s and colors start gray to show that 
# it is currently being explored. Two other values, the distance and the 
# predecessor, are initialized to 0 and None respectively for the starting
# vertex. Finally, start is placed on a Queue. The next step is to begin 
# to systematically explore vertices at the front of the queue. We explore 
# each new node at the front of the queue by iterating over its adjacency 
# list. As each node on the adjacency list is examined its color is 
# checked. If it is white, the vertex is unexplored, and four things happen:
# 1. The new, unexplored vertex nbr, is colored gray.
# 2. The predecessor of nbr is set to the current node currentVert
#The distance to nbr is set to the distance to currentVert + 1
#nbr is added to the end of a queue. Adding nbr to the end of the queue 
# effectively schedules this node for further exploration, but not until all the other vertices on the adjacency list of currentVert have been explored.

def bfs(g,start):
  start.setDistance(0)
  start.setPred(None)
  # need to import the queue class we have made 
  vertQueue = Queue()
  vertQueue.enqueue(start)
  while (vertQueue.size() > 0):
    currentVert = vertQueue.dequeue()
    for nbr in currentVert.getConnections():
      if (nbr.getColor() == 'white'):
        nbr.setColor('gray')
        nbr.setDistance(currentVert.getDistance() + 1)
        nbr.setPred(currentVert)
        vertQueue.enqueue(nbr)
    currentVert.setColor('black')

# final breadth first search tree after all the vertices have been expanded. 
# The amazing thing about the breadth first search solution is that we have 
# not only solved the FOOL–SAGE problem we started out with, but we have 
# solved many other problems along the way. We can start at any vertex in 
# the breadth first search tree and follow the predecessor arrows back to 
# the root to find the shortest word ladder from any word back to fool. 
# The function below shows how to follow the predecessor links to print out the word ladder.    
def traverse(y):
    x = y
    while (x.getPred()):
        print(x.getId())
        x = x.getPred()
    print(x.getId())

traverse(g.getVertex('sage'))

