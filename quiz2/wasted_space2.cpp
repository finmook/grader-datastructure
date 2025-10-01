#include<bits/stdc++.h>
using namespace std;
//problem: display wasted space of cp:vector which is the difference of mCap and mSize
//solution: double vector mCap until the amount of mCap more than or equal to mSize
// mSize + and - normally depend on operator
//when resize the amount of mSize must equal to number after op resize and mCap is the max(mCap, value after op resize)
int main(){
    long long int n;
    cin>>n;
    long long int data=0;//mSize
    long long int s=1;//mCap
    for(long long int i=0;i<n;i++){
        string op;
        long long int amount;
        cin>>op;
        cin>>amount;
        if(op[0]=='p'){//push_back
            data+=amount;
            if(data>s){
                while(data>s){
                    s*=2;
                }
            }
        }else if(op[0]=='o'){//pop_back
            data-=amount;
        }else if(op[0]=='r'){//resize
            s=max(s,amount);
            if(data>amount) data=amount;
        }
    }
    long long int wastedSpace=s-data;
    cout<<wastedSpace<<endl;
}
