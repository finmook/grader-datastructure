#include<bits/stdc++.h>
using namespace std;
//intersection but must use vector
//use method that loop through vector that max value less than

int main(){
    int N,M;
    cin>>N>>M;

    vector<int> v1(N);
    vector<int> v2(M);
    vector<int> dup;
    for(int i=0;i<N;i++){
        cin>>v1[i];
    }

    for(int i=0;i<M;i++){
        cin>>v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1[N-1]<v2[M-1]){
        for(auto x:v1){
            if(find(dup.begin(),dup.end(),x)!=dup.end()) continue;// skip the duplicate data
            for(auto y:v2){
                if(y>x) break;//if value of vector that have max value more than another pass the max value 
                //don't have to loop anymore
                if(y==x){
                    cout<<y<<" ";
                    dup.push_back(y);//To keep data that already duplicate
                    break;
                }
            }
        }
    }else{
         for(auto x:v2){
            if(find(dup.begin(),dup.end(),x)!=dup.end()) continue;
            for(auto y:v1){
                if(y>x) break;
                if(y==x){
                    cout<<y<<" ";
                    dup.push_back(y);
                    break;
                }
            }
        }
    }



}