//problem: ให้ตำแหน่งแกะมา แล้้วให้ตำแหน่งหมาป่าแต่ละวัน หาระยะเพื่อกินแกะตัวใกล้สุดแต่ละวัน(แกะเกิดใหม่ ตำแหน่งเดิมแต่ละวัน เหมือนเส้นจำนวน)
//knowledge: lower_bound
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> locations(N);//locations of sheep.
    
    for(int i=0;i<N;i++){
        cin>>locations[i];
    }
    sort(locations.begin(),locations.end());

    int d;
    cin>>d;
    //vector<int> pWolf(d);
    for(int i=0;i<d;i++){
        int wolf;
        cin>>wolf;//location of wolf each day
        int dist;
        auto it=lower_bound(locations.begin(),locations.end(),wolf);
        if(it==locations.end()) dist=wolf-locations[locations.size()-1];
        else if(it==locations.begin()) dist=locations[0]-wolf;
        else{
            if(*(it)-wolf>wolf-*(it-1)) dist=wolf-*(it-1);
            else dist=*(it)-wolf;
        }
        
        cout<<dist<<endl;
    }
    
}