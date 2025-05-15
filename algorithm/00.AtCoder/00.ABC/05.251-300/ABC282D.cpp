#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<int> color(200020, -1);
int cnt0 = 0, cnt1 = 0;

struct UnionFind {
    vector<int> par, siz;

    void init(int n) {
        par.assign(n, -1);
        siz.assign(n, 1);
    }

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }

};

UnionFind uf;

void dfs(Graph& G, int v, int c) {
    color[v] = c;
    if (c == 0) cnt0++;
    else cnt1++;
    for (auto nv : G[v]) {
        if (color[nv] != -1) continue;

        dfs(G, nv, 1 - c);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    uf.init(n);
    vector<int> rootsz(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        uf.unite(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] != -1) continue;
        cnt0 = 0;
        dfs(G, i, 0);
        rootsz[uf.root(i)] = cnt0;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (auto nv : G[i]) {
            if (color[i] == color[nv]) ok = false;
        }
    }
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int ren = uf.size(i);
        int zero = rootsz[uf.root(i)];
        int one = ren - zero;

        ans = ans + (n - ren);
        if (color[i] == 1) ans += (zero - G[i].size());
        else ans += (one - G[i].size());
    }
    cout << ans/2 << endl;


    return 0;
}
