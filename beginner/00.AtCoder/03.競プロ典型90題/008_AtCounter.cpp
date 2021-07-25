/**
 * ã£ÉvÉçìTå^90ñ‚
 * 008 - AtCounter
 * link : https://atcoder.jp/contests/typical90/tasks/typical90_h
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int mod = 1000000007;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    string t = "atcoder";
    vector<vector<long long> > dp(n+2, vector<long long>(10, 0));

    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 7; ++j) {
            if (s[i]==t[j] && j < 7) dp[i+1][j+1] += dp[i][j];
            dp[i+1][j] += dp[i][j]; 
            dp[i+1][j] %= mod;
            dp[i+1][j+1] %= mod;
        }
    }
    cout << dp[n][7] << endl;
}
