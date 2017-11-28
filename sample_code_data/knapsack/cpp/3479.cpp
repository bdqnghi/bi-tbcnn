#include <iostream>
#include <vector>

using std::vector;
using namespace std; 

int optimal_weight(int W, const vector<int> &w) {
  //write your code here  
  
  int current_weight = 0;
  vector<int> v(w); 
  vector<vector<int>>value(W+1,vector<int>(w.size()+1)); 
  
  for(int i =1; i <= w.size(); ++i){
	  for(int w_=1; w_<= W; ++w_){
		  value[w_][i] = value[w_][i-1];
		  if (w[i-1] <= w_){
			  current_weight = value[w_-w[i-1]][i-1] + v[i-1]; 
			  if (value[w_][i] < current_weight){
				  value[w_][i] = current_weight; 
			  }
		  } 	
	  }	  
  }
      
  return value[W][w.size()];
  
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
