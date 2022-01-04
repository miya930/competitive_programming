#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans = 0;
ll n, x;
vector<ll> l;
vector<vector<ll>> a;

void func(ll i, ll mul) {

    if (mul > x) return;

    if (i == n-1) {
        for (ll idx = 0; idx < l[i]; ++idx) {
            if (mul*a[i][idx] == x) ans++;
        }
        return;
    } else {
        for (ll idx = 0; idx < l[i]; ++idx) {
            if (a[i][idx] >= LONG_LONG_MAX/mul) continue;
            func(i+1, mul*a[i][idx]);
        }
    }    
}

int main()
{
    cin >> n >> x;
    l.resize(n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        for (int j = 0; j < l[i]; ++j) {
            ll tmp; cin >> tmp;
            a[i].push_back(tmp);
        }
    }

    func(0, 1);
    
    cout << ans << endl;

    return 0;
}
