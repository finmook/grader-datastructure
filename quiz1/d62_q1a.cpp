//vote problem
//เอาคนที่ได้คะแนนท๊อป K คน
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> leaderBoard; //เก็บคะแนนคนที่ได้อย่างน้อย 1 แต้ม
    map<string,int> votes;//ชื่อ : คะแนน
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        string name;
        cin>>name;
        if(votes.find(name)==votes.end()){
            votes[name]=1;
        } else{
            votes[name]++;
        }
    }
    for(auto x:votes){
        leaderBoard.push_back(x.second);
    }
    sort(leaderBoard.begin(),leaderBoard.end(),greater<int>());//เอา top score ขึ้นก่อน
    int min=1;
    
    for(int i=0;i<leaderBoard.size();i++){
        if(i>=K) break;//ครบ K คน
        min=leaderBoard[i];
    }
    cout<<min;
}