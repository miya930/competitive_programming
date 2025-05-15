#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    dp[1][1] = m;
    for (int i = 1; i < n; i++) {
        dp[i+1][0] += dp[i][0]*(m-2);
        dp[i+1][1] += dp[i][0];
        dp[i+1][0] += dp[i][1]*(m-1);
        dp[i+1][0] %= mod;
        dp[i+1][1] %= mod;
    }
    cout << dp[n][0] << endl;

    return 0;
}
