#include <vector>
#include<set>
#include<map>
using namespace std;
//Problem: intersect union ปกติ แต่ลำดับมีผล และ A ต้องมาก่อน B
template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<int> s;//เก็บข้อมูลใน A จะได้ find ง่ายๆ
    for(int i=0;i<A.size();i++){
        s.insert(A[i]);
    }
    for(int i=0;i<A.size();i++){
        v.push_back(A[i]);
    }
    for(int i=0;i<B.size();i++){
        if(s.find(B[i])!=s.end()) continue;
        v.push_back(B[i]);
    }


    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<int> sb;
    for(int i=0;i<B.size();i++){
        sb.insert(B[i]);
    }
    for(int i=0;i<A.size();i++){
        if(sb.find(A[i])!=sb.end()) v.push_back(A[i]);
    }
    return v;
}
