//problem: find the min power of all type of cards, each power of each type is the max value of powers of cards in same type.
#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> maxOfType(m,1);
    vector<int> power(n);
    vector<int> type(n);
    set<pair<int,int>> s;//เก็บ {ค่าพลัง,type} เรียงให้เลย map ไม่ได้ค่าพลังซำ้
    for(int i=0;i<m;i++){
        s.insert({1,i});
    }
    for(int i=0;i<n;i++){
        cin>>power[i];
    }
    for(int i=0;i<n;i++){
        cin>>type[i];
    }
    for(int i=0;i<n;i++){
        if(maxOfType[type[i]]<power[i]){
            s.erase({maxOfType[type[i]],type[i]});
            s.insert({power[i],type[i]});
            maxOfType[type[i]]=power[i];
        }
        cout<<(*(s.begin())).first<<" ";
        
    }
    // for(auto x:s){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    
}