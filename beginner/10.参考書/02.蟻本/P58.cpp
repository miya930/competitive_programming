#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, W;
vector<vector<int> > dp;

vector<int> w, v;

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= W; ++j) {
            for (int k = 0; k + w[i] <= j; ++k) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*w[i]] + k*v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}