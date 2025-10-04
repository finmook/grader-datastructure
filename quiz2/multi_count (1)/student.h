#ifndef __STUDENT_H_
#define __STUDENT_H_
//problem: count the value in queue the value come from vector k
//solution: store the value in map loop through mData and ket count in map after that we kept the value of map in vector v and return(the problem fix that we must return in v)
#include <map>
#include<vector>
#include<utility> //for std::pair
template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    std::map<T,size_t> m;
    // for(auto x:k){
    //     m[x]=-1;
    // }
    for(int i=0;i<mSize;i++){
        // if(m[mData[(mFront+i)%mCap]]==0){
        //     if(m[mData[(mFront+i)%mCap]]==-1) m[mData[(mFront+i)%mCap]]=1;
        //     else m[mData[(mFront+i)%mCap]]+=1;
        // }
        m[mData[(mFront+i)%mCap]]++;
    }
    std::vector<std::pair<T,size_t>> v;
    for(int i=0;i<k.size();i++){
        v.push_back(std::make_pair(k[i],m[k[i]]));
    }
    return v;
}

#endif
