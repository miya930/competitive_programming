// 巡回セールスマン問題
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

const int MAXN = 16;
vector<vector<ll> > dp(1<<MAXN, vector<ll>(MAXN));
ll dist[MAXN][MAXN];
int n, m;

ll rec(int bit, int v, int s) {
    if (dp[bit][v] != -1) return dp[bit][v];

    if (bit == (1<<n)-1 && v == s) {
        return dp[bit][v] = 0;
    }

    ll res = INF;

    for (int u = 0; u < n; ++u) {
        if (bit>>u & 1) continue;

        if (res > rec(bit | 1<<u, u, s) + dist[v][u]) {
            res = rec(bit | 1<<u, u, s) + dist[v][u];
        }
    }

    return dp[bit][v] = res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INF;    
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        dist[a][b] = d;
    }

    dp.assign(1<<MAXN, vector<ll>(MAXN, -1));

    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        dp.assign(1<<MAXN, vector<ll>(MAXN, -1));
        if (ans > rec(0, i, i)) {
            ans = rec(0, i, i);
        }
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
