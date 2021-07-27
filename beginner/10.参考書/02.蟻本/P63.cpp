#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;

void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
}
