#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long mod = 1000000007;
typedef long long ll;

ll modpow(ll n, ll m, ll mod) {
    ll res = 1;
    while (m > 0) {
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
    ll h, w;
    cin >> h >> w;

    ll n = calc(h+w-2, mod);
    ll r = calc(h-1, mod);
    ll l = calc(w-1, mod);

    ll ans = n * (modinv(r, mod) * modinv(l, mod) % mod) % mod;

    cout << ans << endl;
    

}
