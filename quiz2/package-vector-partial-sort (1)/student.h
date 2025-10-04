#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
//problem: sort only the postition that the iterators point to(sort using comp)
//solution:sort vector of iterator first then push each value of iterator which is inside pos into v then sort v using comp and change the value of each iterator in pos according to v
#include<vector>
#include<algorithm>
template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B
  sort(pos.begin(),pos.end());
  std::vector<T> v;
  for(auto x:pos){
    v.push_back(*x);//store real value of CP::vector
  } 
  sort(v.begin(),v.end(),comp);
  for(int i=0;i<pos.size();i++){
    *pos[i]=v[i];
  }
}

#endif
