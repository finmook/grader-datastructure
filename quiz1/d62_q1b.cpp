//grandfather
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    map<long long,long long> rel;
    long long N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        long long F,S;
        cin>>F>>S;
        rel[S]=F;
    }
    for(int i=0;i<M;i++){
        long long p1,p2;
        cin>>p1>>p2;
        if(p1==p2){
            cout<<"NO"<<endl;
            continue;
        }
        if(rel.find(p1)!=rel.end() && rel.find(p2)!=rel.end()){
            long long f1=rel[p1];
            long long f2=rel[p2];
            if(rel.find(f1)!=rel.end() && rel.find(f2)!=rel.end()){
            long long gf1=rel[f1];
            long long gf2=rel[f2];
            if(gf1==gf2){
                cout<<"YES"<<endl;
                continue;
            }else{
                cout<<"NO"<<endl;
                continue;
            }
            
        }
        }
        cout<<"NO"<<endl;
    }
}