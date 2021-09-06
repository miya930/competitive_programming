#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000;

vector<vector<int> > dist(16, vector<int>(16, INF));
vector<vector<int> > dp(1<<20-1, vector<int>(21, -1));
int n, m;

int rec(int bit, int v, int s) {
    if (dp[bit][v] != -1) return dp[bit][v];

    if (bit == (1<<n)-1 && v == s) {
        return dp[bit][v] = 0;
    }

    int res = INF;
    for (int u = 0; u < n; ++u) {
        if (bit>>u & 1) continue;

        if (res > dp[bit | (1<<u)][u] + dist[v][u]) {
            res = rec(bit | (1<<u), u, s) + dist[v][u];
        }
    }

    return dp[bit][v] = res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    int res = INF;
    for (int i = 0; i < n; ++i) {
        dp.assign(1<<20-1, vector<int>(21, -1));
        if (res > rec(0, i, i)) {
            res = rec(0, i ,i);
        }
    }
    
    if (res == INF) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}