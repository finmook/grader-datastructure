#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>
#include<vector>
//problem: split stack in form likes ex.{1,2,3,4,5} k=2 so the vector<vector> v that return must contain vector<T> T for each element in v and inside T it is the element
//that when pop for x round of stack we found it and contain the x+=k element until cannot
//เราต้องการเพิ่มฟังก์ชัน std::vector<std::vector<T>> split_stack(int k) const ลงใน
//CP::stack โดยฟังก์ชันนี้จะต้องคืนตัวแปรประเภท vector ขนาด k โดยที่ vector[x] จะต้องมีค่า
//ภายในล าดับดังนี้ {T[x], T[x + k], T[x + 2k], ….} ที่เรียงย้อนกลับ ซึ่งขอนิยาม T[x] ว่าหมายถึงตัว
//ที่จะเป็น Top of stack หลังจากการ Pop ออกมาแล้ว x ครั้ง (แต่เราไม่ได้ท าการ pop จริง ๆ)
//ยกตัวอย่างเช่นเรามี Stack ที่มีข้อมูลภายในตามล าดับดังนี้ [10, 20, 30, 40, 50, 60]
//(ก ำหนดให้ด้ำนขวำสุดคือ Top of stack) T[0] คือ 60 และ T[2] คือ 40 เป็นต้น
//solution: loop backward of mData from position x and +k every time push_back data
template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  //should return something
  std::vector<std::vector<T>> v;
  for(int i=0;i<k;i++){
    std::vector<T> temp;
    int idx=mSize-1-i;//track data in mData
    while(idx>=0){//loop mData backward
      temp.push_back(mData[idx]);
      idx-=k;
    }
    std::reverse(temp.begin(),temp.end());//because we want the first value that pop still on the right side
    v.push_back(temp);
  }
  return v;

}

#endif

