#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<vector>
template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  if(last==first) return;
  vector<T> v;
  k%=(last-first);
  for(int i=0;i<k;i++){
    v.push_back(*(first+i));
  }
  int idx=0;
  int count=0;
  for(auto it=first;it<last;it++){
    if(count<last-first-k){
      *it=*(it+k);
      count++;
    }
    else{
      *it=v[idx++];
    }
    
  }
}

#endif
