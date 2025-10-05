#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
// #include<iostream>
//problems:เป็นการลบ vector ตามช่วงที่เก็บใน iterator first ถึงก่อน iterator second แต่ละตัวใน vector ranges
//solution: create new arr normally kept data from mData but when it is in the range we have to jump the index to 
//the index of last value of that range and then increase ranges index.
//warning: some ranges are full overlapse such as [2,5),[3,4) so when we increase index of ranges we must increase
//index 2 times
#include "vector.h"
#include<algorithm>
template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  int amount=0;
  T *arr=new T[mCap]();
  std::sort(ranges.begin(),ranges.end());
  int i=0;
  int j=0;
  int k=0;
  while(i<mSize){
    while(k<ranges.size()&& i>=(ranges[k].second-begin())) k++;//logic to increase ranges' index for full overlapse case
    if(k<ranges.size() && i>=(ranges[k].first-begin()) && i<(ranges[k].second-begin())){
      i=(ranges[k].second-begin());
      // std::cout<<"shift:"<<i<<std::endl;
      k++;
      continue;
    }
    arr[j++]=mData[i++];
    amount++;
  }
  mSize=amount;
  delete [] mData;
  mData=arr;
}

#endif
