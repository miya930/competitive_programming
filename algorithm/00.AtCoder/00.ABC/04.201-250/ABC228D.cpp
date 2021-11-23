#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int n = 1<<20;

int main()
{
    int Q;
    cin >> Q;
    map<ll, ll> mp;
    map<ll ,ll> val;
    mp[n] = 0;

    for (int q = 0; q < Q; ++q) {
        int t; ll x;
        cin >> t >> x;
        auto i = x % n;

        if (t == 1) {
            auto itr = mp.upper_bound(i);
            if (itr == mp.end()) {
                i = 0;
                itr = mp.begin();
            }
            if (itr->second <= i) {
                val[i] = x;
                ll l1 = itr->second, r1 = i, l2 = i+1, r2 = itr->first;
                mp.erase(itr);
                if (l1 != r1) mp[r1] = l1;
                if (l2 != r2) mp[r2] = l2;
            } else {
                val[itr->second] = x;
                itr->second++;
                if (itr->second == itr->first) mp.erase(itr);
            }
        } else {
            auto itr = val.find(x%n);
            cout << ((itr == val.end()) ? -1 : itr->second) << endl;
        }
    }

    return 0;
}

