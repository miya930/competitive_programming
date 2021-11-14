#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

vector<ll> func(ll n) {
    vector<ll> res;
    for (ll i = 1; i*i <= n; ++i) {
        if (n%i != 0) continue;
        res.push_back(i);
        if (n/i != i) res.push_back(n/i);
    }
    sort(res.begin(), res.end());

    return res;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> vec = func(n);

    ll ans = 0;
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (vec[i] >= (n/vec[i]-1)) break;
        ans += (n/vec[i]-1);
    }

    cout << ans << endl;

    return 0;
}
