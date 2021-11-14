/**
   created: 21.10.2021 23:03:59
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
const int mod = 1000000007;

ll func(ll m, ll n) { // m^n
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * m %mod;
        m *= m;
        m %= mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n ,p;
    cin >> n >> p;

    cout << ((p-1)*func(p-2, n-1))%mod << endl;

    return 0;
}
