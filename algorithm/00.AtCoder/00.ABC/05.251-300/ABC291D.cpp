#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 0; i < n-1; i++) {
        if (a[i] != a[i+1]) {
            dp[i+1][0] += dp[i][0];
        }
        if (a[i] != b[i+1]) {
            dp[i+1][1] += dp[i][0];
        }
        if (b[i] != a[i+1]) {
            dp[i+1][0] += dp[i][1];
        }
        if (b[i] != b[i+1]) {
            dp[i+1][1] += dp[i][1];
        }
        dp[i+1][0] %= mod;
        dp[i+1][1] %= mod;
    }
    
    cout << (dp[n-1][0] + dp[n-1][1]) % mod << endl;

    return 0;
}
