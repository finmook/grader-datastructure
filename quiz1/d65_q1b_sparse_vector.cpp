//problem:insert ค่าถ้า key ซำ้ key เก่า+1 key หลังจากนั้นก็+1
//solution: store value from pos position in vector and erase the value from pos to end() of v(map) after that insert at it with value from vector(use value backward to easy shift)
//knowledge: erase iterator crash, use vector.begin()-1 in condition of loop instead of >=vector.begin() when loop using iterator,lower_bound,insert return the iterator of pos that we insert
#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int, int> &v, int pos, int value)
{
    // your code here
        //first way:false because iterator crash when iter-- because we erase already
        // auto it = v.lower_bound(pos);
        
        // if (!v.empty())
        // {

        //     for (auto iter = (--v.end()); iter != prev(it); iter--)
        //     {
        //         v[(iter->first) + 1] = (iter->second);
        //         v.erase((iter->first));
                
        //     }
        // }

        // v[pos] = value;
    if (!v.empty())
        {
        auto it = v.lower_bound(pos);
        vector<pair<int,int>> back(it,v.end());
        v.erase(it,v.end());
        it=v.end();
        

            for (auto it2=back.end()-1;it2!=back.begin()-1;it2--)//use >=back.begin() not work must use this for loop back using iterator
            {
                it=v.insert(it,{(it2->first)+1,it2->second});

                
            }
            v.insert(it,{pos,value});
        }
        else{
            v[pos]=value;
        }
        
        
    
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        insert_into_sv(v, a, b);
    }
    cout << v.size() << "\n";
    for (auto &x : v)
    {
        cout << x.first << ": " << x.second << "\n";
    }
}