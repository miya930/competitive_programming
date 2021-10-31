#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int> > dp(n+1, vector<int>(1<<27, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        int shift = s[i] - 'a';
        for (int j = 0; j < 1<<26; ++j) {
            if ((j>>shift) & 1) continue;
            if (dp[i][j] > 0) {
                dp[i+1][j | (1<<shift)] += dp[i][j];
            }
            dp[i+1][j] += dp[i][j]; 
        }
    }

    ll ans = 0;
    for (int i = 1; i < 1<<26; ++i) ans += dp[n][i];

    cout << ans << endl;
    return 0;
}
