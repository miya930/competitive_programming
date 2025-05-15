#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    cin >> n >>m;

    ll ans = 1LL << 60;
    for (ll i = 1; i <= n; i++) {
        ll x = (m + i -1) / i;
        if (x <= n) ans = min(ans, x*i);
        if (i > x) break;
    }

    if (ans == (1LL << 60)) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

