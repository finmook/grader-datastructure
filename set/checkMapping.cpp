//problem : if it is permutation(onto && 1-1 && set of A and B equal(f:A=>B))
//1-1 is y equal x must equal
//onto is is has x must has y;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;
    int N;
    cin >> N;
    vector<int> v(N);
    bool eq = true;// to check if A equal B(A is{1,2,3,...,N})
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        if (val > N || val < 1)
        {
            eq = false;
            continue;
        }
        s.insert(val);
        v[i] = val;
    }
    if (s.size() < v.size() || !eq)//(mean not 1-1 || A not equal B)
        cout << "NO";
    else
        cout << "YES";
}