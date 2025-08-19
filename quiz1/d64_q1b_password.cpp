#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    
    int N,M,L;
    cin>>N>>M>>L;
    vector<int> k(L);
    set<string> password;
    for(int i=0;i<L;i++){
        cin>>k[i];
    }
    for(int i=0;i<N;i++){
        string p;
        cin>>p;
        password.insert(p);
    }
    for(int i=0;i<M;i++){
        string q;
        cin>>q;
        string encrypted;
        for(int j=0;j<k.size();j++){

            // way 1
            int shift=k[j]%26;//ป้องกัน+เกิน 26
            int c=(q[j]+shift); // char+int ได้
            if(c>'z') c-=26;

            // way 2
            // int c=(q[j]+k[j]) % 26; // char+int ได้

            encrypted+=char(c);
        }
        
        if((password.find(encrypted))!=password.end()){
            cout<<"Match"<<endl;
        }else{
            cout<<"Unknown"<<endl;
        }
    }

}
