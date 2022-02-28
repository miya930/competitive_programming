#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 10;
 
template <class T> T modpow(T n, T m, T mo) {
    T res = 1;
    while(m > 0) {
        if (m & 1) {
            res = res * n;
            if (res != mo) res %= mo;
        }
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
 
    ll aa = a, cnta = 0;
    while (1) {
        aa = aa * a % mod;
        cnta++;
        if ((aa%mod) == (a%mod)) break;
    }
 
    ll res = modpow(b, c, cnta);
    ll ans = 1;
    for (int i = 0; i < res+cnta; ++i) ans = ans * a%mod;
    cout << ans%mod << endl;
 
    return 0;
}