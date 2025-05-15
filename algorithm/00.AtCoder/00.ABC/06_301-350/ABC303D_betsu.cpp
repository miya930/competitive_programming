#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    ll x, y, z;
    string s;
    cin >> x >> y >> z >> s;
    int n = s.size();

    vector<vector<ll>> dp(n+1, vector<ll>(2, infl));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        // a
        if (s[i] == 'A') {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + y);
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + z + x);
            dp[i+1][0] = min(dp[i+1][0], dp[i][1] + z + y);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + x);
        } else {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + x);
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + z + y);
            dp[i+1][0] = min(dp[i+1][0], dp[i][1] + z + x);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + y);            
        }
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
    return 0;
}
