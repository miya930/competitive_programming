#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll modpow(ll n, ll m) {
    ll res = 1;
    while (m > 0) {
        if (m & 1) res = res * n % mod;
        m >>= 1;
        n *= n;
        n %= mod;
    }
    return res;
}

ll modcom(ll b) {
    return modpow(b, mod-2);
}

int main()
{
    ll x, y;
    cin >> x >> y;

    ll a = 2*y - x;
    ll b = 2*x - y;
    if (a%3 != 0 || b%3 != 0 || a < 0 || b < 0) {
        cout << 0 << endl;
        return 0;
    }

    a /= 3;
    b /= 3;

    ll n = a + b;
    ll tmp1 = 1;
    ll tmp2 = 1;
    for (ll i = 1; i <= n; ++i) {
        tmp1 *= i;
        tmp1 %= mod;
    }
    for (ll i = 1; i <= a; ++i) {
        tmp2 *= i;
        tmp2 %= mod;
    }
    for (ll i = 1; i <= b; ++i) {
        tmp2 *= i;
        tmp2 %= mod;
    }

    cout << tmp1 * modcom(tmp2) % mod << endl;

    return 0;
}
