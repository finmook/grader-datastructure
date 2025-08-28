//problem: voucher booking if the seat is already taken all booking of that person will not accept(must book the available voucher)
//knowlege: make_pair is safe than {} and lower_bound(x,y,value); the value must be real (use make_pair)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    long long N, M;
    cin >> N >> M;
    // the first way got 80/100 pt because booked.insert take time, so if we use vector instead it will get 100 pt;
    // set<pair<string, string>> voucher;
    // set<pair<string, string>> booked;
    // for (long long i = 0; i < N; i++)
    // {
    //     string flight, seat;
    //     cin >> flight >> seat;
    //     voucher.insert({flight, seat});
    // }
    // for (long long i = 0; i < M; i++)
    // {
    //     long long num;
    //     cin >> num;
    //     bool isAccept = true;
    //     vector<pair<string, string>> temp(num);
    //     for (long long j = 0; j < num; j++)
    //     {
    //         string flight, seat;
    //         cin >> flight >> seat;
    //         if ((voucher.find({flight, seat}) == voucher.end()) || ((booked.find({flight, seat})) != booked.end()))
    //         {
    //             isAccept = false;
                
    //         }
    //         temp.push_back({flight, seat});
    //     }
    //     if (isAccept)
    //     {
    //         for (long long j = 0; j < temp.size(); j++)
    //         {
    //             booked.insert(temp[j]);
    //         }
    //         cout << "YES" << endl;
    //     }
    //     else
    //         cout << "NO" << endl;
    // }
    vector<pair<pair<string, string>,bool>> voucher;//store vouchers
    for (long long i = 0; i < N; i++)
    {
        string flight, seat;
        cin >> flight >> seat;
        voucher.push_back({{flight, seat},true});
    }
    sort(voucher.begin(),voucher.end());
    for (long long i = 0; i < M; i++)
    {
        long long num;
        cin >> num;
        bool isAccept = true;//booking complete or not
        vector<vector<pair<pair<string,string>,bool>>::iterator> temp;// store iterator so can change to false later(already booked by someone)
        for (long long j = 0; j < num; j++)
        {
            string flight, seat;
            cin >> flight >> seat;
            auto it=lower_bound(voucher.begin(),voucher.end(),make_pair(make_pair(flight,seat),true));
            if (it!=voucher.end() && (*it)==make_pair(make_pair(flight,seat),true))
            {
                temp.push_back(it);
            }else{
                isAccept=false;
            }
            
        }
        if (isAccept)
        {
            for(auto it:temp)
            {
               (*it).second=false;
            }
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}