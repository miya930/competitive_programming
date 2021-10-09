#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int dp[310][610][610];

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 310; ++j) {
            for (int k = 0; k < 310; ++k) dp[i][j][k] = INF;
        }
    }
    
    dp[0][0][0] = 0;

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            for (int k = 0; k <= y; ++k) {
                if (dp[i][j][k] != INF)
                    dp[i+1][min(j+a[i], x)][min(k+b[i], y)] = min(dp[i+1][min(j+a[i], x)][min(k+b[i], y)], dp[i][j][k]+1);
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }

    if(dp[n][x][y] == INF) cout << -1 << endl;
    else cout << dp[n][x][y] << endl; 

    return 0;
}
