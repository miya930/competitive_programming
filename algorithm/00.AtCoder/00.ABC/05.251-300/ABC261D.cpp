#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    vector<ll> cnt(5020, 0);
    for (int i = 0; i < m; ++i) {
        ll c, y;
        cin >> c >> y;
        cnt[c] = y;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(5010, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            ll tmp = dp[i][j];
            dp[i+1][0] = max(dp[i+1][0], tmp);

            tmp = dp[i][j] + x[i];
            if (cnt[j+1] != 0) tmp += cnt[j+1];
            dp[i+1][j+1] = max(dp[i+1][j+1], tmp);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (ans < dp[n][i]) ans = dp[n][i];
    }

    cout << ans << endl;

    return 0;
}
