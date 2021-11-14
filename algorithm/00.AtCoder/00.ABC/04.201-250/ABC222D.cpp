/**
   created: 09.10.2021 20:12:57
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
const int mod = 998244353;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int ma = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ma = max(ma, b[i]);
    }

    vector<vector<int> > dp(n+1, vector<int>(ma+10, 0));
    vector<int> sum(ma+10, 0);
    for (int i = a[0]; i <= b[0]; ++i) dp[1][i]++;
    for (int i = 0; i < ma+1; ++i) sum[i+1] = sum[i] + dp[1][i];

    for (int i = 1; i < n; ++i) {
        for (int j = a[i]; j <= b[i]; ++j) {
            dp[i+1][j] += sum[j+1];
            dp[i+1][j] %= mod;
        }

        for (int j = 0; j < ma+1; j++) {
            sum[j+1] = sum[j] + dp[i+1][j];
            sum[j+1] %= mod;
        }
        
    }

    ll ans = 0;
    for (int i = 0; i <= ma; ++i) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}
