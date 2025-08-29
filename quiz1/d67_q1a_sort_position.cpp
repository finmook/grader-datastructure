//problem: give vector and tell what position (1 to n) will it be after sort
//knowledge:map insert log n so use vector and sort so only log n one time(vector instead of map in "oldnew")
//solution:keep the position value after sort we still have old position value and know new position from present vector 
#include<bits/stdc++.h>
using namespace std;
int main(){
     std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    for(int i=1;i<=n;i++){
        int ip;
        cin>>ip;
        v.push_back(make_pair(make_pair(ip,i),0));//store{{value,old_position},new positioin}
    }
    vector<pair<pair<int,int>,int>> temp=v;
    sort(v.begin(),v.end());//if equal value the less old postion come first
    vector<pair<int,int>> oldnew; //map from old position to new position
    for(int i=0;i<v.size();i++){
        v[i].second=i+1;
        oldnew.push_back({v[i].first.second,v[i].second});
    }
    sort(oldnew.begin(),oldnew.end());
    for(auto x:oldnew){
        cout<<x.second<<" ";
    }

    // for(auto x:temp){
    //     // for(int i=0;i<temp.size();i++){
    //     //     if(x.second==i){
    //     //         cout<<<<" ";
    //     //         break;
    //     //     }
    //     // }
    //     for(int i=0;i<v.size();i++){
    //         if(x.second==v[i].second){
    //             cout<<i+1<<" ";
    //             break;
    //         }
    //     }
    // }

}