#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
 //write your code only in this function
  int start=a-v.begin(); //swap inward for each pair
  
  int end=b-v.begin()-1;
  
  
  int mid=(start+end)/2; //use index not iterator because want to find mid
  for(int i=start;i<=mid;i++){
    int temp=v[i];
    v[i]=v[end];
    
    v[end]=temp;
    end--;
  }
}
int main() {
 //read input
 int n,a,b;
 cin >> n;
 vector<int> v;
 for (int i = 0;i < n;i++) {
 int c;
 cin >> c;
 v.push_back(c);
 }
 cin >> a >> b;
 //call function
 reverse(v,v.begin()+a,v.begin()+b+1);
 //display content of the vector
 for (auto &x : v) {
 cout << x << " ";
 }
 cout << endl;
}
// void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b) {
//     // b is end() of range, so move one step back for the last element
//     b--;
//     while (a < b) {
//         swap(*a, *b);
//         a++;
//         b--;
//     }
// } * chat solution
