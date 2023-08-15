#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    map<vector<int>, ll> mp;
    vector<int> cnt(10, 0);
    mp[cnt]++;
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i]-'0']++;
        cnt[s[i]-'0'] %= 2;
        mp[cnt]++;
    }
    ll ans = 0;
    for (auto x : mp) {
        ll num = x.second;
        ans += (num*(num-1)/2);
    }

    cout << ans << endl;
    return 0;
}
