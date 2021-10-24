/**
   created: 23.10.2021 18:36:47
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
const int mod = 1000000007;

ll kaijo(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; ++i) {
        res *= i;
        res %= mod;
    }
    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    if (abs(n-m) >= 2) {
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = kaijo(n)*kaijo(m)%mod;

    if (n == m) ans *= 2;
    
    cout << ans%mod << endl;

    return 0;
}
