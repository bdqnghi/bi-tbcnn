#include "mergesort.hpp"

using namespace std;

vector<parOrdenado> merge(const vector<parOrdenado>& left, const vector<parOrdenado>& right)
{
    vector<parOrdenado> result;
    unsigned left_it = 0, right_it = 0;
    while(left_it < left.size() && right_it < right.size())
    {
        if(left[left_it].razao > right[right_it].razao)
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }

    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}

vector<parOrdenado> mergesortvector(vector<parOrdenado>& vec)
{
    if(vec.size() == 1){
        return vec;
    }

    std::vector<parOrdenado>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<parOrdenado> left(vec.begin(), middle);
    vector<parOrdenado> right(middle, vec.end());
    left = mergesortvector(left);
    right = mergesortvector(right);

    return merge(left, right);
}

