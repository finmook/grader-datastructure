#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {// this problem is to show time after such a minute
    int h,m;
    cin>>h>>m;
    int after;
    cin>>after;
    // int crossDay=(h + (m + after) / 60) /24;
    h = (h + (m + after) / 60) % 24;
    m= (m + after)%60;
    string hours=to_string(h);
    string minutes=to_string(m);
    if(hours.size()==1) hours="0"+hours;
    if(minutes.size()==1) minutes="0"+minutes;
    cout<<hours<<" "<<minutes<<endl;
   
}