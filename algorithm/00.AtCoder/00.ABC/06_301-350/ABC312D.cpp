#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

vector<vector<ll>> dp(4000, vector<ll>(7000));
int base = 3500;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    dp[0][base] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 3000; j++) {
            if (s[i] == '(') {
                dp[i+1][j+1+base] += dp[i][j+base];
                dp[i+1][j+1+base] %= mod;
            } else if (s[i] == '?') {
                // '('の場合
                dp[i+1][j+1+base] += dp[i][j+base];
                dp[i+1][j+1+base] %= mod;
                // ')'の場合
                if (j-1 >= 0) {
                    dp[i+1][j-1+base] += dp[i][j+base];
                    dp[i+1][j-1+base] %= mod;
                }
            } else {
                if (j-1 >= 0) {
                    dp[i+1][j-1+base] += dp[i][j+base];
                    dp[i+1][j-1+base] %= mod;
                }
            }
        }
    }

    cout << dp[n][base] << endl;

    return 0;
}
