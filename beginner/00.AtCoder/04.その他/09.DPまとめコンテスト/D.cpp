#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<long long> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

    vector<vector<long long> > dp(n + 1, vector<long long>(W + 1, 0));
    for (int w = 0; w <= W; ++w) dp[0][w] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            chmax(dp[i][j], dp[i - 1][j]);
            if (j - w[i - 1] >= 0) chmax(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}
