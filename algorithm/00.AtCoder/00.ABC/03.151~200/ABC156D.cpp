#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

ll modpow(ll n, ll m) {
    ll res = 1;
    while (m > 0) {
        if(m & 1) res = res * n % mod;
        n *= n;
        n %= mod;
        m >>= 1;
    }
    return res;
}

ll modinv(ll a, ll p) {
    return(modpow(a, p-2));
}

ll modfunc(ll a, ll b) {
    ll res = 1;
    for (ll i = a; i > a-b; --i) {
        res *= i;
        res %= mod;
    }
    return res;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    ll ans = modpow(2, n) - 1;
    
    ll na = modfunc(n, a);
    ll aa = modfunc(a, a);
    ll nb = modfunc(n, b);
    ll bb = modfunc(b, b);

    ll modaa = modinv(aa, mod);
    ll modbb = modinv(bb, mod);

    cout << (ans - na*modaa%mod + mod - nb*modbb%mod + mod) % mod << endl;

}
