/**
   created: 09.10.2021 20:12:33
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{   
    int n;
    cin >> n;
    vector<ll> a(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    map<ll, ll> mp;
    for (int i = 2; i <= n; ++i) mp[i-a[i]]++;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll sum = i + a[i];
        if (mp[sum] > 0) {
            ans += mp[sum];
            mp[i-a[i]]--;
        }
    }

    cout << ans << endl;

    return 0;
}
