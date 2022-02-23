#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dp[3010][3010];

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double limit = (double)e/(double)100;
    dp[0][0] = true;
    int ans1 = 100*a, ans2 = 0;
    double ma = 0;

    for (int i = 1; i <= f; ++i) {
        for (int j = 0; j <= i+1; ++j) {
            if (i-100*a >= 0) dp[i][j] |= dp[i-100*a][j];
            if (i-100*b >= 0) dp[i][j] |= dp[i-100*b][j];

            if (i-c >= 0 && j-c >= 0) dp[i][j] |= dp[i-c][j-c];
            if (i-d >= 0 && j-d >= 0) dp[i][j] |= dp[i-d][j-d];

            if (dp[i][j] && j*100 <= e*(i-j) && 0 < j) {
                double x = 1.0 * 100 * j / i;
                if (ma < x) {
                    ans1 = i;
                    ans2 = j;
                    ma = x;
                }
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;
    return 0;
}
