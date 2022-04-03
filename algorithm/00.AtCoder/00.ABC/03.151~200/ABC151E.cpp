#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 210000;
const ll mod = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod/i) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll com(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    COMinit();
    ll ma = 0, mi = 0;
    for (ll i = k-1; i < n; ++i) {
        ma += ((a[i]%mod) * com(i, k-1));
        ma %= mod;
    }

    sort(a.rbegin(), a.rend());
    for (ll i = k-1; i < n; ++i) {
        mi += ((a[i]%mod) * com(i, k-1));
        mi %= mod;
    }

    cout << (ma-mi+mod)%mod << endl;
    return 0;
}
