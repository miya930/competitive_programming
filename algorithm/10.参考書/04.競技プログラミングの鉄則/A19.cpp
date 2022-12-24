#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, W;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(n+1, vector<ll>(W+1, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j+w[i] <= W) dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j]+v[i]);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= W; ++i) ans = max(ans, dp[n][i]);
    cout << ans << endl;

    return 0;
}
