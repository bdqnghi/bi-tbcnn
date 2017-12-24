from graph import Node, buildGraph

class FoundNodeException(Exception): INDENT
   pass

DEDENT def recursiveDepthFirst(node, soughtValue): INDENT
   try: INDENT
      recursiveDepthFirstWorker(node, soughtValue, set())
      return False
DEDENT    except FoundNodeException: INDENT
      return True

DEDENT DEDENT def recursiveDepthFirstWorker(node, soughtValue, visitedNodes): INDENT
   if node.value == soughtValue: INDENT
      raise FoundNodeException()

DEDENT    visitedNodes.add(node)

   for adjNode in node.adjacentNodes: INDENT
      if adjNode not in visitedNodes: INDENT
         recursiveDepthFirstWorker(adjNode, soughtValue, visitedNodes)


DEDENT DEDENT DEDENT def depthFirst(startingNode, soughtValue): INDENT
   ''' Using a stack. '''
   visitedNodes = set()
   stack = [startingNode]

   while len(stack) > 0: INDENT
      node = stack.pop()
      if node in visitedNodes: INDENT
         continue

DEDENT       visitedNodes.add(node)
      if node.value == soughtValue: INDENT
         return True

DEDENT       for n in node.adjacentNodes: INDENT
         if n not in visitedNodes: INDENT
            stack.append(n)
DEDENT DEDENT DEDENT    return False

DEDENT if __name__ == "__main__": INDENT
   vertices = ["A", "B", "C", "D", "E", "F"]
   edges = [("A","B"), ("B","C"), ("C","E"), ("E","D"), ("E","F"), ("D","B")]

   G = buildGraph(vertices, edges)
   print recursiveDepthFirst(G, "F")
   print recursiveDepthFirst(G, "G")

   print depthFirst(G, "F")
   print depthFirst(G, "G")
DEDENT 
