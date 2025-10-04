#ifndef __STUDENT_H__
#define __STUDENT_H__

#include<vector>
#include<algorithm>
template <typename T>
//problem: distribute data in mData of stack to kept in vector of vector the data must divide in equal part if not divisible it the smaller index of vector have more size
//ex. [1,2,3,4,5,6,7,8,9,10] if k=4 then must return [[1,2,3],[4,5,6],[7,8],[9,10]]
//warning: top stack is 1 for above example(in the example in sheet the top stack is on left but when you input the top of stack is on right(so the last idx of mData
//must insert first) )
//solution: kept the base amount of every vector then + 1 for each vector if there is remain.

std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  int base=mSize/k;//kept base size
  int left=mSize%k;//how many left
  int idx=mSize-1;//track index of mData !!!last idx is top of stack so it would come first in ans(according to problem sheet)
  std::vector<std::vector<T>> ret;
  for(int i=0;i<k;i++){
    std::vector<T> v;
    for(int j=0;j<base;j++){
      v.push_back(mData[idx--]);
    }
    if(left>0){//if still have remain
      v.push_back(mData[idx--]);//add the left value to vector
      left--;//add 1 of the remain so must decrease the amount of remain
    }
    
    ret.push_back(v);
    
  }
  
  return ret;
}
#endif
