/* 
 * Project 10
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the knapsack cpp file and contains the methods for knapsack class
 *
 */
#include <iostream>
using std::ostream;
using std::endl;
using std::cout;
using std::copy;
#include <algorithm>
using std::sort;
using std::swap;
#include<vector>
using std::vector;
#include "knapsack.h"
/*
 * constructor function
 * sets weight limit,capacity, and allocates memory
 */
Knapsack::Knapsack(long max) {
  weight_limit_ = max;
  capacity_=10;
  size_=0;
  data_ = new Package[capacity_];
}
/* deconstructor function
 * Deletes data array
 */
Knapsack::~Knapsack(){
  delete [] data_;
}
/*
 * weight function
 * returns combined weight of all packages
 */
long Knapsack::weight() {
  long totalweight=0;
  for (int i = 0;i<size_;i++) {
    totalweight+=data_[i].weight_;
  }
  return totalweight;
}
/*
 * priority function
 * returns combined priority of all packages
 */
long Knapsack::priority() {
  long totalpriority=0;
  for (int i = 0;i<size_;i++) {
    totalpriority+=data_[i].priority_;
  }
  return totalpriority;
}
/*
 * empty function
 * returns true or false based on if data is empty
 */
bool Knapsack::empty() {
  return !size_;
}
/*
 * add function
 * adds package to data array and extends capacity if need be
 * returns true or false whether it was succesfully added
 *
 */
bool Knapsack::add(Package p) {
  if (weight()+p.weight_ > weight_limit_) {
    return false;
  } else {
    if ((capacity_ - size_) <= 0) {
      capacity_ *=2;
      Package *new_data = new Package[capacity_];
      copy(data_,data_+capacity_,new_data);
      swap(data_,new_data);
      delete [] new_data;
    }
    data_[size_++] = p;
    return true;
  }
  return false;
}
/*
 * friend operator for <<
 * returns ostream, basically outputs all content in knapsack
 */
ostream& operator<<(ostream &out, const Knapsack &ks) {
  out << "Knapsack - Weight Limit: "<<ks.weight_limit_<<" capacity: "<<ks.capacity_<<endl;
  for (int i = 0;i<ks.size_;i++) {
    out << "Package #"<<i<<", Weight: "<<ks.data_[i].weight_<<", Priority: "<<ks.data_[i].priority_<<endl;
  }
  return out;
}
/*
 * friend operator for solve_KS Algorithm 
 * takes a vector of packages, sorts them and inserts as many as possible into data_
 * returns void
 */
void solve_KS(vector<Package>& vp, Knapsack& k) {
  sort(vp.begin(),vp.end(),package_compare);
  for (auto vec : vp) {
    if (!k.add(vec)) 
      break;
  }
}
