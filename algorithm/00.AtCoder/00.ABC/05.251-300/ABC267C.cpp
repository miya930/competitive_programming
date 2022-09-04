#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + a[i];
    }

    ll si = 0;

    for (ll i = 0; i < m; ++i) {
        si += ((i+1)*a[i]);
    }

    ll ans = si;

    for (ll i = 1; i < n - m + 1; ++i) {
        si = si - (sum[m+i-1] - sum[i-1]) + m*a[m+i-1];
        ans = max(ans, si);
    }
    
    cout << ans << endl;

    return 0;
}
