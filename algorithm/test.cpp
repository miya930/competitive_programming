#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const int inf = 1001001001;

int n, m;
int dist[1<<17][17];

int main()
{
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 0; i < 1<<n; ++i) {
        for (int j = 0; j < n; ++j) dist[i][j] = inf;
    }
    
    queue<pair<int,int>> que;
    for (int i = 0; i < n; ++i) {
        dist[1<<i][i] = 1;
        que.push(make_pair(1<<i, i));
    }

    while(!que.empty()) {
        int s = que.front().first;
        int v = que.front().second;
        que.pop();

        for (auto nv : G[v]) {
            int ns = s ^ (1<<nv);
            if (dist[ns][nv] < inf) continue;
            dist[ns][nv] = dist[s][v] + 1;
            que.push(make_pair(ns, nv));
        }
    }

    ll ans = 0;
    for (int i = 1; i < 1<<n; ++i) {
        int mn = inf;
        for (int j = 0; j < n; ++j) mn = min(mn, dist[i][j]);

        ans += mn;
    }

    cout << ans << endl;
    return 0;
}
