#include <bits/stdc++.h>
// ยังไม่เสร็จ
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    vector<int> window;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if(v.size()<w+1){
        sort(v.begin(),v.end());
        auto it=v.begin();
        cout<<*(it+w/2);
    }else{
         for (int i = 0; i < n; i++)
    {
        if (i <w)
        {
            q.push(v[i]);
            window.push_back(v[i]);
        }
        else
        {
            sort(window.begin(),window.end());
            window.insert(lower_bound(window.begin(), window.end(), v[i]), v[i]);
            q.push(v[i]);
            cout << *(next(window.begin(), w / 2)) << " ";
            int f = q.front();
            q.pop();
            window.erase(lower_bound(window.begin(), window.end(), f));
            
        }
    }
    }
    
   

    // first method get only 50% due to T

    // vector<int> v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // if(w>=n){
    //     sort(v.begin(),v.end(),greater<int>());
    //     int a=0;
    //     int b=v.size()-1;
    //     int pos=1+(b-a)/2;
    //     cout<<v[pos-1];
    // }
    // for(int i=0;i<n-w;i++){
    //     vector<int> temp;
    //     for(int j=i;j<=i+w;j++){

    //         temp.push_back(v[j]);

    //     }
    //     sort(temp.begin(),temp.end(),greater<int>());
    //     // cout<<"temp: ";
    //     // for(auto x:temp){
    //     //     cout<<x;
    //     // }
    //     // cout<<endl;
    //     int a=i;
    //     int b=i+w;
    //     int pos=1+(b-a)/2;
    //     // cout<<"pos: "<<pos<<endl;
    //     cout<<temp[pos-1]<<" ";

    // }
}