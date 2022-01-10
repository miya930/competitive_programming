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

ll modcom(ll n) {
    return modpow(n, mod-2) % mod;
}

int main()
{
    ll n, k;
    cin >> n >> k;

    ll pos = n-k+1;
    for (ll i = 1; i <= k; ++i) {
        ll a = 1, b = 1;
        ll diff = pos - i;
        
        for (ll j = 1; j <= pos; ++j) {
            a *= j;
            a %= mod;
        }
        for (ll j = 1; j <= i; ++j) {
            b *= j;
            b %= mod;
        }
        for (ll j = 1; j <= diff; ++j) {
            b *= j;
            b %= mod;
        }
        ll tmp = a * modcom(b) % mod;

        a = 1; b = 1;
        ll tmp1 = k - 1;
        for (ll j = 1; j <= tmp1; ++j) {
            a *= j;
            a %= mod;
        }
        for (ll j = 1; j <= tmp1 - (i-1); ++j) {
            b *= j;
            b %= mod;
        }
        for (ll j = 1; j <= i-1; ++j) {
            b *= j;
            b %= mod;
        }
        ll tmp2 = a * modcom(b) % mod;
        if (pos < i) cout << 0 << endl;
        else cout << tmp * tmp2 % mod << endl;
    }

    return 0;
}
