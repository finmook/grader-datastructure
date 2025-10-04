#ifndef __STUDENT_H_
#define __STUDENT_H_
// #include<iostream>
//problem: overide operator < of CP:vector 
//solution: use if else for cases(show cases in code comments)
template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
  if(empty()&&(!other.empty())) return true;//case: me empty other not empty
  if((!empty())&&(!other.empty())){//case:both are not empty
    if(mData[0]<other.mData[0]) return true;//case:first value is less than
    if(mData[0]==other.mData[0]){//case: first value equal
      for(int i=1;i<mSize;i++){//loop to find whether our data will less than other data
        if(i>=other.mSize) return false;//if all equal and the size of our vector is more than other data so me<other will be false
        if(mData[i]<other.mData[i]) return true;//if our data < other data return true;
        if(mData[i]>other.mData[i]) return false;//if our data less than other data return false
      }
      // std::cout<<"check"<<std::endl;
      if(mSize<other.mSize) return true;//case: our size is less than other size but all elements before are equal.
    }
  }
  return false;//other than those cases return false
}


#endif
