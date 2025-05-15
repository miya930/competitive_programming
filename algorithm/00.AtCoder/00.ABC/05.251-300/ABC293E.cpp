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

ll func(ll a, ll x, ll m) {
    if (x == 0) return 0;
    ll ret;
    if (x%2 == 1) {
        ret = func(a, x-1, m) + modpow(a, x-1LL, m);
    } else {
        ret = func(a, x/2, m)*(1LL+modpow(a, x/2, m));
    }
    ret %= m;
    return ret;
}

int main()
{
    ll A, X, M;
    cin >> A >> X >> M;

    cout << func(A, X, M) << endl;
    return 0;
}
