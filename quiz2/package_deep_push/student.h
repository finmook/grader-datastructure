#ifndef __STUDENT_H_
#define __STUDENT_H_
//problem:insert value in the position which far from top of stack for top
//solution: create new arr pointer

template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  T *arr = new T[mSize+1]();
  int insertIdx=mSize-pos;//convert to normal index
  int j=0;//track mData
  bool isInserted=false;//already insert or not
  for (size_t i = 0;i < mSize+1;i++) {
    if(j==insertIdx&& !isInserted){
      arr[i]=value;
      isInserted=true;
      continue;
    }
    arr[i] = mData[j++];
  }
  delete [] mData;
  mData = arr;
  mCap = mSize+1;
  mSize+=1;
}

#endif
