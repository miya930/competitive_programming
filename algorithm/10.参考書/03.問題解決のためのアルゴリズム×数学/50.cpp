#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

ll modpow(ll n, ll m) {
    ll res = 1;
    while (m > 0) {
        if (m & 1) res = res * n % mod;
        m >>= 1;
        n *= n;
        n %= mod;
    }
    return res;    
}

int main()
{
    ll a, b;
    cin >> a >> b;

    cout << modpow(a, b) << endl;

    return 0;
}
