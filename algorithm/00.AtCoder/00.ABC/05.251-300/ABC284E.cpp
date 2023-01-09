#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
int ans = 0;
const int limit = 1e6;

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
    auto dfs = [&](auto rc, int v) -> void {
        if (ans == limit) return;
        ans++;
        seen[v] = true;
        for (auto& nv : G[v]) {
            if (seen[nv]) continue;
            rc(rc, nv);
        }
        seen[v] = false;
    };

    dfs(dfs, 0);
    cout << ans << endl;
    return 0;
}
