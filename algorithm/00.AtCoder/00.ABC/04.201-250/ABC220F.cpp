#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<ll> sub, ans;
int n;

void dfs(const Graph &G, int v, int d) {
    ans[0] += d;
    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs(G, nv, d+1);
        sub[v] += sub[nv];
    }
}

void dfs2(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        ans[nv] = ans[v] + n - 2*sub[nv];
        dfs2(G, nv);
    }
}

int main()
{
    cin >> n;
    Graph G(n);
    sub.assign(n, 1);
    seen.assign(n, false);
    ans.assign(n, 0);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(G, 0, 0);
    seen.assign(n, false);
    dfs2(G, 0);

    for (int i = 0; i < n; ++i) cout << ans[i] << endl;

    return 0;
}
