#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];

    vector<vector<ll>> dp(1010, vector<ll>(1010));
    ll ans = -infl;
    for (int a = -1; a <= 1; ++a) {
        for (int b = -1; b <= 1; ++b) {
            for (int c = -1; c <= 1; ++c) {
                if (a != 0 && b != 0 && c != 0) {
                    dp.assign(1010, vector<ll>(1010, -infl));
                    dp[0][0] = 0;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j <= m; ++j) {
                            ll tmp = a*x[i] + b*y[i] + c*z[i];
                            chmax(dp[i+1][j], dp[i][j]);
                            chmax(dp[i+1][j+1], dp[i][j] + tmp);
                        }
                    }
                    chmax(ans, dp[n][m]);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
