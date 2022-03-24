#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<vector<bool>> dp(n+1, vector<bool>(10010, false));
    dp[0][0] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            dp[i+1][j] = dp[i+1][j] | dp[i][j];
            if (j+s[i] <= 10000) dp[i+1][j+s[i]] = dp[i+1][j+s[i]] | dp[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i <= 10000; ++i) {
        if (dp[n][i] && i%10 != 0) ans = max(ans, i);
    }

    cout << ans << endl;
    return 0;
}
 