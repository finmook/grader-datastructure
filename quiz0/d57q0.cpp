//histogram
//knowledge: map
//show value that input more than 1 time and show how many times it show;
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string,int> freq;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        if(freq.find(name)==freq.end()){
            freq[name]=1;
        }else{
            freq[name]++;
        }
    }
    for(auto x:freq){
        if(x.second>1){
            cout<<x.first<<" "<<x.second<<endl;

        }
    }
}
