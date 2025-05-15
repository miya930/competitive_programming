#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

vector<vector<ll>> dp(110, vector<ll>(100100, infl));

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n), z(n);
    vector<pair<ll,int>> pa;
    ll zsum = 0;
    ll ini = 0;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    for (int i = 0; i < n; i++) {
        if (x[i] > y[i]) {
            ini += z[i];
            zsum += z[i];
            continue;
        }
        ll num = (x[i]+y[i]+1)/2;
        pa.push_back(make_pair(num-x[i], z[i]));
        zsum += z[i];
    }
    zsum = (zsum+1)/2;
    dp[0][ini] = 0;
    for (int i = 0; i < pa.size(); i++) {
        for (int j = 0; j < 100000; j++) {
            if (dp[i][j] == infl) continue;
            ll co = pa[i].first;
            int ge = pa[i].second;
            if (j+ge <= 100000) dp[i+1][j+ge] = min(dp[i+1][j+ge], dp[i][j] + co);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }

    ll ans = infl;
    for (int i = 0; i <= n; i++) {
        for (int j = zsum; j <= 100000; j++) {
            ans = min(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}
