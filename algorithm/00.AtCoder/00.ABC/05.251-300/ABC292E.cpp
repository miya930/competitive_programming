#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int ans = 0;

template<class T> void bfs(Graph &G, int x, vector<T> &dist) {
    queue<int> que;
    dist[x] = 0;
    que.push(x);

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;

            if (dist[nv] >= 2) ans++;
            que.push(nv);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        vector<int> dist(n, -1);

        bfs(G, i, dist);
    }

    cout << ans << endl;

    return 0;
}
