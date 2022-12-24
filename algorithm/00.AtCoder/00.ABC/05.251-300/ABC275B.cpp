#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    vector<ll> a(6);
    for (int i = 0;  i < 6; ++i) cin >> a[i];


    ll ans = a[0]%mod;
    for (int i = 1; i < 3; ++i) {
        ans = ans * (a[i] % mod);
        ans = ans % mod;
    }

    ll tmp = a[3]%mod;
    for (int i = 4; i < 6; ++i) {
        tmp = tmp * (a[i] % mod);
        tmp %= mod;
    }

    ans = ans - tmp;

    cout << (ans + mod) % mod << endl;

    return 0;
}
