#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll w;
};
using Graph = vector<vector<Edge>>;

vector<ll> dist;
queue<int> que;
void bfs(const Graph &G, int x) {
    que.push(x);
    dist[x] = 0;

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto e : G[v]) {
            if (dist[e.to] != -1) continue;

            dist[e.to] = dist[v] + e.w;
            que.push(e.to);
        }
    } 
    
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    dist.assign(n, -1);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(Edge{v, w});
        G[v].push_back(Edge{u, w});
    }

    bfs(G, 0);

    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        if (dist[i]%2 == 0) ans[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (ans[i] == 1) cout << 1 << endl;
        else cout << 0 << endl;
    } 

    return 0;
}
