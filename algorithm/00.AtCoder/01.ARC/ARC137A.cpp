#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

ll gcd(ll n, ll m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    ll l, r;
    cin >> l >> r;

    ll ans = 0;
    for (ll i = l; i <= l+2000LL; ++i) {
        for (ll j = max(l, r-2000LL); j <= r; ++j) {
            ll g = gcd(i, j);
            if (g == 1) {
                ans = max(ans, j-i);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
