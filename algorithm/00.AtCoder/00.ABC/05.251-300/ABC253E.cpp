#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(n+1, vector<int>(m+100, 0));
    vector<ll> sum(m+100);
    for (int i = 1; i <= m; ++i) dp[0][i] = 1;
    for (int i = 1; i <= m; ++i) sum[i+1] = sum[i] + dp[0][i];

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ll lo = j-k+1;
            ll up = j+k;
            if (lo < 1) lo = 1;
            if (up > m+1) up = m+1; 
            ll tmp = sum[up] - sum[lo];

            ll al = (sum[m+1] - sum[1] - tmp + mod)%mod;

            dp[i][j] += al;
            dp[i][j] %= mod;
        }

        sum[1] = 0;
        for (int j = 1; j <= m; ++j) {
            sum[i+1] = sum[i] + dp[i][j];
            sum[i+1] %= mod;
        }
    }

    ll ans = 0;
    
    for (int i = 1; i <= m; ++i) {
        ans += dp[n-1][i];
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
