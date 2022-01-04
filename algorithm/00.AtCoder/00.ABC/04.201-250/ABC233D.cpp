#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> sum (n+1, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i];

    map<ll, vector<int>> mp;
    for (int i = 1; i <= n; ++i) {
        mp[sum[i]].push_back(i-1);
    }

    ll ans = 0;

    for (auto x : mp) {
        sort(x.second.begin(), x.second.end());
    }
    
    for (auto x : mp) {
        int sz = x.second.size();

        if (x.first == k) ans += sz;

        for (int i = 0; i < sz; ++i) {
            ll idx = x.second[i];
            ll val = x.first;

            ll itr = upper_bound(mp[val+k].begin(), mp[val+k].end(), idx) - mp[val+k].begin();

            ans += (mp[val+k].size() - itr);
        }
    }

    cout << ans << endl;
    return 0;
}
