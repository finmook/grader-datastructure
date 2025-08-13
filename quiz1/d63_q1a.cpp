//multiinsert
//problem: insert same value for count time in vector at specific position
//solution: ใช้วิธีตัด vector ออกเป็นสองส่วนแรกไม่ใช้ส่วนกลางเติม value แล้วก๊อปค่าส่วนท้ายมา
#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
 //write your code here
 //vector<int> v1(position);
 vector<int> v2(v.size()-position);// to store value of v ตั้งแต่ position
//  vector<int> mid(count,value);
for(int i=position;i<v.size();i++){
    v2[i-position]=v[i];// store v value(from position to v.size())
}
 v.resize(v.size()+count);
 int c=0;// to insert value for count time
 int j=0;//to get value from v2 back
 for(int i=position;i<v.size();i++){
    if(c<count){//count time
         v[i]=value;
         c++;
    }else{
        v[i]=v2[j++];
    }
   
    

 }

}
int main() {
 std::ios_base::sync_with_stdio(false);
 cin.tie(0);
 int n,value,position,count;
 cin >> n >> value >> position >> count;
 vector<int> v(n);
 for (int i = 0; i < n; i++) cin >> v[i];
 multiple_add(v,value,position,count);
 cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
 for (auto &x : v) cout << x << " ";
 cout << endl;
}