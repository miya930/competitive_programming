/**
   created: 11.10.2021 21:56:49
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

vector<vector<int> > dp(1010, vector<int>(10010, inf));

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= h; ++j) {
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i][min(j+a[i], h)], dp[i][j]+b[i]);
        }
    }

    cout << dp[n][h] << endl;

    return 0;
}
