#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void list_erase(vector<int> &v, vector<int> &pos)
{
    // write your code here
    //  sort(pos.begin(),pos.end());
    //  int posIdx=pos.size()-1;
    //  for(int i=v.size()-1;i>=0;i--){
    //     if(i!=pos[posIdx]) continue;
    //     else{
    //         posIdx--;
    //         v.erase(v.begin()+i);
    //         if(posIdx<0) break;
    //     }
    //  } 60 scores method
    //use copy vector instead(push_back or get the value is faster(o(1)))
    vector<int> temp(v.size() - pos.size()); // each value in pos is unique.
    sort(pos.begin(), pos.end());
    int posIdx = 0;
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == pos[posIdx])
        {
            posIdx++;
            continue;
        }
        temp[j++] = v[i];
    }
    v = temp;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n), pos(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> pos[i];
    list_erase(v, pos);
    cout << "After call list_erase" << endl
         << "Size = " << v.size() << endl;
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}