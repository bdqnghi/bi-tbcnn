#include "mergesort.hpp"
#include <cstring>

#define MERGESORT_DEBUG

#ifdef MERGESORT_DEBUG
#include <iostream>
using std::cout;
using std::endl;
#endif // MERGESORT_DEBUG

void devide(int* arr, unsigned int size)
{
    // Base case:

    if(size == 1)
        return;

    // Recursive case:

    unsigned int r = size - 1;
    unsigned int q = r / 2;

    unsigned int sub_size_1 = q + 1;
    unsigned int sub_size_2 = size - sub_size_1;

    devide(arr, sub_size_1);
    devide(arr + q + 1, sub_size_2);
    merge(arr, sub_size_1, arr + q + 1, sub_size_2);
}

void merge(int* sub_arr_1, unsigned int sub_size_1, int* sub_arr_2, unsigned int sub_size_2)
{
    // Creating & initializing temporary arrays:

    int* temp_sub_arr_1 = new int[sub_size_1];
    int* temp_sub_arr_2 = new int[sub_size_2];
    memcpy(temp_sub_arr_1, sub_arr_1, sizeof(int)*sub_size_1);
    memcpy(temp_sub_arr_2, sub_arr_2, sizeof(int)*sub_size_2);

    #ifdef MERGESORT_DEBUG
    cout << "Merging the following sub-arrays:" << endl;
    for(int i = 0; i < sub_size_1; i++)
        cout << temp_sub_arr_1[i] << " ";
    cout << endl;
    for(int i = 0; i < sub_size_2; i++)
        cout << temp_sub_arr_2[i] << " ";
    #endif

    // Iterating through the temporary arrays and changing the original
    // array, which is (sub_arr_1 + sub_array_2):

    unsigned int left_shift = 0;
    unsigned int right_shift = 0;

    int* original = sub_arr_1;
    unsigned int origin_shift = 0;
    unsigned int origin_size = sub_size_1 + sub_size_2;

    while(origin_shift != origin_size)
    {
        int* curr_origin_el = original + origin_shift;

        // 1. Checking if one of the arrays has ended:
        if(left_shift >= sub_size_1)
        {
            if(right_shift < sub_size_2)
            {
                for(int i = right_shift; i < sub_size_2; i++)
                {
                    *curr_origin_el = *(temp_sub_arr_2 + i);
                    origin_shift++;
                    curr_origin_el = original + origin_shift;
                }
            }
            break;
        }
        else if(right_shift >= sub_size_2)
        {
            if(left_shift < sub_size_1)
            {
                for(int i = left_shift; i < sub_size_1; i++)
                {
                    *curr_origin_el = *(temp_sub_arr_1 + i);
                    origin_shift++;
                    curr_origin_el = original + origin_shift;
                }
            }
            break;
        }

        // 2. Otherwise, comparing elements:

        if(*(temp_sub_arr_1 + left_shift) <= *(temp_sub_arr_2 + right_shift))
        {
            *curr_origin_el = *(temp_sub_arr_1 + left_shift);
            origin_shift++;
            left_shift++;
        }
        else
        {
            *curr_origin_el = *(temp_sub_arr_2 + right_shift);
            origin_shift++;
            right_shift++;
        }
    }

    #ifdef MERGESORT_DEBUG
    cout << endl;
    cout << "Resulting array: " << endl;
    for(int i = 0; i < origin_size; i++)
        cout << original[i] << " ";
    cout << endl;
    cout << "_______________________" << endl;
    #endif

    delete[] temp_sub_arr_1;
    delete[] temp_sub_arr_2;
}
