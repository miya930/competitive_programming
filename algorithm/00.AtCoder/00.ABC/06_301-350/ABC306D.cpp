#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
            dp[i+1][1] = max(dp[i+1][1], dp[i][1]);

            if (x[i] == 0) {
                dp[i+1][0] = max(dp[i+1][0], dp[i][0] + y[i]);
                dp[i+1][0] = max(dp[i+1][0], dp[i][1] + y[i]);
            } else {
                dp[i+1][1] = max(dp[i+1][1], dp[i][0] + y[i]);
            }
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}
