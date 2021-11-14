#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 998244353;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n; ++i) cin >> a[i];

    // dp[i][j]：i回操作実施、左端の数字がj (i <= n-1)
    // dp[i+1][(a[i]+j)%10] <- dp[i][j]
    // dp[i+1][(a[i]*j)%10] <- dp[i][j]

    vector<vector<int> > dp(n, vector<int>(10, 0));

    dp[0][a[0]] = 1;
    
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (dp[i][j]) {
                dp[i+1][(a[i+1]+j)%10] += dp[i][j];
                dp[i+1][(a[i+1]+j)%10] %= mod;

                dp[i+1][(a[i+1]*j)%10] += dp[i][j];
                dp[i+1][(a[i+1]*j)%10] %= mod;
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << dp[n-1][i] << endl;
    }

    return 0;

}
