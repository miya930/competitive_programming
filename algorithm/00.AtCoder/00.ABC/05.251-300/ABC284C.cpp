#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(Graph const G, int x) {
    seen[x] = true;

    for (auto nv : G[x]) {
        if (seen[nv]) continue;

        dfs(G, nv);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    seen.assign(n, false);
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        dfs(G, i);

        ans++;
    }

    cout << ans << endl;

    return 0;
}
