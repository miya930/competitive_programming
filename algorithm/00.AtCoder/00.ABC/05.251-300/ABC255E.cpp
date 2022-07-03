#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n ,m;
    cin >> n >> m;
    vector<ll> s(n-1), x(m);
    for (int i = 0; i < n-1; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> x[i];

    vector<ll> a(n);
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        a[i] = s[i-1] - a[i-1];
    }

    ll ans = 0;
    map<ll,ll> mp;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll c = a[i] - x[j];
            if (i%2 == 0) c *= -1;
            mp[c]++;
        }
    }

    for (auto xx : mp) {
        ans = max(ans, xx.second);
    }

    cout << ans << endl;
    return 0;
}
