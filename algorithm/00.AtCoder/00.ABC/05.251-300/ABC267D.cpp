#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, -infl));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i+1][j]   = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(j+1)*a[i]);
        }
    }

    ll ans = -infl;
    for (int i = m; i <= n; ++i) {
        ans = max(ans, dp[i][m]);
    }

    cout << ans << endl;
    return 0;
}
