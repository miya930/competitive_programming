#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) cin >> s[i] >> t[i];

    map<string,ll> mp;
    ll ans = 0, val = 0;
    for (int i = 0; i < n; ++i) {
        if (mp[s[i]] == 0LL) {
            mp[s[i]] = t[i];
            if (val < t[i]) {
                val = t[i];
                ans = i+1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
