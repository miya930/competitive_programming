#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

map<int, int> mp;
vector<int> seen;
vector<int> c;

void dfs(const Graph &G, int v) {
    if (mp[c[v]] > 0) seen[v] = 1;
    else seen[v] = 0;
    mp[c[v]]++;

    for (auto nv : G[v]) {
        if (seen[nv] != -1) continue;

        dfs(G, nv);
    }
    mp[c[v]]--;
    if (mp[c[v]] == 0) mp.erase(c[v]);
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    c.resize(n);
    for (int i = 0;i < n; ++i) cin >> c[i];
    for (int i = 0;i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(n, -1);
    seen[0] = 0;

    dfs(G, 0);
    
    for (int i = 0; i < n; ++i) {
        if (seen[i] == 0) cout << i+1 << endl;
    }

    return 0;
}
