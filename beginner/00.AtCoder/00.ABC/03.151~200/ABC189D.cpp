#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n+1);
    for (int i = 1; i <= n; ++i) cin >> s[i];

    vector<vector<long long> > dp(n+1, vector<long long>(2));
    dp[0][true] = 1;
    dp[0][false] = 1;

    for (int i = 1; i <= n; ++i) {
        if(s[i] == "AND") {
            dp[i][true] = dp[i-1][true];
            dp[i][false] = dp[i-1][false]*2 + dp[i-1][true];
        } else {
            dp[i][true] = dp[i-1][true]*2 + dp[i-1][false];
            dp[i][false] = dp[i-1][false];
        }
    }
    cout << dp[n][true] << endl;

}
