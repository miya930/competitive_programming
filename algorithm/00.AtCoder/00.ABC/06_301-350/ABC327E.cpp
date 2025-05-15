#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };


int main()
{
    int n;
    cin >> n;
    vector<long double> p(n);
    rep(i, 0, n) cin >> p[i];

    vector<vector<long double>> dp(n+1, vector<long double>(n+1, -1));
    dp[0][0] = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (dp[i][j] < 0) continue;
            long double tmp = dp[i][j]*(long double)0.9 + p[i];
            dp[i+1][j+1] = max(dp[i+1][j+1], tmp);

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    long double ans = -5000;
    long double den = 1.0;
    rep(i, 1, n+1) {
        long double r = dp[n][i] / den - (long double)1200.0 / (long double)sqrt((long double)i);
        ans = max(ans, r);

        den *= (long double)0.9;
        den += (long double)1.0;
    }
    printf("%.10lf\n", (double)ans);
    return 0;
}
