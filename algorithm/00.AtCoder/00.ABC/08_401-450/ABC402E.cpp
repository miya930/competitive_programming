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
    int n, x;
    cin >> n >> x;
    vector<int> s(n), c(n), p(n);
    rep(i, 0, n) cin >> s[i] >> c[i] >> p[i];

    vector<vector<double>> dp((1<<n), vector<double>(x+100, 0));
    for (int i = 0; i < x+1; i++) {
        for (int j = 0; j < (1<<n); j++) {
            for (int k = 0; k < n; k++) {
                int xx = i - c[k];
                int jj = j | (1 << k);
                if (xx < 0 || jj == j) continue; 

                double val = (double)p[k] / 100.0 * (dp[jj][xx] + (double)s[k]) + (double)(100.0 - (double)p[k]) / 100.0 * dp[j][xx];
                dp[j][i] = max(dp[j][i], val);
            }
        }
    }
    printf("%.10lf\n", dp[0][x]);
    return 0;
}
