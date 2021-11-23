#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

ll modpow(ll n, ll m, ll mo) {
    ll res = 1;
    n %= mo;
    while (m > 0) {
        if (m&1) res = res * n % mo;
        m >>= 1;
        n *= n;
        n %= mo;
    }
    return res;
}

int main()
{
    ll n, k, m;
    cin >> n >> k >> m;

    if (m%mod == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll r = modpow(k, n, mod-1);
    ll ans = modpow(m, r, mod);
    
    cout << ans << endl;

    return 0;
}
