#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[110][2][5];

int main()
{
    string n;
    int k;
    cin >> n >> k;

    dp[0][0][0] = 1;
    for (int i = 0; i < n.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int l = 0; l < k+1; ++l) {
                int c = n[i] - '0';
                for (int t = 0; t < 10; ++t) {
                    if (c < t && j == 0) continue;

                    int jj = j;
                    if (t < c) jj = 1;
                    int l2 = l;
                    if (t != 0) l2++;

                    dp[i+1][jj][l2] += dp[i][j][l];
                }
            } 
        }
    }

    ll ans = dp[(int)n.size()][0][k] + dp[(int)n.size()][1][k];

    cout << ans << endl;
    return 0;
}
