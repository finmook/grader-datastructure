#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  int pos=position-begin();
  ensureCapacity(size()+last-first);
  
  for(int i=mSize-1;i>=pos;i--){
    mData[i+last-first]=mData[i];
  }
  int j=0;
  for(int i=pos;i<pos+last-first;i++){
    mData[i]=*(first+j);
    j++;
  }
  mSize=size()+last-first;

  
  // vector<T> temp1;
  
  // auto it=position;
  
  // for(it;it!=end();it++){
  //   temp1.push_back(*it);
  // }
  // resize(size()+last-first);
  // int j=0;
  // auto it2=first;
  // for(auto it=position;it!=end();it++){
  //   if(it>position+last-first){
  //     this->at(i)=temp1[j];
  //     j++;
  //   }
  //   this->at(i)=*it2;
  //   it2++;
  // }


}

#endif
