#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll func(ll n ,ll m, ll mod) {
    ll res = 1;
    while (m > 0) {
        if (m&1) res = res * n % mod;
        n *= n;
        n %= mod;
        m >>= 1;
    }
    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    ll temp = func(10, n, m*m);
    cout << (temp/m)%m << endl;    

    return 0;
}
