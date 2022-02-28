#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll t = modpow(b, c, 4LL);
    ll ans = modpow(a, t+4, 10LL);

    cout << ans << endl;
    return 0;
}
