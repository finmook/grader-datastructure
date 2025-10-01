#ifndef __STUDENT_H_
#define __STUDENT_H_
//problem:overwrite == of CP:queue
//solution: we compare size first then compare each data in each queue must all equal to return true
template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  //write your code here
  if(size()!=other.size()) return false;
  for(int i=0;i<mSize;i++){
    if(mData[(mFront+i)%mCap]!=other.mData[(other.mFront+i)%other.mCap]) return false;
  }
  return true;
  // YOU CANNOT CALL push or pop
}

#endif
