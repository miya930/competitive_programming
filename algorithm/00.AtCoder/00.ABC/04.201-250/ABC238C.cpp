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

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    ll z = 10;
    ll cnt = 18;
    while(cnt > 0) {

        ll l = z/10;
        ll r = min(n, z-1);

        if (l <= r) ans = ans + ((((r-l+1)%mod) * ((2+r-l)%mod))%mod * moddiv(2LL, mod));
        ans %= mod;

        z *= 10;
        cnt--;
    }

    cout << ans << endl;
    return 0;
}
