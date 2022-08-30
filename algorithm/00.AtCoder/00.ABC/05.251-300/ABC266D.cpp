#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a(100000), x(100000);

int main()
{
    int n;
    cin >> n;
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) {
        ll xx, aa;
        cin >> t[i] >> xx >> aa;
        x[t[i]] = xx;
        a[t[i]] = aa;
    }

    vector<vector<ll>> dp(100010, vector<ll>(5));

    for (int i = 1; i < 5; ++i) dp[0][i] = -1e18;

    for (int i = 1; i <= 100000; ++i) {
        for (int j = 0; j < 5; ++j) {
            dp[i][j] =dp[i-1][j];
            if (j != 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            if (j != 4) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
        }
        dp[i][x[i]] += a[i];
    }

    ll ans = 0;
    for (int i = 0; i < 5; ++i) {
        ans = max(ans, dp[100000][i]);
    }

    cout << ans << endl;
    return 0;
}
