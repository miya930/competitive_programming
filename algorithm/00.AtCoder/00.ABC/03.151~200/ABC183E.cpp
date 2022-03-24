#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    vector<vector<ll>> x(h, vector<ll>(w, 0)), y(h, vector<ll>(w, 0)), z(h, vector<ll>(w, 0)), dp(h, vector<ll>(w, 0));
    dp[0][0] = 1;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 && j == 0) continue;
            if (s[i][j] == '#') continue;
            if (j > 0) x[i][j] = (x[i][j-1] + dp[i][j-1])%mod;
            if (i > 0) y[i][j] = (y[i-1][j] + dp[i-1][j])%mod;
            if (i > 0 && j > 0) z[i][j] = (z[i-1][j-1] + dp[i-1][j-1])%mod;
            dp[i][j] = ((ll)x[i][j]+y[i][j]+z[i][j])%mod;
        }
    }

    cout << dp[h-1][w-1] << endl;
    return 0;
}
