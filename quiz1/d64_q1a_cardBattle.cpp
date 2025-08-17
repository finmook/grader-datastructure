#include<bits/stdc++.h>
//problem: มี n การ์ด แข่งเป็นรอบๆ แต่ละรอบต้องส่งการ์ดที่พบลังโจมตีมากกว่าออกมา
//knowledge: map erase(o(log n)) is faster than vector erase(o(n))
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    
    
    int n,m;
    cin>>n>>m;
    map<int,int> myCard;
    for(int i=0;i<n;i++){
        int card;
        cin>>card;
        myCard[card]++;
    }
    int count=0;
    bool lose=false;
    for(int i=0;i<m;i++){
        
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int atk;
            cin>>atk;
            if(myCard.upper_bound(atk)!=myCard.end()){
                //cout<<*(upper_bound(myCard.begin(),myCard.end(),atk))
                int keyy=myCard.upper_bound(atk)->first;
                myCard[keyy]--;
                if(!myCard[keyy]) myCard.erase(keyy);
            } else{
                lose=true;
                break;
            }
        }
        count++;
        if(lose) break;
    }
    if(!lose) count++;
    cout<<count;
}