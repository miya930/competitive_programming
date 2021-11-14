#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 60;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long> > dp(n, vector<long long>(n, INF));

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--; b--;
        dp[a][b] = w;
        dp[b][a] = w;
    }

    for (int v = 0; v < n; ++v) dp[v][v] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    long long ans = INF;
    for (int i = 0; i < n; ++i) {
        long long temp = 0;
        for (int j = 0; j < n; ++j) {
            temp = max(temp, dp[i][j]);
        }
        ans = min(ans, temp);
    }

    cout << ans << endl;
}
