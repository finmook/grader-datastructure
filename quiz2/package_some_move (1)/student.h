#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>
//problem: insert the value in vector in our CP::vector but our CP::vector is like vector some move
//solution: shift the value to the the right then insert(not optimal solution)
template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  // std::vector<std::vector<T>> mData2;
  // size_t newSize=
 
  int j=(mSize-1);
  ensureCapacity(mSize+value.size());
  int newSize=mSize+value.size();
  int i=newSize-1;
  while(j>=index){
    (*this)[i--]=(*this)[j--];
  }
  
  int vidx=value.size()-1;
  while(vidx>=0){
    (*this)[i--]=value[vidx--];
    
  }
  mSize=newSize;

}

#endif