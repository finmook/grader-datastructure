//problem:
//knowledge: map lower_bound upper_bound
//warning: case เยอะ
//tips: output show only 0 and 1
#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    map<int,int> intervals;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        intervals[start]=end;
    }
    for(int i=0;i<m;i++){
        int q;
        cin>>q;
        int count=0;
        if(intervals.lower_bound(q)!=intervals.end()){//case: not more than every key
            
            auto it=intervals.lower_bound(q);
            if(it!=intervals.begin()){// case: normal
                if(q==it->first) count=1;//case:equal to the key
                else if(q<=(--it)->second) count=1;//case: backward 1
            }else{//case:less than all key(may be equal to first key)
                if(it->first==q) count=1;
            }
            
        }else{// case: more than every key
            auto it=--intervals.end();
            if(q<=it->second) count=1;

        }
        cout<<count<<" ";
        
    }
    
}