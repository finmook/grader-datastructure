#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator
it,int k) {
 //write some code here
 //don’t forget to return something
 int start=it-k-v.begin();
 int end=it+k-v.begin();
 if(start<0) start=0;
 if(start>end || start>=v.size()) return v;
 vector<string> result;//let copy used value in new vector(o(n) not o(n**2))
 for(int i=0;i<v.size();i++){
    if(i>=start && i<=end) continue;
    else result.push_back(v[i]);
 }
 return result;

}
int main() {
 int n,j,k;
 cin >> n >> j >> k;
 vector<string> v(n);
 for (int i = 0;i < n;i++) {
 cin >> v[i];
 }
 cout << "Result after punch" << endl;
 vector<string> result = punch(v, v.begin() + j, k);
 for (auto &x : result) {
 cout << x << endl;
 }
}