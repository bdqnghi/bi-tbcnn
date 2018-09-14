/*
11.2.14 Knapsack Problem
11603990735 DanDanTan

Eureka moment
- when if (cur_volume < T), we recursive call FillKnapsack function (that means we wanna come back there).

Requirement

*/
#include <iostream>
#include <fstream>
#include <vector>

//#define TEST 1

std::vector<int> w;
int T;
std::vector<int> knapsack;
int p = 0;

// we need to fill the knapsack (total volume is T)
// we already have prev (picked_idx + 1) stuffs and the total volume of them is cur_volume
void FillKnapsack(int cur_volume, int picked_idx)
{
	for (int i = picked_idx + 1; i < w.size(); ++i)
	{
		// push stack
		cur_volume += w[i];
		knapsack.push_back(i);
		++p;

		// judge
		if (cur_volume < T)
		{
			FillKnapsack(cur_volume, i);
		}
		else if (cur_volume > T)
		{
		}
		else // cur_weight == T
		{
			std::cout << "( ";
			for (int j = 0; j < p; ++j)
				std::cout << w[knapsack[j]] << " " ;
			std::cout << ")" << std::endl;
		}

		// pop stack
		cur_volume -= w[i];
		knapsack.pop_back();
		--p;
	}
}

int main()
{
#if TEST

	w.push_back(1);
	w.push_back(8);
	w.push_back(4);
	w.push_back(3);
	w.push_back(5);
	w.push_back(2);
	T = 10;

#else

	// read testcase from file
	std::ifstream sequences;
	sequences.open("data.in");

	if (!sequences.is_open())
		return -1;

	int buf;
	sequences >> buf;
	T = buf;

	while (!sequences.eof())
	{ 
		sequences >> buf;
		w.push_back(buf);
	}

	sequences.close();

#endif

	FillKnapsack(0, -1);

	return 0;
}