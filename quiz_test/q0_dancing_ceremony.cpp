//problem: มี่กี่คู่ของคู่เต้นที่ผลรวมแต้ม เป็น + (แต้มแต่ละคู่คือคะแนนเต้นผู้นำ-ผู้ตาม)
//knowledge: upper_bound
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> A(n);//คะแนนเต้นผู้นำ
    vector<long long> B(n);//คะแนนเต้นผู้ตาม
    for (long long i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    vector<long long> diff(n);//ผลต่างคะแนน แต่ละคู่
    long long count = 0;
    for (long long i = 0; i < n; i++)
    {
        diff[i] = A[i] - B[i];
    }
    sort(diff.begin(), diff.end());
    for (long long i = 0; i < n; i++)//ข้ามไปคู่ของคู่เต้น แรกที่diff รวมกันเป็น + แล้ว + ไปจนถึงตัวสุดท้าย
    {
        // for(int j=i+1;j<n;j++){
        //     if(diff[i]+diff[j]>0){
        //         count+=diff.size()-j;
        //         break;
        //     }
        // }
        if (diff[i] <= 0)
        {
            auto it = upper_bound(diff.begin(), diff.end(), abs(diff[i]));
            // cout << "it:" << *(it) << endl;
            if (it == diff.end()||it==diff.begin()) continue;
            int idx = it - diff.begin();
            count += (diff.size() - idx);
        }
        else
        {
            count += (diff.size()-1-i);
        }
    }
    cout << count;
}