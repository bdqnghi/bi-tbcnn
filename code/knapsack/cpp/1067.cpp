#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>

using namespace std;

vector<int> values; // vector of the profits
vector<int> capacities; // vector of the capacities
vector<vector<int> > solution_DP; //table

void pick(int i, int w)
{
	if (i <= 0 || w <= 0) return;

	int k = solution_DP[i][w];
	if (k != solution_DP[i - 1][w]) {
		cout << i << " ";
		// The table case had changed which means that in this step we have chosen the element
		pick(i - 1, w - capacities[i]);
	} else {
		// The capacity didn't change we didn't pick any item
		pick(i - 1, w);
	}
}

int main()
{

  clock_t begin = clock();

  int W, N;
  int st, vt;

  capacities.push_back(-1);
  values.push_back(-1);

  ifstream fichier("bigI.txt");
  if (fichier){
    string curseur;

    if (curseur!= " "){
      fichier>> W >> N;
      cout<<"We have a total number of items of : "<<N<<"  with a knapsack of total
      capacity :  "<<W<<endl;}
    for(int i=1; i<=N ; ++i){
      fichier >> vt >> st;
      capacities.push_back(st);
      values.push_back(vt);
      cout<<"item :   "<<i<<"      profit :   "<<values[i]<<"     capacity : "
      <<capacities[i]<<endl;
      }
    fichier.close();
    }
    else{cout<<" CAN'T OPEN THE FILE ! :( "<<endl;} //cerr

 	solution_DP.resize(N +1, vector<int>(W +1, 0));

 for (int i = 1; i <= N; i++) { //we are in layer i
		for (int w = 1; w <= W; w++) {
			if (capacities[i] > w) {
				solution_DP[i][w] = solution_DP[i - 1][w];
			} else {
				solution_DP[i][w] = max(solution_DP[i - 1][w], values[i] + solution_DP[i - 1][w - capacities[i]]);
	}
		}

	}

	cout<<"The maximum profit found using dynamic programming is : "<<endl;
	cout<<solution_DP[N][W]<<endl;
	cout << "The selected items are : ";
	pick(N, W);
	cout<<endl;
	cout<<": ) "<<endl;

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

cout<<"Execution time :"<<time_spent<<endl;
}
