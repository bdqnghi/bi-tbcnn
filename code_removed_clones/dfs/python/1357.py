#It is an implementation of depth first search

class node: INDENT
    def __init__(self): INDENT
        self.children=dict()
        self.element=0



DEDENT DEDENT def find_element(element_to_find, stack): INDENT
    if  len(stack) < 1: INDENT
        return ""
DEDENT     ptr=stack.pop();
    if ptr.element==element_to_find: INDENT
        return ptr
DEDENT     else:       INDENT
        for i in ptr.children: INDENT
            child=ptr.children[i]
            stack.append(child)
DEDENT DEDENT     return find_element(element_to_find, stack)


#code below is for initiliazing the tree for bfs search
DEDENT stack=list()
root= node()
root.children[1]=node()
root.children[1].element=1
root.children[2]=node()
root.children[2].element=2
root.children[1].children[1]=node()
root.children[1].children[1].element=3
stack.append(root)
a= find_element(3, stack)
if a: INDENT
    print a.element 
DEDENT else: INDENT
    print "not found"    
DEDENT 
