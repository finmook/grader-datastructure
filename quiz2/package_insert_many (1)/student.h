#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
//problem:insert many value into CP::vector in different position(according to before insert)
//solution: sort the parameter first then loop through new size and shift the position that have to add when add the value from parameter
//knowledge: custom comparator for compare pair, shift value
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data)
{
  // write your code here
  // std::sort(data.begin(), data.end(), [](const auto &a,const auto &b){ return a.first>b.first;});
  // for (int i = 0; i < data.size(); i++)
  // {
  //   insert_by_pos(data[i].first, data[i].second);
  // }
  size_t newSize=mSize+data.size();
  mCap=std::max(newSize,mCap*2);
  T *arr=new T[mCap]();
  std::sort(data.begin(), data.end(), [](const auto &a,const auto &b){ return a.first<b.first;});
  int j=0;
  int k=0;
  int shift=0;
  for(int i=0;i<newSize;i++){
    if(i==data[j].first+shift){
      arr[i]=data[j].second;
      j++;
      shift++;//increase position due to add out source data
      continue;
    }
    arr[i]=mData[k++];
  }
  delete [] mData;
  mData=arr;
  mSize=newSize;
}

#endif
