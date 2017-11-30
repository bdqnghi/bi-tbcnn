#include <iostream>


int knapsack() {
	int n;
	int k;
	std::cin >> n;
	std::cin >> k;
	int knapsack[n];
	for(int i = 0; i < n; i++) {
		std::cin >> knapsack[i];
	}
	int table[n+1][k+1];
	//sets up table
	for(int i = 0; i < k+1; i++) {
		table[0][i] = 0;
	}
	for(int i = 0; i < n+1; i++) {
		table[i][0] = 0;
	}
	//fills in table
	for(int row = 1; row < n + 1; row++) {
		//std::cout << "Row: " << row << std::endl;
		for(int column = 1; column < k + 1; column++) {
			int val = 0;
			if(table[row - 1][column] > val) {
				val = table[row - 1][column];
			}
			if(table[row][column - 1] > val) {
				val = table[row][column - 1];
			}
			int currentNum = knapsack[row - 1];
			if(column >= currentNum) {
				if(column % currentNum == 0) {
					val = column;
				} else if(table[row][column - currentNum] > 0) {
					int compareVal = table[row][column - currentNum] + currentNum;
					if(compareVal > val) {
						val = compareVal;
					}
				}
			}
			table[row][column] = val;
		}
		if(table[row][k] == k) {
			return k;
		}
	}

	return table[n][k];
	// for(int i = 0; i < n+ 1; i++) {
	// 	for(int j = 0; j < k + 1; j++) {
	// 		std::cout << table[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
}

int main() {
	int T;
	std::cin >> T;
	for(int i = 0; i < T; i++) {
		std::cout << knapsack() << std::endl;
	}

	return 0;
}