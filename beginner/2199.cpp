#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1001001001;

int main()
{
    while(1)  {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<int> c(m), x(n);
        for (int i = 0; i < m; ++i) cin >> c[i];
        for (int i = 0; i < n; ++i) {
            int temp; cin >> temp;
            x[i] = temp - 128;
        }

        vector<vector<int> > dp(n+1, vector<int>(256, INF));
        vector<vector<bool> > seen(n+1, vector<bool>(256, false));
        dp[0][0] = 0;
        seen[0][0] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 255; ++j) {
                if (!seen[i][j]) continue;
                for (int k = 0; k < m; ++k) {
                    int temp = j + c[k];
                    if (temp <= 0) temp = 0;
                    else if (temp >= 255) temp = 255;
                    dp[i+1][temp] = min(dp[i+1][temp], dp[i][j]+(temp-x[i])*(temp-x[i]));
                    seen[i+1][temp] = true;
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < 256; ++i) ans = min(ans, dp[n][i]);
        cout << ans << endl;
    }

}
