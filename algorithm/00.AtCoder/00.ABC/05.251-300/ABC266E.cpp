#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

int main()
{
    int n;
    cin >> n;

    vector<ld> dp(n+1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 6; j++) {
            ld tmp = (ld)1.0 * max((ld)j, dp[i]) / (ld)6.0;
            dp[i+1] += tmp;
        }
    }
    
    printf("%.10lf\n", dp[n]);
    return 0;
}
