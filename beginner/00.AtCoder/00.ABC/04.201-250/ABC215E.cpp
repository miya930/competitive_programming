#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll dp[1010][1<<10][11];

int main()
{
    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;
    dp[0][0][10] = 1;

    for (int i = 0; i < n; ++i) {
        int shift = s[i] - 'A';
        for (int j = 0; j < (1<<10); ++j) {
            for (int k = 0; k < 11; ++k) {
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j][k] %= mod;

                if (j & (1<<shift) && shift != k) continue;
                dp[i+1][j|1<<shift][shift] += dp[i][j][k];
                dp[i+1][j|1<<shift][shift] %= mod;
                
            }
        }
    }

    for (int i = 1; i < 1<<10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;

}
