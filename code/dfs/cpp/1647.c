#include <iostream>
#include <string>
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

void dfs(graph *gr);

void dfs_visit(graph *gr , vertex *u);

int TIME = 0 ;

void print_path(graph *gr);

int main(int argc , char * argv[])
{

	graph *gr = new graph();

	vertex *v1 = new vertex();
	vertex *v2 = new vertex();
	vertex *v3 = new vertex();
	vertex *v4 = new vertex();
	vertex *v5 = new vertex();
	vertex *v6 = new vertex();

	v1->element = "U";
	v2->element = "V";
	v3->element = "W";
	v4->element = "Z";
	v5->element = "Y";
	v6->element = "X";	
	

	
	gr->addVertex(v1);
	gr->addVertex(v2);
	gr->addVertex(v3);
	gr->addVertex(v4);
	gr->addVertex(v5);
	gr->addVertex(v6);

	gr->addEdge(v1,v2,1);
	gr->addEdge(v1,v6,1);
	gr->addEdge(v6,v2,1);
	gr->addEdge(v2,v5,1);
	gr->addEdge(v5,v6,1);
	gr->addEdge(v3,v5,1);
	gr->addEdge(v3,v4,1);
	gr->addEdge(v4,v4,1);
	
	cout<<"Printing the depth first tree :"<<endl;
	
	cout<<" "<<endl;
	dfs(gr);
	
	
	return 0;
	
	
}


void dfs(graph *gr)
{

	//for each vertex u E G.V
	for(int i = 0 ; i < gr->numVerticies; i++)
	{
		
		//u.color = white
		
		gr->verticies[i]->color = 1;
		
		//u.parent = NULL
		
		gr->verticies[i]->parent = NULL;
	
		//time = 0 ; is initialized at the top
		
	}
	
	//for each vertex u E G.V
	
	for(int i = 0 ; i < gr->numVerticies; i++)
	{
		//if u.color == white
		
		if (gr->verticies[i]->color == 1)
		{
		
			//DFS-VISIT(G , u)
			
		dfs_visit(gr , gr->verticies[i]);
	
		cout<<" "<<endl;
		
		}
		

	}

}

//DFS-VISIT(G,u)

void dfs_visit(graph *gr , vertex *u)
{
	
	//time = time + 1
	
	TIME = TIME + 1;
	
	//u.d = time
	
	int index = gr->indexOf(u);
	
	//u.d = time;means starting time = time
	
	gr->verticies[index]->start_time = TIME;
	
	//u.color = GRAY
	
	gr->verticies[index]->color = 2;
	
	
	//creating space for an array of vertex
	
	vertex ** arrofadjvert = (vertex**)malloc(sizeof(vertex)*gr->getsizeofadjVerticies(u));
	
	//assigning the arrays of adjacent vertex in to the 
	//newly formed vertex array
	
	arrofadjvert = gr->arrayofadjacentVertex(u);
	
		
		//foreach v E G.Adj[u]
		
		for(int i = 0 ; i< gr->getsizeofadjVerticies(u) ; i++)
	
	{
			//creating a new vertex
			
			vertex *v = new vertex();
			
			//assigning an element of the array of vertex to v
			
			v = arrofadjvert[i];
			
			//if v.color == white
			
			if(v->color == 1)
			{
			
				//v.parent = u 
				
				gr->verticies[gr->indexOf(v)]->parent = gr->verticies[index] ;
				
				//DFS-VISIT(G ,v)
				
				dfs_visit(gr,gr->verticies[gr->indexOf(v)]);
				
			}
	
	
	}
	//u.color = BLACK
	
	gr->verticies[gr->indexOf(u)]->color = 3;
	
	cout<<gr->verticies[gr->indexOf(u)]->element<<endl;
	
	//time = time + 1
	
	TIME = TIME + 1;
	
	//u.f = time
	
	gr->verticies[gr->indexOf(u)]->end_time = TIME;
	
}


