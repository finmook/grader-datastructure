#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING
//problem: get the value from set but the first value of set is top of stack
//solution: loop backward to copy value from set
//knowledge:: std::distance(first,last) for any iterator,prev(it),max must compare same type(ex. size_t and size_t)


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  mSize=std::distance(first,last);
  size_t n=1;//want mCap to be at least 1
  mCap=std::max(n,mSize);
  mData=new T[mCap]();
  int i=0;
  auto it=--last;
  for(it;it!=std::prev(first);it--){
    mData[i++]=*it;
  
  }
}

#endif
