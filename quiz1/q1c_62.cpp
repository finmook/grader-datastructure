#include<bits/stdc++.h>
using namespace std;
//vector intersection
int main(){
    set<int> s1;
    set<int> s2;

    int M,N;
    cin>>M>>N;
    for(int i=0;i<M;i++){
        int ip;
        cin>>ip;
        s1.insert(ip);
    }
    for(int i=0;i<N;i++){
        int ip;
        cin>>ip;
        s2.insert(ip);
    }
    for(auto &x:s1){
        if(s2.find(x)!=s2.end()){
            cout<<x<<" ";
        }
    }
    

}