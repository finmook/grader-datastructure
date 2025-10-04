#ifndef __STUDENT_H_
#define __STUDENT_H_
//problem: mirror vector ex. {1,2,3,4}->{1,2,3,4,4,3,2,1}
//hints: the size is double of old size
//knoledge: create new arr pointer
//solution: create new arr pointer to store data
template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  T *arr=new T[mSize*2]();
  for(int i=0;i<mSize;i++){
    arr[i]=mData[i];
  }
  int j=mSize;
  for(int i=mSize-1;i>=0;i--){
    arr[j++]=mData[i];
  }
  delete [] mData;
  mData=arr;
  mSize*=2;
  mCap=mSize;
}

#endif
