//interval count problem:m values n questions find how many values in m in [question-k,question+k]
//knowledge: lower_bound,upper_bound

#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n);
    //vector<int> q(m);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());//important before use lower_bound and upper_bound
    for(int i=0;i<m;i++){
        int q;
        int count=0;
        cin>>q;
        auto start=lower_bound(v.begin(),v.end(),q-k);
        auto end=upper_bound(v.begin(),v.end(),q+k);

        if(start!=v.end()){
            // if(*start==q) cout<<*start<<" ";
            for(auto it=start;it!=end;it++){//loop from start in question-k to question+k
                count++;
            }
        }
        if(end!=v.end() && *end==q){//if last position is eq to q+k
            count++;
        }
        cout<<count<<" ";

    }
}
