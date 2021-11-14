#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<vector<double> > dp(n+1, vector<double>(n+1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n+1; ++j) {
            dp[i+1][j+1] += dp[i][j]*p[i];
            dp[i+1][j] += dp[i][j]*(1-p[i]);
        }
    }

    double ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (n-i < i) ans += dp[n][i];
    }
    printf("%.10f\n", ans);
    return  0;
}
