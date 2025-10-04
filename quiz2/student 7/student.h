#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
//problem:give vector of CP:vector:iterator every iterator that it give make all element in it unique(near mData[0] kept if redundant but more idx delete)
//solution: sort iterator that give and kept real element value in set if already found we insert it in v after that we loop backward in v to erase element
//special knoledge: sort vector that contain iterator
#include "vector.h"
#include<set>
#include<vector>
#include<algorithm>
template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  // Write code here
  std::vector<CP::vector<T>::iterator> v;//kept erased iterator
  std::sort(itrs.begin(),itrs.end(),std::less<decltype(begin())>{});// can sort normally if CP:vector override operator <
  std::set<T> s;//kept unique value
  for(auto x:itrs){
    if(s.find(*x)==s.end()) s.insert(*x);//never found this value before
    else v.push_back(x);//kept iterator in v in order to delete later
  }
  for(int i=v.size()-1;i>=0;i--){
    erase(v[i]);
  }


}

#endif
