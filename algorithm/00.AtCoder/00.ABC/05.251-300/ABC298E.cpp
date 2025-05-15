#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

mint dp[110][110][2];

int main()
{
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    for (int i = 0; i < n; i++) {
        for (int t = 0; t < 2; t++) {
            dp[n][i][t] = 1;
            dp[i][n][t] = 0;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            for (int k = 1; k <= p; k++) {
                dp[i][j][0] += dp[min(n, i+k)][j][1];
            }
            dp[i][j][0] /= p;
            for (int k = 1; k <= q; k++) {
                dp[i][j][1] += dp[i][min(n, j+k)][0];
            }
            dp[i][j][1] /= q;
        }
    }

    cout << dp[a][b][0].val() << endl;

    return 0;
}
