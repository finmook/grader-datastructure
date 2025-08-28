//problem: brake each time assumes ความเร็วคงที่ เบรกตอนไหนลดทันที และ>=0 have 2 types of question first is velocity at a time second is time that contain minimal velocity
//knowledge: lower_bound() the last value must be real like make_pair() not {} and type of -1e10 is double so we convert to long in this problem
//optional knowledge: lower_bound(v.rbegin(),v.rend(),value,comp)
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;//k=initial velocity
    map<int,int> td;//store time and deduction
    map<int,int> tv;//store time and velocity(for a==1 which is finding the velocity from time)
    vector<pair<int,long>> vt;//store velocity and -time(for a==2 which is find the time that minimal velocity q has)
    for(int i=0;i<n;i++){
        int t,d;
        cin>>t>>d;
        td[t]=d;
    }
    tv[0]=k;//don't forget to insert initial value
    vt.push_back(make_pair(k,0));// same as above comment
    for(auto x:td){
        k-=x.second;
        if(k<0) k=0;
        tv[x.first]=k;
        vt.push_back(make_pair(k,-x.first));
    }
    sort(vt.begin(),vt.end());
    for(int i=0;i<m;i++){
        int a,q;
        cin>>a>>q;
        if(a==1){
            // auto x=lower_bound(tv.begin(),tv.end(),make_pair(q,(long)-1e10));
            auto x=tv.lower_bound(q);
            if(x->first==q) cout<<x->second<<endl;
            else cout<<(--x)->second<<endl;
        }else if(a==2){
            auto it=lower_bound(vt.begin(),vt.end(),make_pair(q,(long)-1e10));//
            
            if(it==vt.begin()) cout<<abs((*it).second)<<endl;
            else cout<<abs((*(it-1)).second)<<endl;
        }
    }
}