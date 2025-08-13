#include <iostream>
#include <vector>
using namespace std;
//this function swap the position until one of vectors has no swap value
//after that loop through the left value of one vector and insert it forward to another vector(increase position each times by 1 and delete the value in itself)
void vector_swap(vector<int> &v1,vector<int> &v2,
 int start1, int end1,
 int start2, int end2) {
    if((end2-start2)<(end1-start1)){
        while(start2!=end2){
            swap(v1[start1],v2[start2]);
            start2++;
            start1++;
        }
        int pos=start2;
        for(int i=0;i<end1-start1;i++){
            v2.insert(v2.begin()+pos,v1[start1]);
            pos++;
            v1.erase(v1.begin()+start1);
        }
        
    }else{
        while(start1!=end1){
            swap(v1[start1],v2[start2]);
            start2++;
            start1++;
        }
        int pos=start1;
        for(int i=0;i<end2-start2;i++){
            v1.insert(v1.begin()+pos,v2[start2]);
            pos++;
            v2.erase(v2.begin()+start2);
        }
    }
}
int main() {
 //read input
 int n,c;
 vector<int>v1,v2;
 cin >> n; //number of v1
 for (int i = 0;i < n;i++) {
 cin >> c;
 v1.push_back(c);
 }
 cin >> n; //number of v2
 for (int i = 0;i < n;i++) {
 cin >> c;
 v2.push_back(c);
 }
 int s1,e1,s2,e2; //position
 cin >> s1 >> e1 >> s2 >> e2;
 //call the function
 vector_swap(v1,v2,s1,e1,s2,e2);
 //display content of the stack
 cout << "v1 has " << v1.size() << endl;
 for (auto &x : v1) { cout << x << " "; }
 cout << endl;
 //display content of the stack
 cout << "v2 has " << v2.size() << endl;
 for (auto &x : v2) { cout << x << " "; }
 cout << endl;
}