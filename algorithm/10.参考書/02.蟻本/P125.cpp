#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll modpow(ll x, ll n, ll mod) { // x^n % n の計算
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

vector<bool> is_prime(70000, true);

int main()
{
    ll n;
    cin >> n;

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= (int)is_prime.size(); ++i) {
        for (int j = 2*i; j <= (int)is_prime.size(); j += i) is_prime[j] = false;
    }

    if (is_prime[n]) {
        cout << "No" << endl;
        return 0;
    }

    bool ans = true;
    for (int i = 2; i < n; ++i) {
        if (i != modpow(i, n, n)) ans = false;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
