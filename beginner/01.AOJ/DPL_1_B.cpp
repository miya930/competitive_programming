// knapsack problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, w;
    cin >> n >> w;
    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++) cin >> value[i] >> weight[i];

    vector<vector<int> > dp(n+1, vector<int>(w+1));

    // èâä˙íl
    for (int i = 0; i <= w; ++i) dp[0][i] = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= w; ++j) {
            if (w >= weight[i]) dp[i+1][j] = max(dp[i][j-weight[i]]+value[i], dp[i][j]);
            else dp[i+1][j] = dp[i][j];
        }
    }

    cout << dp[n][w] << endl;
}
