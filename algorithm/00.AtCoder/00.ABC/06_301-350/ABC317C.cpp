#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;
vector<bool> seen;
ll ans = 0;

void dfs(Graph &G, int v, ll sum) {
    seen[v] = true;

    for (auto e : G[v]) {
        int nx = e.to;
        ll w = e.w;
        if (seen[nx]) continue;
        dfs(G, nx, sum+w);
    }
    ans = max(ans, sum);
    seen[v] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    seen.assign(n, false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge{a, c});
    }

    for (int i = 0; i < n; i++) {
        dfs(G, i, 0);
    }
    cout << ans << endl;

    return 0;
}
