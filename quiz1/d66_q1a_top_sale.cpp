#include<bits/stdc++.h>
//problem: find the most amount of product that have sell but smaller than k
//solution: have two map to store both side of relation if we store count for key and set in value it cannot be duplicate key and we also can sort by count easily and find id easily
//knowledge: new technique(map<int,set<int>>) and lower_bound
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    //this method is slow and not pass testcase(pass only in example)
    // set<long,long> sales;
    // int N,M;
    // cin>>N>>M;
    // for(int i=0;i<N;i++){
    //     int id;
    //     cin>>id;
    //     sales[-id]=0;
    // } 
    // for(int i=0;i<M;i++){
    //     int type;
    //     cin>>type;
    //     if(type==1){
    //         int ip,sale;
    //         cin>>ip>>sale;
    //         if(sales.find(-ip)!=sales.end()) sales[-ip]+=sale;
    //     }
    //     else if(type==2){
    //         int k;
    //         cin>>k;
    //         long maxs=-1e9;
    //         long answer;
            
    //         for(auto it=sales.begin();it!=sales.end();it++){
    //             if((it->second)>=k) continue;
    //             if(it->second>maxs){
    //                 answer=abs(it->first);
    //                 maxs=it->second;
    //             }
               
                
    //         }
    //         if(maxs==(-1e9)) cout<<"NONE"<<endl;
    //         else cout<<answer<<endl;
    //     }
        
    // }
    //second method
    map<long,set<long>> countToId;
    map<long,long> idToCount;
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int stock;
        cin>>stock;
        idToCount[stock]=0;//เก็บว่ามีของชิ้นไหนบ้าง
        
    }
    for(int i=0;i<M;i++){
        int type;
        cin>>type;
        if(type==1){//increase the product count
            int id,sale;
            cin>>id>>sale;
            if(idToCount.count(id)!=0){//check if it is our product id
                countToId[idToCount[id]].erase(id);//ลบข้อมูลเก่า
                if(countToId[idToCount[id]].size()==0) countToId.erase(idToCount[id]);//important must delete (it will crash if empty and call iterator)
                idToCount[id]+=sale;//increase count
                countToId[idToCount[id]].insert(id);//new insert to new count key
            }
        }else{// answer the question of most count product of us but the count must less than k if(the max count is equal choose the product that have more product id)
            int k;
            cin>>k;
            auto it=countToId.lower_bound(k);
            if(it==countToId.begin()) cout<<"NONE"<<endl;
            else{
                cout<<*(--(((--it)->second).end()))<<endl;
            }

        }
    }
}