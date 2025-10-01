//problem:find the waste space which is mCap-mData
//solution: multiply mCap by 2 until the value of mCap is more than n;
//knowledge: same like expand of CP:vector
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int mData=n;
    int mCap=1;
    if(n>mCap){
        while(n>mCap){
            mCap*=2;
        }
    }
    cout<<mCap-mData;
}