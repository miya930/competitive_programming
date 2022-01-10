#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
unsigned long long power10[22];

ll modpow(ll a, ll b, ll m) {
    ll p = 1, q = a;
    for (int i = 0; i < 30; ++i) {
        if ((b & (1LL<<i)) != 0) {
            p *= q;
            p %= m;
        }
        q *= q;
        q %= m;
    }
    return p;
}

ll div(ll a, ll b, ll m) {
    return (a * modpow(b, m-2, m)) % m;
}

void init() {
    power10[0] = 1;
    for (int i = 1; i <=19; ++i) power10[i] = power10[i-1] * 10ULL;
}

ll f(ll x) {
    ll v1 = x % mod;
    ll v2 = (x + 1) % mod;
    ll v = v1 * v2 % mod;
    return div(v, 2, mod);
}

int main()
{
    init();
    unsigned long long l, r;
    cin >> l >> r;

    ll ans = 0;
    for (int i = 1; i <= 19; ++i) {
        unsigned long long vl = max(l, power10[i-1]);
        unsigned long long vr = min(r, power10[i] - 1ULL);
        if (vl > vr) continue;
        ll val = (f(vr) - f(vl-1) + mod) % mod; // ó›êœòaìIÇ»çlÇ¶ï˚
        ans += 1LL * i * val;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
