#include <iostream>
#include <vector>
#include <algorithm>
//problem: add ข้อมูล เช่น [10,20,30,40,50] multiply=[{2,3},{3,2}] first of pair is iterator second is how many we want to add
// the result is [10,20,30,30,30,30,40,40,40,50] 10 members
//knowledge: reserve() of vector(prevent reallocation), reallocation crashes iterators.
using namespace std;
void member_multiply(vector<int> &v, vector<pair<vector<int>::iterator, int>> &multiply)
{

    // write your code here
    
    sort(multiply.begin(), multiply.end());// to get the first iterator at first
    vector<int> indexs(multiply.size());//to get index
    int count = 0;//for capacity
    for (int i = 0; i < multiply.size(); i++)
    {
        count += multiply[i].second;
        indexs[i]=(multiply[i].first-v.begin());
    }
    v.reserve(v.size()+count);//change capacity of vector to match(prevent reallocation)
    for(int i=multiply.size()-1;i>=0;i--){
        v.insert(v.begin()+indexs[i],multiply[i].second,v[indexs[i]]);//insert values backward
    }
   
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator, int>> multiply(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        multiply[i].first = v.begin() + a;
        multiply[i].second = b;
    }
    member_multiply(v, multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}