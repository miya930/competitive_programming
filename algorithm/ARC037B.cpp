#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
bool exist = false;
queue<int> que;

void bfs(const Graph &G, int x) {
    seen[x] = true;
    que.push(x);

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (v != nv && seen[nv] == true) exist = true;
            if (seen[nv]) continue;
            que.push(nv);
        }
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
        bfs(G, i);
        if (!exist) ans++;
        cout << i << endl;
    }
    
    cout << ans << endl;
    return 0;
}
