#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

template <class T> T modpow(T n, T m, T mo) {
    T res = 1;
    while(m > 0) {
        if (m & 1) res = res * n % mo;
        m >>= 1;
        n *= n;
        n %= mo;
    }
    return res;
}

template <class T> T moddiv(T n, T mo) {
    return modpow(n, mo-2, mo);
}


map<ll, ll> memo;
ll n;
ll func(ll val) {
    if (val >= n) {
        if (val == n) return 1;
        else return 0;
    }
    if (memo.count(val)) return memo[val];

    ll res = 0;
    for (ll i = 2; i <= 6; i++) {
        res += func(val*i);
        res %= mod;
    }
    res *= moddiv(5LL, mod);
    memo[val] = res;
    return res;
}

int main()
{
    cin >> n;

    cout << func(1)%mod << endl;
    return 0;
}
