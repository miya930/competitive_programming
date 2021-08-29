#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int dp[210][210];
bool use[210][210];

int main()
{
    int d, n;
    cin >> d >> n;
    vector<int> t(d), a(n), b(n), c(n);
    rep(i, d) cin >> t[i];
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    rep(i, d+1) rep(j, n) dp[i][j] = 0;
    rep(i, n) {
        if (a[i] <= t[0] & t[0] <= b[i]) use[1][i] = true;
    }

    for (int i = 1; i < d; ++i) rep(j, n) rep(k, n) {
        if (t[i] < a[k] || b[k] < t[i] || !use[i][j]) continue;
        dp[i+1][k] = max(dp[i+1][k] ,dp[i][j] + abs(c[k]-c[j]));
        use[i+1][k] = true;
    }

    int ans = 0;
    rep(i, n) ans = max(ans, dp[d][i]);

    cout << ans << endl;
}
