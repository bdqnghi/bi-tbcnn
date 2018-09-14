#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

int optimal_weight_v1(int W, const vector<int> &w) {
	//write your code here
	int current_weight = 0;
	for (size_t i = 0; i < w.size(); ++i) {
		if (current_weight + w[i] <= W) {
			current_weight += w[i];
		}
	}
	return current_weight;
}

int optimal_weight_util(int target, const vector<int> &w, int n_size, map<int,int> dict ) {
	//write your code here
	int values;
	// find W in the pair
	if (dict.count(target) > 0) {
		return dict[target];
	}
	
	// W NOT in the pair
	dict[target] = 0;
	int v_i = 1;
	for (int i = 0; i < n_size; i++) {
		if (w[i] < target) {
			values = optimal_weight_util(target- w[i], w, i-1, dict) + v_i;
			if (values > dict[target]) {
				dict[target] = values;
			}
		}
		
	}
	
	dict[target] = values;
	
	return dict[target];
}

int optimal_weight(int target, const vector<int> &w) {
	int n_size = w.size();
	// sort w
	sort(w.begin(), w.end());
	
	map<int, int> dict;	
	return optimal_weight_util(target, w, n_size, dict);
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
