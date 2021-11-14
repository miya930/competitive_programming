#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll modpow(ll n, ll m, ll mod) {
    ll res = 1;
    while(m > 0) {
        if (m & 1) res = res * n % mod;
        n = n * n % mod;
        m >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod-2, mod);
}

ll calc(ll a, ll mod) {
    ll res = 1;
    for (int i = 1; i <= a; ++i) {
        res *= i;
        res %= mod;
    }
    return res;
}

int main()
{
    ll x, y;
    cin >> x >> y;

    if (2*x < y || 2*y < x || (2*x-y)%3 != 0 || (2*y-x)%3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll a = (2*x - y) / 3 % mod;
    ll b = (2*y - x) / 3 % mod;

    ll n = calc(a+b, mod);
    ll r = calc(a, mod);
    ll l = calc(b, mod);

    ll ans = n * (modinv(r, mod) * modinv(l, mod) % mod) % mod;
    cout << ans << endl;
}
