#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
// #include<iostream>
//problem: mitosis the value of data in mData which is the from the top of stack for a times and b times(between and inclusive)
// the top of stack mean right of stack
//solution1: create new pointer arr and get the value from mData track from different idx and if it is the data that has to duplicate we shift idx of arr but not idx of mData
//solution2(100 points): shift the value by loop backward of newSize if it is in the range that must mitosis it will track if duplicated or not
template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    // int newSize=mSize+b-a+1;
    // T *arr = new T[newSize]();
    // int j=mSize-1;
    // int count=0;//if already add duplicate or not(0 is not add 1 is already add so can shift idx of mData)
    // int start=mSize-1-b;//the come first idx that must duplicate
    // int end=mSize-1-a;//the come last idx that must duplicate
    // // std::cout<<start<<" "<<end<<" ";
    // for (int i = newSize-1; i >=0; i--)
    // {

    //     arr[i]=mData[j];
    //     if(j>=start && j<=end && count==0){
    //         count++;
    //         continue;
    //     }
    //     j--;//shift mData idx
    //     count=0;

    // }
    // delete[] mData;
    // mData = arr;
    // mSize=newSize;
    // mCap = mSize+b-a+1;
    size_t newSize=mSize+b-a+1;
    int start=mSize-1-b;
    int end=mSize-1-a;
    
    if(newSize>mCap) expand(std::max(mCap*2,newSize));
    int j=mSize-1;
    bool isDuplicated=false;
    for(int i=newSize-1;i>=start;i--){
        
        if(j<=end && j>=start && !isDuplicated){
            // std::cout<<i<<" "<<j<<std::endl;
            mData[i]=mData[j];
            isDuplicated=true;
            continue;
        }
        mData[i]=mData[j--];
        isDuplicated=false;
        
    }
    mSize=newSize;
    
}

#endif