#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modpow(ll x, ll m, ll mod) { // x^m
    ll res = 1;
    while(m > 0) {
        if (m%2 == 1) res = res * x % mod;
        m >>= 1;
        x *= x;
        x %= mod;
    }
    return res;
}

int main()
{
    ll n;
    cin >> n;
    vector<bool> vec(70000, true);
    vec[0] = false; vec[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (vec[i] == false) continue;
        for (int j = i*2; j <= n; j += i) {
            vec[j] = false;
        } 
    }

    bool flag = true;
    if (vec[n]) flag = false;
    for (ll i = 1; i <= n; ++i) {
        ll t = modpow(i, n, n);
        if (t != (i%n)) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
