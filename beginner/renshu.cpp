#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int dp[(1<<20)+1][21];
int n, m;
vector<vector<int> > dist;

int rec(int bit, int v, int s) {
    if (dp[bit][v] != -1) return dp[bit][v];

    if (bit == (1<<v) && v == s) {
        return dp[bit][v] = 0;
    }

    int res = INF;

    int prev_bit = bit & ~(1<<v);

   for (int u = 0; u < n; ++u) {
        if (!(prev_bit & (1<<u))) continue;

        if (res > rec(prev_bit, u, s) + dist[u][v]) {
            res = rec(prev_bit, u, s) + dist[u][v];
        }
    }

    return dp[bit][v] = res;
}

int main()
{
    cin >> n >> m;
    dist.assign(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        dist[a][b] = d;
    }

    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -1; 
        }
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (ans > rec((1<<n)-1, i, i)) {
            ans = rec((1<<n)-1, i, i);
        }
    }
    cout << ans << endl;
}
