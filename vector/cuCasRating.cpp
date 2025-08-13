#include<bits/stdc++.h>
using namespace std;
//หาคะแนนเฉลี่ยอาจารย์กับแต่ละวิชา
int main(){
    cout << std::fixed << std::setprecision(2);
    map<string,pair<int,int>> teacher;//pair contains {sum of score, number of score(ส่วนที่ใช้หารอะ)}
    map<long long,pair<int,int>> subject;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        long long subj;
        string prof;
        int score;
        cin>>subj>>prof>>score;
        if(teacher.find(prof)==teacher.end()){
            teacher[prof]={score,1};
        }else{
            teacher[prof].first+=score;
            teacher[prof].second+=1;
        }
        if(subject.find(subj)==subject.end()){
            subject[subj]={score,1};
        } else{
            subject[subj].first+=score;
            subject[subj].second+=1;
        }
    }
    for(auto x:subject){
        float point=((x.second.first+0.0)/x.second.second);
        
        cout<<x.first<<" "<<point<<endl;
    }
    for(auto x:teacher){
        float point=((x.second.first+0.0)/x.second.second);
                cout<<x.first<<" "<<point<<endl;

    }
}