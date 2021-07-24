#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int mod = 1000000007;

int main()
{
    string s;
    cin >> s;

    int n = (int)s.size();
    string t = "chokudai";

    vector<vector<long long> > dp(n+2, vector<long long>(10, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= n; ++i) dp[i][0] = 1; 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (s[i]==t[j]) dp[i+1][j+1] += dp[i][j];
            if (s[i]!=t[j]) dp[i+1][j] += dp[i][j];
            dp[i+1][j+1] %= mod;
            dp[i+1][j] %= mod;
        }
    }

    cout << dp[n][8] << endl;
}
