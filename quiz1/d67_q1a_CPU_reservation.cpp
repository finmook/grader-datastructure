//problem: reserve the time come first get first(if time have already taken (intersect time(include bound))) rejected
//display the person that booked successful
//knowledge: map lower_bound, possible case
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> m;
    vector<int> v;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int start,end;
        cin>>start>>end;
        if(m.empty()){
            m[start]=end;
            cout<<1<<" ";//first person always get
        }
        else{
            auto it=m.lower_bound(start);
            if(it==m.end() && (start<=(prev(it)->second))){continue;}//the last time but start is less than end of before people
            else if(it==m.end()){m[start]=end; cout<<i+1<<" ";}//get booked
            else if(it==m.begin() &&(end>=(m.begin()->first))){continue;}//begin but end is after the start of person who already booked
            else if(it!=m.begin() && (start<=(prev(it)->second) || end>=(it->first))){continue;}//warning:block if it==m.begin() because we don't know the value of prev(begin()),normal case
            else{//get booked
                m[start]=end;
                cout<<i+1<<" ";// don't store i+1 in vector because it is slower just print it.
            }
        }
    }
    
    
    
}