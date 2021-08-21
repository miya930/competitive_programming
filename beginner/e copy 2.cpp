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
    
    dp[1][s[0]-'A'][1] = 1;

    for (int i = 1; i < n; ++i) {
        dp[i+1][s[i]-'A'][1]++;
        for (int j = 0; j < 10; ++j) {
            for (int k = 1; k < i; ++k) {
                if (k > 1) {
                    if ((int)(s[i]-'A') != j) {
                        if (i < n-1) continue;
                        else {
                            dp[i+1][s[i]-'A'][1] += dp[i][j][k];
                            dp[i+1][s[i]-'A'][1] %= mod;
                        }
                    }
                    dp[i+1][s[i]-'A'][k+1] += dp[i][s[i]-'A'][k];
                    dp[i+1][s[i]-'A'][k+1] %= mod;
                } else {
                    if ((int)(s[i]-'A') == j) {
                        dp[i+1][j][k+1] += dp[i][j][k];
                        dp[i+1][j][k+1] %= mod;
                    } else {
                        dp[i+1][s[i]-'A'][k] += dp[i][j][k];
                        dp[i+1][s[i]-'A'][k] %= mod;
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
