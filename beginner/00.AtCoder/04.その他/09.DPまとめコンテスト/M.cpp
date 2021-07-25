#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
vector<vector<int> > dp(110, vector<int>(300000, 0));
vector<int> sum(110000, 0);

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        sum[0] = 0;
        for (int j = 0; j < k + 1; ++j) sum[j + 1] = (sum[j] + dp[i][j]) % mod;
        for (int l = 0; l <= k; ++l) {
            dp[i + 1][l] = (sum[l + 1] - sum[(int)max(0, l - a[i])] + mod) % mod;
        }
    }
    cout << dp[n][k] << endl;
}
