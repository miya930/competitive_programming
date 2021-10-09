#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;

int main()
{
    int n ,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n ;++i) cin >> a[i];

    vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int m = 0; m <= a[i]; ++m) {
                if (j-m>=0) dp[i+1][j] += dp[i][j-m];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][k] << endl;
}
