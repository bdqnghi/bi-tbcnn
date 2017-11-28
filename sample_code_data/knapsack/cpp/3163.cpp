# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;



void knapsack(vector<int> wt,vector<int> pro,int cap,int &cur_p,int &cur_wt,vector<int> &cur_ass,int &max_p,vector<int> &best_ass)
{


	
	if(cur_p > max_p){
		
		max_p = cur_p;
		best_ass.clear();
		best_ass.resize(cur_ass.size());

		copy(cur_ass.begin(),cur_ass.end(),best_ass.begin());
	

	}

	
	for (int i = cur_ass[cur_ass.size()-1]+1; i <= pro.size(); i++) {


		if(cur_wt+ wt[i-1] <= cap){
			
	
			cur_p += pro[i-1];
	
			cur_ass.push_back(i);
		
			cur_wt += wt[i-1];
			

			knapsack(wt,pro,cap,cur_p,cur_wt,cur_ass,max_p,best_ass);

			cur_ass.pop_back();
			cur_p -= pro[i-1];
			cur_wt -= wt[i-1];

				
		}
	}
}



		

		

	
int main()
{

	int n,cap;
	cin >> n >> cap;

	vector<int> wt,pro,cur_ass,best_ass;

	int x,y;
	for (int i = 0; i < n; i++){
		
		cin >> x >> y;

		wt.push_back(x);
		pro.push_back(y);
	}

	int cur_p = 0;
	int cur_wt = 0;

	int max_p = 0;
	
	cur_ass.push_back(0);

	knapsack(wt,pro,cap,cur_p,cur_wt,cur_ass,max_p,best_ass);

	cout << max_p << endl;
	for (int i = 1; i < best_ass.size();i++){
		
		cout << best_ass[i] << " " ;
	
	}
	

	
	return 0;
}
