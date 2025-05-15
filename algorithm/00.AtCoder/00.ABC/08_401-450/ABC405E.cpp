#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };
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

template <class T> T modcomb(T n, T r, T mo) {
    T a = 1, b = 1;
    for (T i = 1; i <= n; ++i) {
        a *= i;
        a %= mo;
    }
    for (T i = 1; i <= r; ++i) {
        b *= i;
        b %= mo;
    }
    for (T i = 1; i <= n-r; ++i) {
        b *= i;
        b %= mo;
    }

    return a * moddiv(b, mo) % mo;
}


int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = 0;
    
    ll n1 = 1, r1 = 1;

    for (int i = 0; i <= c; i++) {
        ans += modcomb(a+b+i, b, mod) * modcomb(c-i+d-1, d-1, mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
