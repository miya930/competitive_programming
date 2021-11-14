#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;;

ll modpow(ll n, ll m, ll mod) {
    ll res = 1;
    while (m > 0) {
        if (m & 1) res = res * n % mod;
        n = n * n % mod;
        m >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod){
    return modpow(a, mod-2, mod);
}

ll modfac(ll a, ll mod) {
    ll res = 1;
    for (int i = 1; i <= a; i++) {
        res *= i;
        res %= mod;
    }
    return res;
}

int main()
{
    ll n, k;
    cin >> n >> k;

    ll a = modfac(n+k-1, mod);
    ll b = modfac(n-1, mod);
    ll c = modfac(k, mod);

    cout << a * (modinv(b, mod) * modinv(c, mod) % mod) % mod << endl;
}
