#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        s.insert(value); // change from vector to set because has duplicate value
        // insert takes o(log(n))
    }

    for (int i = 0; i < M; i++)
    {
        int q;
        bool isFind = false;
        cin >> q;

        for (auto &x : s)
        {
            if (s.find(q - x) != s.end() && q - x != x)
            {
                isFind = true;
                break;
            }
        }
        if (!isFind) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}