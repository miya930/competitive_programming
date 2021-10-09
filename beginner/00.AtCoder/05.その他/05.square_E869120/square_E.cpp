/***
 * E869120 and Path Length
 * https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_e
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

ll modpow(ll n, ll m) // n^m
{
    ll res = 1;
    while (m > 0) {
        if (m & 1) res = res * n % mod;
        n = n * n % mod;
        m >>= 1;
    }
    return res;
}

int main()
{
    int n, Q;
    cin >> n >> Q;

    vector<ll> a(n), c(Q+2);
    vector<ll> sum(n+1, 0);
    c[0] = 0; c[Q+1] = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int q = 1; q <= Q; ++q) {
        long long t; cin >> t;
        t--;
        c[q] = t;
    }

    for (int i = 0 ; i < n; ++i) sum[i+1] = sum[i] + modpow(a[i], a[i+1]);

    ll ans = 0;

    for (int i = 1; i < (int)c.size(); ++i) {
        ans += (ll)abs(sum[c[i]] - sum[c[i-1]]);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;

}
