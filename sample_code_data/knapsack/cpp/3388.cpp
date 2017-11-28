#include<bits/stdc++.h>
using namespace std;
#define LIM 100
#define MAXCAPACITY 100

int knapsack[LIM][MAXCAPACITY];

int Knapsack_Solver(int weight[], int value[], int n, int capacity) {
	int i, j;

	for(i = 0 ; i <= n ; i++)
		knapsack[i][0] = 0;

	for(i = 1 ; i <= n ; i++) {
		for(j = 0 ; j <= capacity ; j++) {
			if(weight[i] <= j) {
				knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-weight[i]] + value[i]); 
			}else{
				knapsack[i][j] = knapsack[i-1][j];
			}
		}
	}
	return knapsack[n][capacity];
}

int main() {
	int no_of_items, max_weight;
	int weight_item[LIM], value_item[LIM];

	printf("This Program computes the maximum value that can be stored in a knapsack from a given set of items i.e 0-1 Knapsack Problem\nEnter No of Items: ");
	scanf("%d",&no_of_items);
	
	printf("Enter maximum weight that knapsack can hold: ");
	scanf("%d",&max_weight);

	printf("Enter value and weight of each item: \n");
	for(int i = 1 ; i <= no_of_items ; i++) {
		scanf("%d%d",&value_item[i], &weight_item[i]);
	}

	printf("Result: %d\n",Knapsack_Solver(weight_item, value_item, no_of_items, max_weight));
	return 0;
}