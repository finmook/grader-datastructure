#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
//problem:when expand we not create arr and copy value in new arr but we create new arr according to value that we want
//so mData is vector of vector then we want to access mData normally like mData[3] but actually it is mData[][];
//solution: we store the mSize of total for that time of expand that we kept it in aux, we use upper_bound to get the first that
//have size more than we want then we use the before iterator to define the first [] then use the idx- value inside the before it
//to get the col
template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
  // int row,col;
  // for(int i=0;i<mData.size();i++){
  //   if(idx>=mData[i].size()) idx-=(mData[i].size());
  //   else{
  //     row=i;
  //     col=idx;
  //     break;
  //   }
  // }
  // return mData[row][col];
  auto it=upper_bound(aux.begin(),aux.end(),idx);
  int row=(it-1)-aux.begin();
  int col=idx-*(it-1);
  return mData[row][col];

}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
  aux.push_back(mSize);//store mSize each time expand
  

}

#endif
