#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(2));
    ll ans = infl;

    for (int t = 0; t < 2; ++t) {
        dp[1][t] = a[1]*t;
        dp[1][1-t] = infl;

        for (int i = 2; i <= n; ++i) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i];
        }

        if (t == 0) ans = min(ans, dp[n][1]);
        else ans = min(ans, min(dp[n][1], dp[n][0]));
    }

    cout << ans << endl;
    return 0;
}
