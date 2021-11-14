#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int inf = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<long long> > dp(n, vector<long long>(n, inf));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
    }

    for (int i = 0; i < n; ++i)dp[i][i] = 0;

    long long ans = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] != inf) ans += dp[i][j];
            }
        }
    }
    cout << ans << endl;

}
