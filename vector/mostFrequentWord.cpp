#include<bits/stdc++.h>
using namespace std;
//find the most frequent word(ex. of out put: Somchai 3)
int main(){
    map<string,int> freqWord;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string word;
        cin>>word;
        if(freqWord.find(word)==freqWord.end()){//never has this word before
            freqWord[word]=1;
        }else{
            freqWord[word]++;
        }
    }
    int max=-1;
    string ans;
    for(auto x:freqWord){//loop map แบบนี้ง่ายดี
        if(x.second>=max){
            ans=x.first;
            max=x.second;
        }

    }
    cout<<ans<<" "<<max;
}