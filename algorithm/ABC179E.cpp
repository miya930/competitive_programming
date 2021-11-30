#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;

    ll a = x;
    vector<ll> start, loop;
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        mp[a]++;
        if (mp[a] == 3) break;
        a = a*a%m;
    }
    
    a = x;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (mp[a] == 1) start.push_back(a);
        else {
            if (mp[a] == 3) {
                cnt++;
                if (cnt == 2) break;
            }
            loop.push_back(a);
        }
        a = a*a%m;
    }

    ll ans = 0;
    if (n <= start.size()) {
        for (int i = 0; i < n; ++i) ans += start[i];
        cout << ans << endl;
        return 0;
    } else {
        for (int i = 0; i < start.size(); ++i) ans += start[i];
        n -= start.size();
    }

    ll div, mod;
    div = n / loop.size();
    mod = n % loop.size();

    ll sum = 0;
    for (int i = 0; i < loop.size(); ++i) sum += loop[i];
    
    ans += div*sum;
    n -= div*loop.size();

    for (int i = 0; i < mod; ++i) ans += loop[i];

    cout << ans << endl;

    return 0;
}
