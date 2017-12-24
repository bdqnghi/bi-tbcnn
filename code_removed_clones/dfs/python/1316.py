# -*- coding: utf-8 -*-
"""
Created on Sun Mar  3 20:09:30 2013

@author: sandra
"""

import cv

class Node: INDENT
    #Initialisierung der Knoten
    #Vorgaenger = NIL
    #Besucht = FALSE
    #Jeder Knoten erhaelt eine Nummer
    def __init__(self,features,i): INDENT
        self.nodenumber = i
        self.visited = False
        self.feature = features[i]
        self.predecessor = "nil"
        self.postdecessor = "nil"
        self.whichpath = "nil"
        self.distance = 0
        self.root = "nil"
        
DEDENT     def getPredecessor(self): INDENT
        return self.predecessor

DEDENT     def setPredecessor(self,predecessor): INDENT
        self.predecessor = predecessor
        
DEDENT     def setVisited(self): INDENT
        self.visited = True
        
DEDENT     def getVisitedState(self): INDENT
        return self.visited
        
DEDENT     def getFeaturePoint(self): INDENT
        return self.feature

#Finde den nächsten Knoten, der auch keinen Nachfolger hat. Diser
#Knoten darf aber nicht auf dem gleichen Pfad sein.        
DEDENT DEDENT def findNextFeature(node,remainingNodes): INDENT
    feature_of_node = node.feature
    distance_min = 10000
    distances = []
    distance = 0
    node_candidate = ""
    for n in remainingNodes: INDENT
        if n is not node: INDENT
            distance = ((feature_of_node[0]-n.feature[0])**2 + (feature_of_node[1]-n.feature[1])**2)**0.5
            distances.append((n,distance)) 
            #print node.feature, distances
DEDENT         for d in distances: INDENT
            node_d = d[0]
            node_dist = d[1]
            if node_dist < distance_min: INDENT
                distance_min = node_dist
                node_candidate = node_d
                n.distance = distance_min
                
            
        
DEDENT DEDENT DEDENT     return (distance_min,node_candidate)
        
DEDENT def getPath(goal,pathnumber): INDENT
    path_stack = []
    path_stack.append(goal)
    goal.whichpath = pathnumber
    while goal.predecessor is not "nil": INDENT
        goal = goal.predecessor 
        path_stack.append(goal)
DEDENT     return path_stack
    
DEDENT def getRoot(node): INDENT
    while node.predecessor is not "nil": INDENT
        node = node.predecessor
    
DEDENT     return node
        

DEDENT def findNeighbours(node,nodes,searchDistance): INDENT
    neighbours = []
    current = node.feature
    x = current[0]
    y = current[1]
    for n in nodes: INDENT
        if n.visited is False: INDENT
            x1 = n.feature[0]
            y1 = n.feature[1]
            if x1>=x-searchDistance and x1<=x or x1<=x+searchDistance and x1>=x: INDENT
                if y1>=y-searchDistance and y1<=y or y1<=y+searchDistance and y1>=y:         INDENT
                    neighbours.append(n)
                
DEDENT DEDENT DEDENT DEDENT     return neighbours

DEDENT def DFSVisit(node,nodes,searchDistance): INDENT
    node.setVisited()
    neighbours = findNeighbours(node,nodes,searchDistance)
    for neighbour in neighbours: INDENT
        if neighbour.visited is False: INDENT
            neighbour.predecessor = node
            node.postdecessor = neighbour
            DFSVisit(neighbour,nodes,searchDistance)     

DEDENT DEDENT DEDENT def DFS(nodes,searchDistance): INDENT
    for i in range(len(nodes)): INDENT
        if nodes[i].visited == False: INDENT
            DFSVisit(nodes[i],nodes,searchDistance)
DEDENT DEDENT     return nodes
            

