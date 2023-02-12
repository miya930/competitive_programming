#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -infl));
    vector<ll> sum(n+1);
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + a[i/2];
    }

    dp[1][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i+1][j+1] = max(dp[i][j], dp[i+1][j+1]);
            dp[i+1][0] = max(dp[i][j] + sum[j], dp[i+1][0]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n][i]+sum[i]);
    }

    cout << ans << endl;

    return 0;
}
