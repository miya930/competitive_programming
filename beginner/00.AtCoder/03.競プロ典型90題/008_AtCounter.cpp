/**
 * ã£ÉvÉçìTå^90ñ‚
 * 008 - AtCounter
 * link : https://atcoder.jp/contests/typical90/tasks/typical90_h
 * 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[100009][8];

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    dp[0][0] = 1;

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 8; ++j) {
            dp[i+1][j] += dp[i][j];
            if (s[i] == 'a' && j == 0) dp[i+1][j+1] += dp[i][j];
            if (s[i] == 't' && j == 1) dp[i+1][j+1] += dp[i][j];
            if (s[i] == 'c' && j == 2) dp[i+1][j+1] += dp[i][j];
            if (s[i] == 'o' && j == 3) dp[i+1][j+1] += dp[i][j];
            if (s[i] == 'd' && j == 4) dp[i+1][j+1] += dp[i][j];
            if (s[i] == 'e' && j == 5) dp[i+1][j+1] += dp[i][j];
            if (s[i] == 'r' && j == 6) dp[i+1][j+1] += dp[i][j];
        }
        for (ll j = 0; j < 8; ++j) dp[i+1][j] %= mod;
    }

    cout << dp[n][7] << endl;
}