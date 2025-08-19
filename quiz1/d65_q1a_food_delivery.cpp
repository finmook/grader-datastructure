//problem: ต้องทำกี่ออเดอร์ได้ตามยอดขาย รับ order จาก 2 app ให้ความสำคัญ app1 ก่อนถ้าราคาออเดอร์เท่าแต่ถ้าไม่ให้ความสำคัญอันที่ถูกกว่าระหว่าง 2 แอพ
//knowledge: pair of vector to store original index before sort,queue
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> par(m);
    vector<int> index(m);
    vector<int> result(m,-1);
    queue<int> app1;
    queue<int> app2;
    int total=0;//ดูว่าถึงยอดยัง
    int count=0;//นับจำนวน order
    int ptr=0;//เพื่อตอน loop จะได้ไม่ต้องวนใหม่ ต่อจากของเดิม
    for(int i=0;i<m;i++){
        int price;
        cin>>price;
        par[i]={price,i};
    }
    sort(par.begin(),par.end());
    
    for(int i=0;i<n;i++){
        int type;
        cin>>type;
        if(type==1){
            int a,b;
            cin>>a>>b;
            if(a==1){
                app1.push(b);
            }else{
                app2.push(b);
            }
        } else{
            if(app1.empty()&&!app2.empty()){
                total+=app2.front();
                app2.pop();
            }else if(app2.empty()&&!app1.empty()){
                total+=app1.front();
                app1.pop();
            }else if(app1.front()<=app2.front()){
                total+=app1.front();
                app1.pop();
            }else{
                total+=app2.front();
                app2.pop();
            }
            count++;
            // for(int j=0;j<m;j++){
            //     if(total>=par[j]&&result[j]==-1){
            //         result[j]=count;
            //     }
            // }
            while(par[ptr].first<=total && ptr<m){
                
                if(par[ptr].first<=total&&result[par[ptr].second]==-1){
                    result[par[ptr].second]=count;//เก็บลง result according to original index of par
                    ptr++;
                }
            }

        }

    }
    for(auto x:result){
        cout<<x<<" ";
    }
    

}