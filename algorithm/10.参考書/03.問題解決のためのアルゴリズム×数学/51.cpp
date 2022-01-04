#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

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

    ll n = x+y;

    ll tmp1 = 1, tmp2 = 1, tmp3 = 1;
    for (ll i = 1; i <= n; ++i) {
        tmp1 *= i;
        tmp1 %= mod;
    }
    for (ll i = 1; i <= x; ++i) {
        tmp2 *= i;
        tmp2 %= mod;
    }
    for (ll i = 1; i <= y; ++i) {
        tmp3 *= i;
        tmp3 %= mod;
    }
    tmp2 = tmp2 * tmp3 % mod;

    cout << tmp1 * modcom(tmp2) % mod << endl;

    return 0;
}
