#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> c(m), d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    for (int i = 0; i < m; ++i) cin >> c[i];

    vector<vector<ll> > dp(m+1, vector<ll>(n+1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            chmin(dp[i+1][j+1], dp[i][j]+c[i]*d[j]);
            chmin(dp[i+1][j], dp[i][j]);
        }
    }
    
    ll ans = INF;
    for (int i = 0; i <= m; ++i) chmin(ans, dp[i][n]);

    cout << ans << endl;
}
