#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    map<char,ll> mp;
    for (ll i = 0; i < n; ++i) mp[s[i]]++;
    ll ans = 1;

    for (auto x : mp) {
        ans *= (x.second+1);
        ans %= mod;        
    }

    cout << ans-1 << endl;
    return 0;
}
