#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {// this function store first k values of q in vector
  std::vector<T> res;
  //write your code only here
  //
  int front=mFront;//const make mFront can't change
  for(int i=0;i<k;i++){
    if(i==mSize) break;
    res.push_back(mData[front%mCap]);
    front++;
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {// this function is constructor  of queue with the value of from to before to
  //write your code only here
  mData = new T[to-from]();
  mCap=to-from;
  mSize=to-from;
  mFront=0;
  for(auto it=from;it!=to;it++){
    mData[(mFront+it-from)%mCap]=*it;//mData สูตรตามนี้ อย่าใช้ push
  }

}

#endif
