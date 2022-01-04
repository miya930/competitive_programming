#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> vec(n);
    map<ll,ll> mp;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        mp[vec[i]]++;
    }

    ll ans = 0;
    for (auto x : mp) {
        ll cnt = x.second;
        ans += (cnt * (cnt-1))/2;
    }

    cout << ans << endl;
    return 0;
}
