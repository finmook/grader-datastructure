#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"
//problem: finally want q empty and qs must contain k queues for example queue<int> q เกก็บขข้อมมูล {3,9,8,6,7,2,1,3,8,4} ตามลทาดบับจากหนข้าไปหลบังอยมูว่ หากเราเรียก
// vector<queue<int>> qs = q.split_queue(3)
// ผลทนที่ไดข้คชอ qs[0] จะเปป็นแถวคอยทนที่เกก็บ {3,6,1,4}
//  qs[1] จะเปป็นแถวคอยทนที่เกก็บ {9,7,3}
//  qs[2] จะเปป็นแถวคอยทนที่เกก็บ {8,2,8}
//solution we will add the data to each queue using data from mData and finally we will delete mData and create new array
template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
    std::vector<CP::queue<T> > qs(k);
    // code here
    int idx=0;//track index of vector
    int i=0;// track data in mData
    while(i<mSize){
        if(idx>=k) idx=0;
        qs[idx++].push(mData[(mFront+i)%mCap]);
        i++;
    }
    delete [] mData;
    T *arr=new T[mCap]();
    mSize=0;
    mData=arr;
    return qs;
}

#endif

