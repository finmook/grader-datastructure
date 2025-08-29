#include<bits/stdc++.h>
//problem: เก็บเงินซื้อไอติมเริ่มต้นวันละ start บาท มีวันที่ตั้งใจจะเปลี่ยนจำนวนเงินที่เก็บได้ ถ้าโดนคอลเซนเตอ เงินหายหมด แต่ถ้าซื้อไอติมวันนั้นพอดีรอด
//ต้องการวันที่ได้กินไอติม
//knowledge: lower_bound
using namespace std;
const int N=1e5;//guarantee the ans less than 1e5;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    
    int n,m,start;
    cin>>n>>m>>start;
    
    vector<int> v(N+1);//เก็บว่าแต่ละวันมีเงินรวมเท่าไหร่
    v[0]=start;
    for(int i=0;i<n;i++){
        int a,b;//a= the day change saving per day b=the value
        cin>>a>>b;
        v[a]=b;//store in v first
    }
    int inc=start;
    for(int i=1;i<N;i++){//each index means day
        if(v[i]==0){
            v[i]=inc;//get the saving per day in this(will sum with all money from yesterday below)
        }else{
            inc=v[i];//change the value to sum with money from yesterday
        }
        v[i]+=v[i-1];//sum with money from yesterday
    }
    for(int i=0;i<m;i++){
        int p,d;

        cin>>p>>d;
        if(p<=v[d]){
            cout<<lower_bound(v.begin(),v.end(),p)-v.begin()<<" ";
        }else{
            
           cout<<lower_bound(v.begin(),v.end(),p+v[d])-v.begin()<<" ";
        }
    }
    
}