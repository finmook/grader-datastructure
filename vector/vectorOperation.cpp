#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        string order;
        cin>>order;
        if(order[0]=='p'){
            int num;
            cin>>num;
            v.push_back(num);
        }
        else if(order=="sa"){
            sort(v.begin(),v.end());
        }
        else if(order=="sd"){
            sort(v.begin(),v.end(),greater<int>());
        }
        else if(order=="r"){
            reverse(v.begin(),v.end());
        }
        else if(order[0]=='d'){
            int index;
            cin>>index;
            v.erase(v.begin()+index);
        }


    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}