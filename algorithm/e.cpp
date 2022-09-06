#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    for (int i = 1; i <= m; ++i) dp[0][i] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j+k <= m) {
                for (int l = j+k; l <= m; ++l) {
                    dp[i+1][l] += dp[i][j];
                    dp[i+1][l] %= mod;
                }
            } else if (j-k >= 1) {
                for (int l = 1; l <= j-k; ++l) {
                    dp[i+1][l] += dp[i][j];
                    dp[i+1][l] %= mod;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += dp[n][i];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}
