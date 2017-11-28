#include "mergesort.h"
#include <sys/timeb.h>

std::vector<int> MergeSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    this->recSort(&array, 0, array.size()-1);

    ftime(&end); // end timer
    this->time = (end.time - start.time)*1000;
    this->time=(this->time+end.millitm-start.millitm)/1000;

    return array;
}

std::vector<int>* MergeSort::recSort(std::vector<int>* array, int left, int right){
    if(right - left < 1)
        return array;

    //split the array into two other arrays
    int ls = left;              //left array start
    int le = ((left+right)/2);    //left array end
    int rs = le+1;                //right array start
    int re = right;             //right array end

    //sort the left array
    this->recSort(array, ls, le);
    //sort the right array
    this->recSort(array, rs, re);
    //merge arrays into one again
    this->merge(array, ls, le, rs, re);

    return array;
}

std::vector<int>* MergeSort::merge(std::vector<int>* array, int ls, int le, int rs, int re){
    int lsize = le-ls+1; //left array size
    int rsize = re-rs+1; //right array size

    std::vector<int> la(lsize); //left array copy
    std::vector<int> ra(rsize); //right array copy

    for(int i=ls, j=0;i<=le;i++, j++) la[j] = (*array)[i];
    for(int i=rs, j=0;i<=re;i++, j++) ra[j] = (*array)[i];

    int li=0, ri=0, i=ls; //left, right and main indexes

    for(;i<re && li<lsize && ri<rsize;i++){
        if(la[li] < ra[ri])
            (*array)[i] = la[li++];
        else{
            (*array)[i] = ra[ri++];
            this->nSwaps += 1;
        }
        this->nComparisons += 1;
    }

    for(;li<lsize;i++, li++) (*array)[i] = la[li];
    for(;ri<rsize;i++, ri++) (*array)[i] = ra[ri];

    return array;
}
