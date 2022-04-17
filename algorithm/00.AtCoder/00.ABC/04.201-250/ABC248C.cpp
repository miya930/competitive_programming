#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(n+1, vector<int>(n*m+1));
    for (int i = 0; i <= m; ++i) dp[1][i] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < k; ++j) {
             for (int l = 1; l <= m; ++l) {
                 if (j+l <= k) {
                     dp[i+1][j+l] += dp[i][j];
                     dp[i+1][j+l] %= mod;
                 }
             }
        }
    }

    ll ans = 0;
    for (int i = n; i <= k; ++i) {
        ans += dp[n][i];
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
