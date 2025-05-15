#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
ll n, m;
vector<vector<mint>> dp(70, vector<mint>(80));

int main()
{
    cin >> n >> m;

    if (n > 60) {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 61; j++) {
            for (int k = j+1; k < 61; k++) {
                ll upper = min((1LL<<k) - 1, m);
                ll lower = (1LL<<(k-1));
                if (upper < lower) continue;
                dp[i+1][k] += dp[i][j] * (upper - lower + 1);
            }
        }
    }
    mint ans = 0;
    for (int i = 0; i <= 60; i++) {
        ans += dp[n][i];
    }
    cout << ans.val() << endl;
    return 0;
}
