#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
ll ans = 0;
int n, m;

void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs(G, nv);
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (seen[i] == false) ok= false;
    }

    if (ok) ans++;
    
    seen[v] = false;

}

int main()
{
    cin >> n >> m;
    Graph G(n);
    seen.assign(n, false);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(G, 0);

    cout << ans << endl;
    return 0;
}
