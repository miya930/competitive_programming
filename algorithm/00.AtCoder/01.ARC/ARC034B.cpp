#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll keta(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

int main()
{
    ll n;
    cin >> n;

    ll ma = 9*20;
    vector<ll> ans;
    for (ll i = max(0LL, n-ma); i <= n + ma; ++i) {
        ll tmp = i;
        tmp += keta(i);

        if (tmp == n) ans.push_back(i);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << endl;
    return 0;
}
