#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
#include<unordered_set>
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  T* data=new T[mCap]();
  std::unordered_set<T> s;
  int amount=mSize;
  int j=0;
  for(int i=0;i<amount;i++){
    if(s.find(mData[i])==s.end()){
      s.insert(mData[i]);
      data[j++]=mData[i];
    }
  }
  mData=data;
  resize(s.size());
}

#endif
