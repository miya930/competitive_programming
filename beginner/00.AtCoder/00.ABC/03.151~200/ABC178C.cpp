#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

ll modpow(ll n, ll m) {
    ll res = 1;
    for (ll i = 0; i < n; ++i) res = res * m % MOD;
    return res;
}

int main()
{
    ll n; cin >> n;

    ll ans = modpow(n, 10) - 2 * modpow(n, 9) + modpow(n, 8);
    ans %= MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}
