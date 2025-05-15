#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<mint>> dp(k+1, vector<mint>(n+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 1; l <= m; l++) {
                if (dp[i][j].val() > 0) {
                    if (j+l <= n) {
                        dp[i+1][j+l] += dp[i][j] / (mint)m;
                    } else {
                        int nxt = n - (l - (n - j));
                        dp[i+1][nxt] += dp[i][j] / (mint)m;
                    }
                }
            }
        }
        dp[i+1][n] += dp[i][n];
    }

    cout << dp[k][n].val() << endl;

    return 0;
}