#Hand-Features
DEDENT features = [(183.0, 225.0), (174.0, 177.0), (206.0, 245.0), (205.0, 185.0), (220.0, 176.0), (25.0, 224.0), (187.0, 191.0), (191.0, 170.0), (196.0, 235.0), (176.0, 160.0), (155.0, 168.0), (266.0, 128.0), (143.0, 25.0), (83.0, 49.0), (203.0, 71.0), (156.0, 93.0), (145.0, 44.0), (150.0, 68.0), (160.0, 109.0), (168.0, 132.0), (203.0, 133.0), (185.0, 213.0), (43.0, 227.0), (99.0, 250.0), (105.0, 97.0), (91.0, 69.0), (53.0, 231.0), (146.0, 250.0), (86.0, 245.0), (164.0, 122.0), (63.0, 235.0), (153.0, 81.0), (160.0, 243.0), (172.0, 149.0), (196.0, 154.0), (200.0, 144.0), (148.0, 58.0), (203.0, 116.0), (203.0, 94.0), (117.0, 252.0), (186.0, 201.0), (203.0, 106.0), (100.0, 87.0), (232.0, 170.0), (248.0, 154.0), (257.0, 142.0), (123.0, 132.0), (134.0, 150.0), (169.0, 235.0), (140.0, 158.0)]
#Person-Features
#features = [(156.0, 186.0), (148.0, 273.0), (90.0, 158.0), (216.0, 21.0), (170.0, 65.0), (161.0, 102.0), (161.0, 93.0), (158.0, 68.0), (131.0, 195.0), (161.0, 116.0), (159.0, 288.0), (160.0, 86.0), (151.0, 19.0), (156.0, 168.0), (151.0, 26.0), (165.0, 289.0), (150.0, 39.0), (166.0, 214.0), (178.0, 66.0), (159.0, 78.0), (156.0, 181.0), (166.0, 199.0), (209.0, 50.0), (76.0, 153.0), (160.0, 190.0), (156.0, 63.0), (103.0, 174.0), (127.0, 192.0), (94.0, 167.0), (205.0, 60.0), (156.0, 283.0), (66.0, 153.0), (143.0, 195.0), (158.0, 243.0), (153.0, 279.0), (111.0, 180.0), (81.0, 155.0), (152.0, 54.0), (162.0, 226.0), (115.0, 184.0), (151.0, 188.0), (192.0, 65.0), (214.0, 30.0), (156.0, 152.0), (155.0, 146.0), (151.0, 46.0), (159.0, 237.0), (155.0, 250.0), (151.0, 260.0), (213.0, 39.0)]
#features = [(156.0, 186.0), (148.0, 273.0), (90.0, 158.0), (216.0, 21.0), (170.0, 65.0), (161.0, 102.0), (161.0, 93.0), (158.0, 68.0), (131.0, 195.0), (161.0, 116.0)]
count = len(features)
img = cv.LoadImage("hand.jpg")
nodes = []
searchDistance = 20

#Zuordnung Features zu Knoten 
for i in range(count): INDENT
    nodes.append(Node(features,i))
    
DEDENT nodes = DFS(nodes,searchDistance)

path_list = []
pathnumber = 1
for i in range(len(nodes)): INDENT
    path = getPath(nodes[i],pathnumber)
    path_list.append((path,pathnumber))
    pathnumber = pathnumber + 1

DEDENT for node in nodes: INDENT
    node.root = getRoot(node)
    print "Knoten ", node.nodenumber, " hat Wurzel ", node.root.nodenumber

DEDENT remainingNodes = []
predecessors = []
#Pfade zeichnen und Knoten einzeichnen, die keinen Nachfolger haben   
color = 255
for path in path_list: INDENT
    for p in path[0]: INDENT
        x1 = int(p.feature[0])
        y1 = int(p.feature[1])
        if p.predecessor is not "nil": INDENT
            x2 = int(p.predecessor.feature[0])
            y2 = int(p.predecessor.feature[1])
            cv.Line(img, (x1,y1),(x2,y2), (color,color,color), thickness=2, lineType=8, shift=0)
DEDENT         if p.postdecessor is "nil": INDENT
            cv.Circle(img,(int(p.feature[0]),int(p.feature[1])),5,(255,0,255),thickness=2)
            remainingNodes.append(p)
        #if p.predecessor is "nil":
        #    cv.Circle(img,(int(p.feature[0]),int(p.feature[1])),5,(255,0,0),thickness=1)
        #    remainingNodes.append(p)
            

#print path_list
#Naechsten Nachbar finden, der keinen Nachfolger hat. 
DEDENT DEDENT DEDENT color = 50
color2 = 10
for node in remainingNodes: INDENT
    
    best_distance_candidate = findNextFeature(node,remainingNodes)
    #print best_distance_candidate
    #print best_distance_candidate
    candidate = best_distance_candidate[1]

#    if candidate.predecessor is not "nil" and node.root != candidate.root:
    if candidate.predecessor is not "nil" and node.root != candidate.root: INDENT
        best_cand = findNextFeature(candidate,remainingNodes)
        #Symmetrische Bedingung
        #if best_cand[1].nodenumber == node.nodenumber:
        cv.Line(img, (int(node.feature[0]),int(node.feature[1])),(int(candidate.feature[0]),int(candidate.feature[1])), (0,255,0), thickness=2, lineType=8, shift=0)
        candidate.root = node.root


DEDENT DEDENT cv.ShowImage("Image",img)
cv.SaveImage("hand-DFS-endergebnis.png",img)
cv.WaitKey()
