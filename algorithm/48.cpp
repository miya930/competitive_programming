#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

ll sum(ll n) {
    ll res = 0;
    while (n > 0) {
        res += (n%10);
        n /= 10;
    }
    return res;
}

int main()
{
    ll k;
    cin >> k;

    vector<ll> vec;
    bool seen = false;
    map<ll, ll> mp;
    ll cnt = 1;

    while (!seen) {
        ll tmp = sum(cnt*k);
        mp[tmp]++;
        cnt++;
        if (mp[tmp] > 1) seen = true;
    }

    ll ans = infl;
    for (auto x : mp) {
        ans = min(ans, x.first);
    }

    cout << ans << endl;
    return 0;
}
