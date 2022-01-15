#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
bool exist = false;

void dfs(const Graph &G, int v, int p) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (p != nv && seen[nv]) exist = true;
        if (seen[nv]) continue;

        dfs(G, nv, v);
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    seen.assign(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (seen[i] == true) continue;
        exist = false;
        dfs(G, i, -1);
        if (!exist) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
