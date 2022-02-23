#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> pa(k);
    for (int i = 0; i < k; ++i) cin >> pa[i].first >> pa[i].second;

    vector<ll> dp(n+1);
    dp[0] = 1;
    dp[1] = -1;

    for (int i = 0; i < n; ++i) {
        if (i > 0) dp[i] += dp[i-1];
        for (int j = 0; j < k; ++j) {
            int l, r;
            tie(l, r) = pa[j];
            if (i+l < n) {
                dp[i+l] += dp[i];
                dp[i+l] %= mod;
            }
            if (i+r+1 < n) {
                dp[i+r+1] -= dp[i];
                dp[i+r+1] %= mod;
            }
        }
    }

    cout << dp[n-1]%mod << endl;
    return 0;
}
