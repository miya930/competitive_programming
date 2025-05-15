#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int nmax = 3030;
int hole[nmax][nmax];

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        hole[a][b] = 1;
    }

    vector<vector<ll>> dp(nmax, vector<ll>(nmax, 0));
    ll ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (hole[i][j] == 1) continue;

            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            ans += dp[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}
