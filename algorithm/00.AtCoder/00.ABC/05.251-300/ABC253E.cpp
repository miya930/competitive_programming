#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n+1, vector<ll>(m+10));
    vector<vector<ll>> sum(n+1, vector<ll>(m+10));

    for (int i = 1; i <= m; i++) {
        dp[1][i] = 1;
        sum[1][i] = sum[1][i-1] + 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll l = max(1, j-k+1);
            ll r = min(m, j+k-1);
            ll dif = sum[i-1][r] - sum[i-1][l-1];
            if (l > r) dif = 0;
            dp[i][j] = (sum[i-1][m] - dif + mod) % mod;
            sum[i][j] = (sum[i][j-1] + dp[i][j]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
