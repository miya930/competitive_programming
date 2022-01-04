#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>> func(ll n) {
    vector<pair<ll, ll>> res;
    for (ll i = 2; i * i <= n; ++i) {
        if (n%i != 0) continue;
        ll ex = 0;

        while (n%i == 0) {
            n /= i;
            ex++;
        }
        res.push_back(make_pair(i, ex));
    }
    if (n != 1) res.push_back(make_pair(n, 1));

    return res;
}

int main()
{
    ll n;
    cin >> n;

    vector<pair<ll,ll>> vec = func(n);
    int sz = vec.size();

    for (int i = 0; i < sz; ++i) {
        ll val = vec[i].first;
        ll ex = vec[i].second;
        for (int j = 0; j < ex; ++j) cout << val << " ";
    }

    return 0;
}
