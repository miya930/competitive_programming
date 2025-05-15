#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) a[i] = -a[i];
    }

    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; i++) sum[i+1] = sum[i] + a[i];

    map<ll, int> mp;
    for (int i = 0; i <= n; i++) mp[sum[i]]++;

    ll ans = 0;
    for (auto x : mp) {
        ans += x.second * (x.second - 1LL) / 2LL;
    }
    cout << ans << endl;

    return 0;
}
