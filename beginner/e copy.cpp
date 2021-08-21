#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll dp[1010][11][1010];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    for (int i = 0; i < 10; ++i) dp[1][i][1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 1; k <= i; ++k) {
                if (k > 1) {
                    dp[i+1][j][k+1] += dp[i][j][k];
                    dp[i+1][j][k+1] %= mod;
                    if (i == n-1) {
                        for (int l = 0; l < 10; ++l) {
                            if (j == l) continue;
                            dp[i+1][l][1] += dp[i][j][k];
                            dp[i+1][l][1] %= mod;
                        }
                    }
                } else if (k == 1) {
                    for (int l = 0; l < 10; ++l) {
                        if (j == l) continue;
                        dp[i+1][l][1] += dp[i][j][k];
                        dp[i+1][l][1] %= mod;
                    }
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= n; ++j) {
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;

}
