#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    int wastedSpace1=mCap-mSize;
    int wastedSpace2=other.mCap-other.mSize;
    if(wastedSpace1<wastedSpace2) return -1;
    else if(wastedSpace1==wastedSpace2) return 0;
    else {
        return 1;
    }
}

#endif
