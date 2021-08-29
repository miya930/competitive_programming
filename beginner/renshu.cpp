#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<ll> > dp(110, vector<ll>(25, 0)); // dp[n][0~20] = 満たす個数
    dp[1][a[0]] = 1;

    for (int i = 1; i < n-1; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if (j-a[i] >= 0) dp[i+1][j] += dp[i][j-a[i]];
            if (j+a[i] <= 20)  dp[i+1][j] += dp[i][j+a[i]];
        }
    }

    cout << dp[n-1][a[n-1]] << endl;
}
