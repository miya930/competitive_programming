#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

ll modpow(ll n, ll m) {
    ll res = 1;
    while (m > 0) {
        if (m & 1) res = (res * n) % mod;
        m >>= 1;
        n *= n;
        n %= mod;
    }
    return res;
}

ll modinv(ll n, ll p) {
    return modpow(n, p-2);
}

int main()
{
    ll n ,k;
    cin >> n >> k;

    for (int i = 1; i <= k; ++i) {
        
    }

    return 0;
}
