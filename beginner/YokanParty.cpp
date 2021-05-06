#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 200000000;

int main(void)
{
    int k, n, l;
    cin >> n >> l >> k;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    // i番目の切れ目を選び、j個の切れ目を選んだ時のスコアの最大値
    vector<vector<int> > dp(n, vector<int>(k+1));

    dp[0][0] = 0;
    for (int i = 1; i < k; ++i) dp[0][i] = 0;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i+1][j] = 
        }
    }

}
