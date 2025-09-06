#ifndef __STUDENT_H_
#define __STUDENT_H_
//problem:implement queue that can use q[idx] to access data
//solution: change the negative idx to positive idx first
template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  //
  if(idx<0) idx=mSize+idx;//if idx like -1 can access the last element
  return mData[(mFront+idx)%mCap];
  // you need to return something
  // return 
}

#endif
