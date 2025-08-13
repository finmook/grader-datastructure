#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() { //this problem refer the top right as 1,1 not 0,0
    int N,M;
    cin>>N>>M;
    vector<vector<int>> mtx(N,vector<int>(M));
    int R;
    cin>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>mtx[i][j];
        }
    }
    for(int i=0;i<R;i++){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        if(r1>r2 || c1>c2){// case: false input (bottom right cannot less than top left)
            cout<<"INVALID"<<endl;  
            continue;
        }
        if(c1>M || c2<=0 || r1>N ||r2<=0){ // case: not have any area intersect
            cout<<"OUTSIDE"<<endl;
            continue;
        }
        if(r1<=0) r1=1; // the start point if outside let it be top left
        if(c1<=0) c1=1;
        int maxs=-9999999; //maxs should be very small at first
        for(int j=r1-1;j<=r2-1;j++){
            if(j>=N) break;
            for(int k=c1-1;k<=c2-1;k++){
                if(k>=M) break;
                maxs=max(maxs,mtx[j][k]);
            }
        }
        cout<<maxs<<endl;


    }
}