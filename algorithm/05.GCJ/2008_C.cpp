#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

double dp[2][(1 << 15)+1];

int main()
{
    int m, x;
    double p;
    cin >> m >> p > x;

    int n = 1 << m;

    double *prev = dp[0], *next = dp[1];
    memset(prev, 0, sizeof(double)*(n+1));
    prev[n] = 1.0;

    for (int r = 0; r < m; r++) {
        for (int i = 0; i <= n; ++i) {
            int jub = min(i, n-i);
            double t = 0.0;
            for (int j = 0; j <= jud; ++j) {
                t = max(t, p*prev[i+j]+(1-p)*prev[i-j]);
            }
            next[i] = t;
        }
        swap(prev, next);
    }

    int i = (long long) x * n / 1000000;
    printf("%.6f\n", prev[i]);
}
