//hiatus: find the latest งานเขียน if(year,month) is equal print (0,0) if before all updated dates (-1,-1) normal case: if (year,month) in between find the lates updated date
//knowledge: vector of pair , make_pair(a,b) and lower_bound,upper_bound
#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> w(n);
    for(int i=0;i<n;i++){
        int y,m;
        cin>>y>>m;
        w[i].first=y;
        w[i].second=m;
    }
    sort(w.begin(),w.end());
    for(int i=0;i<m;i++){
        int y,m;
        cin>>y>>m;
        auto it=lower_bound(w.begin(),w.end(),make_pair(y,m));
        if(it==w.end()){//writing end before input date so get the latest date.
            cout<<(*(it-1)).first<<" "<<(*(it-1)).second<<" ";
        }
        else if(y==(*it).first){//case: same year
        
            if(m==(*it).second){// case: also same month
                cout<<0<<" "<<0<<" ";
            }else if(it==w.begin()){//case : can be before or equal first updated date but we check equal month above so it is before only
                cout<<-1<<" "<<-1<<" ";
            }else{//case: same year but month should be less than so we get the value of before pair
                cout<<(*(it-1)).first<<" "<<(*(it-1)).second<<" ";//warning: must use *(it-1).first not y
            }
        }else if(it==w.begin()){
            //cout<<((*it).first)<<((*it).second)<<endl;
            cout<<-1<<" "<<-1<<" ";//case: before all updated dates
        }else{
            cout<<(*(it-1)).first<<" "<<(*(it-1)).second<<" ";//case: between the pair so we get the pair before
        }
    }
}