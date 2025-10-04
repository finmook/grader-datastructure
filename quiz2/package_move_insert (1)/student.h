#ifndef __STUDENT_H__
#define __STUDENT_H__
// #include<iostream>
//problem: move the top of stack for m value of s2 to the position of k pop times from top of our stack
//ex.ให้s1 เป็น stack ที่มีข้อมูลเป็น [2, 7, 4, 3] และ s2 มีข้อมูลเป็น [10, 6, 9]
//การเรียก s1.moveInsert(1, s2, 2) จะท าให้ s1 มีข้อมูลเป็น [2, 7, 4, 6, 9, 3] และ s2 มีข้อมูลเป็น
//[10] 
//solution: shift value in mData and if the it is the insert position we have to insert value of s2 instead
//special case when insert in bottom the pos not 0 but -1 because if 0 we will miss the bottom value of our stack to be appear before s2 data
template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  // your code here
  if(m>s2.mSize) m=s2.mSize;
  
  size_t newSize=mSize+m;
  expand(std::max(2*mCap,newSize));
  int j=mSize-1;
  int pos=mSize-1-k;
  if(k>=mSize) pos=-1;//for special case
  // std::cout<<"pos:"<<pos<<std::endl;
  int count=0;//track how many data from s2 we already insert
  for(int i=newSize-1;i>=pos;i--){
    if(count==m) break;//if already insert m data from s2
    if(j==(pos)){//get data from s2;

      mData[i]=s2.top();
      s2.pop();
      // std::cout<<"pop"<<std::endl;
      count++;
      continue;
    }
    // std::cout<<"in loop"<<std::endl;
    mData[i]=mData[j--];//shift old data
    
  }
  mSize=newSize;//very important




  // int pos=mSize-1-k;
  // if(m>s2.mSize) m=s2.mSize;
  // if(k>=mSize) pos=0;
  // size_t newSize=mSize+m;
  // mCap=std::max(newSize,2*mSize)
  // T* arr= new T[mCap]();
  // int j=mSize-1;
  // for(int i=0;i<newSize;i++){
  //   if(j==pos){
  //     arr[i]=
  //   }
  //   arr[i]=mData[j];
    
  // }

}
#endif
