//problem: change department of staff or move all staffs from one department to another.
//solution: use map to have key as department and value as set of staff
//knowledge: pass by reference to edit the value in it
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    map<string,set<string>> m;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string a,b;
        cin>>a>>b;//people=a department=b
        m[b].insert(a);
    }
    for(int i=0;i<M;i++){
        int type;
        cin>>type;//type of commands
        if(type==1){
            string name,dept;
            
            cin>>name>>dept;
            for(auto &x:m){//pass by reference to erase value***
                if(x.second.find(name)!=x.second.end()) x.second.erase(name);//erase staff from old department
            }
            m[dept].insert(name);

        }else if(type==2){
            string dept1,dept2;
            cin>>dept1>>dept2;
            for(auto x:m[dept1]){
                m[dept2].insert(x);
            }
            m.erase(dept1);//delete department that no staff
        }
    }
    for(auto x:m){
        cout<<x.first<<": ";
        for(auto y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}