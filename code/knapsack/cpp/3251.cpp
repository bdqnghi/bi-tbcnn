#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<fstream>
#include<iomanip>
#include<ctime>
#include"knapsack.h"


using namespace std;


double *max_weight = 0; //max_weight
int *item_num = 0; // item numbering

double **original_weight = 0; //weight[o][i] o: object, i: item
double **original_profit = 0; //profit[o][i] o: object, i: item
double **original_profit_per_weight = 0; //profit[o][i] / weight[o][i]
double *original_q_j = 0; //q_j = max(profit[o][i] / weight[o][i])
int *original_x_check = 0; //desicion number
int *x_check = 0; //desicion number

double **weight = 0; //weight[o][i] o: object, i: item
double **profit = 0; //profit[o][i] o: object, i: item
double **profit_per_weight = 0; //profit[o][i] / weight[o][i]
double *q_j = 0; //q_j = max(profit[o][i] / weight[o][i])



void knapsack_file_read(char *file, int &item, int &ob){
	
	ifstream fin(file);
	if (!fin){
		cout << "cant open the file" << endl;
		exit(1);
	}
	fin >> item;
	fin >> ob;


	item_num = new int[item];
	weight = new double*[ob];
	profit = new double*[ob];
	profit_per_weight = new double*[ob];
	max_weight = new double[ob];
	q_j = new double[item];
	x_check = new int[item];
	for (int i = 0; i < item; i++){
		x_check[i] = 1;
	}
	for (int o = 0; o < ob; o++){
		fin >> max_weight[o];
		weight[o] = new double[item];
		profit[o] = new double[item];
		profit_per_weight[o] = new double[item];
		for (int i = 0; i < item; i++){
			fin >> weight[o][i];
			fin >> profit[o][i];
			profit_per_weight[o][i] = profit[o][i] / weight[o][i];
			item_num[i] = i;
		}
	}

	ofstream check1("weight_file_check.txt");
	for (int i = 0; i < item; i++){
		for (int o = 0; o < ob; o++){
			check1 << weight[o][i] << " ";
		}
		check1 << endl;
	}
	ofstream check2("profit_file_check.txt");
	for (int i = 0; i < item; i++){
		for (int o = 0; o < ob; o++){
			check2 << profit[o][i] << " ";
		}
		check2 << endl;
	}
	check1.close();
	check2.close();


	for (int i = 0; i < item; i++){
		int max = 0;
		for (int o = 0; o < Q_J; o++){
			if (profit_per_weight[max][i] < profit_per_weight[o][i]){
				max = o;
			}
		}
		q_j[i] = profit_per_weight[max][i];
	}

	original_weight = new double*[ob];
	original_profit = new double*[ob];
	original_profit_per_weight = new double*[ob];
	original_q_j = new double[item];
	original_x_check = new int[item];

	for (int o = 0; o < ob; o++){
		original_weight[o] = new double[item];
		original_profit[o] = new double[item];
		original_profit_per_weight[o] = new double[item];
		for (int i = 0; i < item; i++){
			original_weight[o][i] = weight[o][i];
			original_profit[o][i] = profit[o][i];
			original_profit_per_weight[o][i] = profit_per_weight[o][i];
		}

	}
	for (int i = 0; i < item; i++){
		original_q_j[i] = q_j[i];
		original_x_check[i] = x_check[i];
	}

	fin.close();
}

void sorting_profit_per_weight(int item, int ob){

	double min = 0.0;
	double temp_double;
	int temp_int;
	int k = 0;
	double **temp_array;

	//profit_per_weight and item_num sorting
	for (int i = 0; i < item; i++){
		for (int j = item - 1; j > i; j--){
			if (q_j[j - 1] > q_j[j]){
				temp_double = q_j[j];
				q_j[j] = q_j[j - 1];
				q_j[j - 1] = temp_double;


				temp_int = item_num[j];
				item_num[j] = item_num[j - 1];
				item_num[j - 1] = temp_int;
			}
		}

	}

	//weight sorting
	temp_array = new double *[ob];
	for (int o = 0; o < ob; o++){
		temp_array[o] = new double[item];
		for (int i = 0; i < item; i++){
			temp_array[o][i] = weight[o][i];
		}
	}

	for (int o = 0; o < ob; o++){
		for (int i = 0; i < item; i++){
			weight[o][i] = temp_array[o][item_num[i]];
		}
	}

	//profit sorting
	for (int o = 0; o < ob; o++){
		for (int i = 0; i < item; i++){
			temp_array[o][i] = profit[o][i];
		}
	}
	for (int o = 0; o < ob; o++){
		for (int i = 0; i < item; i++){
			profit[o][i] = temp_array[o][item_num[i]];
		}
	}

	//profit_per_weight sorting
	for (int o = 0; o < ob; o++){
		for (int i = 0; i < item; i++){
			temp_array[o][i] = profit_per_weight[o][i];
		}
	}
	for (int o = 0; o < ob; o++){
		for (int i = 0; i < item; i++){
			profit_per_weight[o][i] = temp_array[o][item_num[i]];
		}
	}

	for (int n = 0; n < ob; n++){
		delete[] temp_array[n];
	}
	delete[] temp_array;

}


