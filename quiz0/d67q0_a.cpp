//shoesizing
//find size for customer(nearest if equal (in between) choose larger)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> shoeSize(N);
    

    for(int i=0;i<N;i++){
        cin>>shoeSize[i];
    }
    sort(shoeSize.begin(),shoeSize.end());
    for(int i=0;i<M;i++){
        int footSize;
        cin>>footSize;
        auto it=lower_bound(shoeSize.begin(),shoeSize.end(),footSize);
        if(it==shoeSize.begin()) cout<<*(it)<<" ";//case: less than least shoesize
        else if(it==shoeSize.end()||abs(*(it-1)-footSize)<abs(*it-footSize)) cout<<*(it-1)<<" ";// case: between size but not equal
        else cout<<*(it)<<" ";//case: between size but equal
    }
    
    

}