#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }

    const int val = 100000;

    ll ans = 0;
    for (auto x : mp) {
        ll b = val - x.first;
        if (b == 50000) continue;
        else ans += (x.second * mp[b]);   
    }

    ans /= 2;
    ll tmp = mp[50000];

    cout << ans + tmp*(tmp-1)/2 << endl;

    return 0;
}
