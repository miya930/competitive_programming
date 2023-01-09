#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[110][110][110];

int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            for (int l = 0; l < 110; l++) dp[i][j][l] = -1;
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l < d; l++) {
                if (dp[i][j][l] == -1) continue;
                if (j != k) {
                    dp[i+1][j+1][(l+a[i])%d] = max(dp[i][j][l]+a[i], dp[i+1][j+1][(l+a[i])%d]);
                }
                
                dp[i+1][j][l] = max(dp[i][j][l], dp[i+1][j][l]);
            }
        }
    }

    cout << dp[n][k][0] << endl;

    return 0;
}
