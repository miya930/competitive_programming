#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
using namespace std;
const int mod = 1000000007;
typedef long long ll;

ll modpow(int n) {
    ll res = 1;
    for (int i = 0; i < n; ++i) res *= 2;
    res %= mod;
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 各a[i]のビットごとの1を累積和として計算
    vector<vector<ll> > x(n+1, vector<ll>(61, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 60; ++j) {
            if (a[i]>>j & 1) x[i+1][j] = x[i][j] + 1;
            else x[i+1][j] = x[i][j];
        }
    }

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= 60; j++) {
            if (a[i]>>j & 1) {
                ans += (modpow(j) * (i-x[i][j]));
                ans %= mod;
            } else {
                ans += modpow(j) * x[i][j];
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
