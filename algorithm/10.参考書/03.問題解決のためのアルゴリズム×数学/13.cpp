#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> func(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
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
    int sz = vec.size();

    for (int i = 0; i < sz; ++i) cout << vec[i] << endl;
    return 0;
}
