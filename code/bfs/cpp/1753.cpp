//============================================================================
// Name        : BFS.cpp
// Author      : Christian Martinez
// Student ID  : 7354
// Description : A Breath First search algorithm
//============================================================================

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <stdlib.h>
using namespace std;

/*
 * Functions
 */
vector< vector<int> > readFile(string filename);
string promptInput();
void displayOutput();
void stringSplit(string str);
void displayBFS(vector< vector<int> >, int);
int promptVertex();
bool checkIfVertexIsVisited(int);

/*
 * Variables
 */
vector<int> strSplit;
int vertices;
vector<int> nDx;

int main() {
	string filename = promptInput();
	vector< vector<int> > ADJMatrix = readFile(filename);
	cout << "Read File." << endl;
	int vertex = promptVertex();
	cout << "Got vertex" << endl;
	displayBFS(ADJMatrix, vertex);
	return 0;
}
/*
 *prompts input for name of file.
 *@return filename
 */
string promptInput(){
	string filename;
	cout << "Enter Input File: " << endl;
	cin >> filename;
	return filename;
}

/*
 * reads the file from the filename and puts it into an array
 * @return vector;
 */
vector< vector<int> > readFile(string filename){
	ifstream inFile;
	string vrtxStr;
	inFile.open(filename.c_str());

	//get vertices
	getline(inFile, vrtxStr);
	vertices = atoi(vrtxStr.c_str());
	cout << "Vertices: " << vertices << endl;

	//initialize the contents to 0
	vector< vector <int> > A(vertices, vector<int>(vertices, 0));

	int aRow = 0;

	//Set up Matrix
	string edgeData;
	while(!inFile.eof()){
		getline(inFile, edgeData);
		stringSplit(edgeData);

		//add data to matrix
		for(int i = 0; i < vertices; i++){
			A[aRow][i] = strSplit[i];
		}
		aRow++;
	}
	return A;

}
/*
 * splits the string into int values. Stored into the strSplit Array.
 */
void stringSplit(string str){
	//clear array
	strSplit.clear();
	stringstream ss(str);
	string token;
	char delimiter = ' ';
	while(strSplit.size() != vertices){
		getline(ss, token, delimiter);
		int val = atoi(token.c_str());
		strSplit.push_back(val);
	}
}
/*
 * Prompts for the starting vertex:
 * @return starting vertex
 */
int promptVertex(){
	int vertex;
	cout << "Enter Starting Vertex: ";
	cin >> vertex;
	return vertex;
}
/*
 * Displays breath first traversal with an adjacency matrix and a starting vertex.
 * @param Adjacency Matrix
 * @param Starting Vertex
 */
void displayBFS(vector< vector<int> > matrix, int vertex)
{
	queue<int> queue;

	//add the starting vertex to the queue;
	queue.push(vertex);

	//while queue is not empty
	while(!queue.empty()){
		nDx.push_back(queue.front());
		for(int i = 0; i < vertices; i++){
			int a = matrix[queue.front()][i];
			if(a == 1){
				if(!checkIfVertexIsVisited(i)){
					queue.push(i);
				}
			}
		}
		queue.pop();

	}
	//print out BFS Traversal
	cout << "BFS Order: ";

	for(int j = 0; j < nDx.size(); j++){
		cout << nDx[j] << " -> ";
	}
}

/*
 * Checks if Node is visited.
 * @param vertex to check
 * @returns true or false
 */
bool checkIfVertexIsVisited(int vertex){
	for(int i = 0; i < nDx.size(); i++){
		if(nDx[i] == vertex){
			return true;
		}
	}
	return false;
}
//C:\Users\Chris\WorkSpace-C++\BFS\src\sample_t1.txt
/*
 */
