#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> p(n), a(n);
    for (int i = 0; i < n; ++i) cin >> p[i] >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 0; --j) {
            if (i+1 <= n && i+1 <= p[i] && p[i] <= j) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i]);
            if (1 <= j-1 && i <= p[i] && p[i]-1 <= j) dp[i][j-1] = max(dp[i][j+1], dp[i][j] + a[i]);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
