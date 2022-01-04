#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;

void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs(G, nv);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(n, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (seen[i] == true) continue;
        dfs(G, i);
        cnt++;
    }

    if (cnt == 1) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;

    return 0;
}
