#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::pair;
using std::make_pair;

void solveByPairOfVW (const vector<int> &v, 
		      const vector<int> &w, 
		      const int maxWeight, 
		      vector<int> &s);

void solveByTraditionalDP(const vector<int> &v, const vector<int> &w, const int, vector<int> &s);

//0-1 knapsack
// n items, value {v1,v2,...vn}, weight {w1, w2, ... wn}
// s1 indicate if item1 is selected or not, {0, 1}
// maxV= sum of Sn*Vn, constraint sum of Sn*Wn <= W
int main()
{

  vector<int> v;
  vector<int> w;
  vector<int> s;
  int maxWeight;
  int maxValue;
  ifstream inputFile;
  string line;
  int number;

  inputFile.open("data.txt");
  if (!inputFile)
    {
      cout<<"No Input File"<<endl;
    }
  
  getline(inputFile, line);
  istringstream stream(line);
  while (stream >> number)
    v.push_back(number);
  getline(inputFile, line);
  istringstream stream2(line);
  while (stream2 >> number)
    w.push_back(number);

  getline(inputFile, line);
  istringstream stream3(line);
  stream3 >> maxWeight;
  
  inputFile.close();
  int i = 1;
  for(vector<int>::const_iterator p = v.begin(); p != v.end(); p++, i++)
    cout<<"V["<<i<<"]="<<*p<<" ";
  cout<<endl;
  i = 1;
  for(vector<int>::const_iterator p = w.begin(); p != w.end(); p++, i++)
      cout<<"W["<<i<<"]="<<*p<<" ";
  cout<<endl<<"MaxWeight:"<<maxWeight<<endl;

  // method 1:from Chinese: Fundenmentals of computer algorithm
  solveByPairOfVW(v, w, maxWeight, s);

  // method 2:using Normal DP
  solveByTraditionalDP(v, w, maxWeight, s);
  
  return 0;
}

void solveByPairOfVW (const vector<int> &v, 
		      const vector<int> &w, 
		      const int maxWeight, 
		      vector<int> &s)
{
  vector< pair<int, int> > pwPair;
  pair<int, int> tempPair(0, 0);
  vector<int> endPoint;
  int i;

  pwPair.push_back(tempPair);  
  endPoint.push_back(0);

  
  int start, end;
  
  int k ,r;

  int next = 1;
  for (i = 1; i <= v.size(); i++)
    {
      k =  i>1?(endPoint[i-2]+1):0;
      end = endPoint[i-1];
      start = k;
      for (r = start; r <= end && pwPair[r].second + w[i-1] <= maxWeight; r++)
	{
	  tempPair = make_pair(pwPair[r].first+v[i-1], pwPair[r].second+w[i-1]);
	  while (k <= end && pwPair[k].second < tempPair.second)
	    {
	      pwPair.push_back(pwPair[k]);
	      next++;
	      k++;
	    }
	  if (k <= end && pwPair[k].second == tempPair.second)
	    {
	      tempPair.first = tempPair.first > pwPair[k].first ? tempPair.first: pwPair[k].first;
	      k++;
	    }

	  if (tempPair.first > pwPair[next-1].first)
	    {
	      pwPair.push_back(tempPair);
	      next++;
	    }
	      
	  // Discard some pair
	  while (k <= end && pwPair[k].first <= tempPair.first)
	    k++;
	}
      // Copy left S{i-1} -> S{i}
      while (k <= end)
	{
	  pwPair.push_back(pwPair[k]);
	  next++;
	  k++;
	}
      endPoint.push_back(next-1);
    }
  
  cout<<endl;
  for (vector< pair<int,int> >::const_iterator p = pwPair.begin(); 
       p != pwPair.end(); 
       p++)
    {
      cout<<" ["<<p->first<<","<<p->second<<"]";
    }  
   cout<<endl;
  i = 0;
  for (vector<int>::const_iterator p = endPoint.begin(); 
       p!=endPoint.end(); 
       p++)
    cout<<"["<<i++<<":"<<*p<<"]";
  cout<<endl;
}
void solveByTraditionalDP (const vector<int> &v, 
			   const vector<int> &w, 
			   const int maxWeight, 
			   vector<int> &s)
{
  int i, j;
  vector< vector<int> > maxValue;
  for (j = 0; j <= v.size(); j++)
    {
      maxValue.push_back(vector<int>(maxWeight+1, 0));
    }

    for (i = 1; i <= v.size(); i++)
    {
      for (j = 1; j <= maxWeight; j++)
	{
	  if (j>=w[i-1] 
	      && v[i-1]+maxValue[i-1][j-w[i-1]] > maxValue[i-1][j])
	    maxValue[i][j] = v[i-1]+maxValue[i-1][j-w[i-1]];
	  else
	    maxValue[i][j] = maxValue[i-1][j];
	}
    }
    cout<<endl<<"MaxValue we can achieved is :"<<maxValue[v.size()][maxWeight]<<endl;
    
    int weight = maxWeight;
    for (i = v.size(); i > 0; i--)
      {
	if (maxValue[i][weight] == maxValue[i-1][weight])
	  {
	    cout<<" V["<<i<<"]"<<0;
	  }
	else
	  {
	    cout<<" V["<<i<<"]"<<1;
	    weight -= w[i-1];
	  }
      }
}
