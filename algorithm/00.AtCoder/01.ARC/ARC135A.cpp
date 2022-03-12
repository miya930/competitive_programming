#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

map<ll,ll> mp;

ll func(ll x) {

    ll x1 = x/2;
    ll x2 = (x+1)/2;

    if (mp[x] != 0) return mp[x];

    if (x1 == 1 || x2 == 1) {
        mp[x] = x; 
        return x;
    }

    ll res = func(x1)%mod * func(x2)%mod;
    mp[x] = res;

    return res;

}

int main()
{
    ll x;
    cin >> x;

    cout << func(x) << endl;

    return 0;
}