void fitness(int y[], double fit[], int item, int ob){
	double *sum_profit = new double[ob];
	double *sum_weight = new double[ob];

	for (int o = 0; o < ob; o++){
		sum_profit[o] = 0.0;
		sum_weight[o] = 0.0;
	}

	/*int i = 0;
	for (int o = 0; o < ob; o++){
	for (i = 0; i < item; i++){
	sum_profit[o] += original_profit[o][i] * y[i];
	sum_weight[o] += original_weight[o][i] * y[i];
	}
	}
	i = 0;
	int flag = 0;
	for (int o = 0; o < Q_J; o++){
	if (sum_weight[o] > max_weight[o]){
	flag = 1;
	break;
	}
	}
	while (flag == 1){
	for (int o = 0; o < ob; o++){
	sum_profit[o] -= profit[o][i] * y[item_num[i]];
	sum_weight[o] -= weight[o][i] * y[item_num[i]];
	}
	y[item_num[i]] = 0;
	flag = 0;
	for (int o = 0; o < Q_J; o++){
	if (sum_weight[o] > max_weight[o]){
	flag = 1;
	break;
	}
	}
	i++;
	}*/
	int i = item - 1;
	for (; i >= 0; i--){
		int flag = 0;
		for (int o = 0; o < Q_J; o++){
			if (sum_weight[o] + original_weight[o][item_num[i]] * y[item_num[i]] > max_weight[o]){
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			for (int o = 0; o < ob; o++){
				sum_weight[o] += original_weight[o][item_num[i]] * y[item_num[i]];
				sum_profit[o] += original_profit[o][item_num[i]] * y[item_num[i]];
			}
		}
		else{
			break;
		}
	}
	for (; i >= 0; i--){
		y[item_num[i]] = 0;
	}

	for (int o = 0; o < ob; o++){
		fit[o] = sum_profit[o];
	}
	delete[] sum_weight;
	delete[] sum_profit;

}

void non_repair_fitness(int y[], double fit[], int item, int ob){
	double *sum_profit = new double[ob];
	double *sum_weight = new double[ob];

	for (int o = 0; o < ob; o++){
		sum_profit[o] = 0.0;
		sum_weight[o] = 0.0;
	}

	int i = 0;
	for (int o = 0; o < ob; o++){
		for (i = 0; i < item; i++){
			sum_profit[o] += original_profit[o][i] * y[i];
			sum_weight[o] += original_weight[o][i] * y[i];
		}
	}

	for (int o = 0; o < ob; o++){
		fit[o] = sum_profit[o];
	}
	delete[] sum_weight;
	delete[] sum_profit;

}


void repair_output(int item, int ob){
	ofstream fout_repair("repair.txt");
	fout_repair << fixed << setprecision(16);
	for (int i = 0; i < item; i++){
		fout_repair << q_j[i] << "\t" << item_num[i] << endl;
	}
	fout_repair.close();
}

void check_input_file_output(int y[], int item, int ob){

	ofstream fout_file("file.txt");
	double *fit = new double[ob];
	for (int i = 0; i < item; i++){
		fout_file << y[i] << " ";
	}
	fout_file << endl << endl;
	fitness(y, fit, item, ob);
	fout_file << fit[0] << " " << fit[1] << endl;
	for (int i = 0; i < item; i++){
		fout_file << y[i] << " ";
	}
	fout_file << endl << endl;

	for (int i = 0; i < item; i++){
		y[i] = i % 2;
	}
	for (int i = 0; i < item; i++){
		fout_file << y[i] << " ";
	}
	fout_file << endl << endl;
	fitness(y, fit, item, ob);
	fout_file << fit[0] << " " << fit[1] << endl;
	for (int i = 0; i < item; i++){
		fout_file << y[i] << " ";
	}
	fout_file << endl << endl;

	for (int i = 0; i < item; i++){
		y[i] = (i + 1) % 2;
	}
	for (int i = 0; i < item; i++){
		fout_file << y[i] << " ";
	}
	fout_file << endl << endl;
	fitness(y, fit, item, ob);
	fout_file << fit[0] << " " << fit[1] << endl;
	for (int i = 0; i < item; i++){
		fout_file << y[i] << " ";
	}
	fout_file << endl << endl;

	delete[] fit;
	fout_file.close();

}