//problem: เอาค่าใน vector เฉพาะตัวที่ ไม่มีค่า r1<=row<=r2 || c1<=col<=c2
//knowledge: vector
//solution: เก็บค่าที่เอาไว้ใน vector ใช้ continue เข้ามาจะได้ไม่เสียเวลาเช็ค
#include <iostream>
#include <vector>
using namespace std;
void cross_2d(vector<vector<int>> &m ,int r1, int r2, int c1, int c2) {
 //your code here
 int c=m[0].size();//store column size
 vector<vector<int>> temp;// to store temporary value that will copy into m at last step
 for(int i=0;i<m.size();i++){
    if(i>=r1&&i<=r2) continue;
    vector<int> inner;// to kept chosen value for each row
    for(int j=0;j<c;j++){
        
        if(j>=c1&&j<=c2) continue;
        inner.push_back(m[i][j]);
    }
    if(!inner.empty()){
        temp.push_back(inner);
    }
 }
 m=temp;
}
int main() {
 ios_base::sync_with_stdio(false);cin.tie(0);
 vector<vector<int>> m;
 int r,c,r1,r2,c1,c2;
 cin>> r >> c;
 cin >> r1 >> r2 >> c1 >> c2;
 m.resize(r);
 for (int i =0;i < r;i++) {
 m[i].resize(c);
 for (int j = 0;j < c;j++) {
 cin >> m[i][j];
 }
 }
 cross_2d(m,r1,r2,c1,c2);
 for (int i =0;i < m.size();i++) {
 for (int j = 0;j < m[i].size();j++) {
 cout << m[i][j] << " ";
 }
 cout << "\n";
 }
 return 0;
}
