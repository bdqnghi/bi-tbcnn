#include <iostream>
#include <stdlib.h>

class Vertex{
public:
	Vertex(){}
	Vertex(char name){
		this->name=name;
	}
	char getName(){
		return name;
	}
	void setName(char name){
		this->name=name;
	}
	void setClock(int clock){
		this->postClock=clock;
	}
	int getClock(){
		return postClock;
	}
	void setConnector(int connector){    //just like the property in C#
		if(connector>0)
			this->connector=connector;
		else
			throw connector;
	}
	int getConnector(){
		return connector;
	}
private:
	int postClock;
	int connector;
	char name;
};

int compare(const void *a,const void *b){
	Vertex *pa = (Vertex*)a;
	Vertex *pb = (Vertex*)b;
	return pb->getClock() - pa->getClock();
}

class Graph{
public:
	Graph(){}
	Graph(int **arc, Vertex *vertex, int n){
		this->connector=0;
		this->clock=0;
		this->num=n;
		this->vertex=new Vertex[n];
		for(int i=0;i<num;i++)
			this->vertex[i].setName(vertex[i].getName());
		this->visited=new bool[n];
		for(int i=0;i<num;i++){
			visited[i]=false;
		}
		this->arc=new int*[num];
		for(int i=0;i<num;i++)
			this->arc[i]=new int[num];
		for(int i=0;i<num;i++)
			for(int j=0;j<num;j++){
				this->arc[i][j]=arc[i][j];
			}
	}
	~Graph(){
		delete[] vertex;
		delete[] visited;
		for(int i=0;i<num;i++)
			delete[] *(arc + i);
	}
	void DFS(bool printVertex){									//depth first search
		for(int i=0;i<num;i++)
			visited[i]=false;
		for(int i=0;i<num;i++){
			if(visited[i]==false)
				connector++;
				explore(i,printVertex);
		}
		if(printVertex)
			std::cout << std::endl;
	}
	void Linearize(){
		DFS(false);
		Vertex *t_vertex=new Vertex[num];
		for(int i=0;i<num;i++){
			t_vertex[i].setClock(vertex[i].getClock());
			t_vertex[i].setName(vertex[i].getName());
		}
		qsort(t_vertex,num,sizeof(Vertex),compare);				//use the quickSort provided by system
		for(int i=0;i<num;i++)
			std::cout << ' ' << t_vertex[i].getName();
	}
private:
	void explore(int v,bool printVertex){
		if(printVertex)
			std::cout << ' ' << vertex[v].getName();
		visited[v]=true;
		vertex[v].setConnector(connector);
		clock++;
		for(int i=0;i<num;i++){
			if(arc[v][i]==1 && visited[i]==false)
				explore(i,printVertex);
		}
		clock++;
		postVisit(v);
	}
	void postVisit(int v){
		vertex[v].setClock(clock);
	}
private:
	Vertex *vertex;
	bool *visited;
	int **arc;
	int clock;
	int connector;
	int num;
};

int main(){
	try{
		
	}catch(int connector){
		
	}
	return 0;
}