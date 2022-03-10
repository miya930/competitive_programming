#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(10, 0)); 

    for (int i = 0; i < 9; ++i) dp[0][i] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 9; ++j) {
            dp[i+1][j] += dp[i][j];
            if (j+1 < 9) dp[i+1][j+1] += dp[i][j];
            if (j-1 >= 0) dp[i+1][j-1] += dp[i][j];

            dp[i+1][j] %= mod;
            dp[i+1][j+1] %= mod;
            dp[i+1][j-1] %= mod;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 9; ++i) {
        ans += dp[n-1][i];
        ans %= mod;
    }
    
    cout << ans << endl;
    return 0;
}
