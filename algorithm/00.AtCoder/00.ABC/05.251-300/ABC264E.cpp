#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
int n, m, e;
vector<bool> densen;

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

vector<bool> seen;

void dfs(Graph const &G, int v) {
    seen[v] = true;
    densen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;

        dfs(G, nv);
    }
}

int main()
{
    int Q;    
    cin >> n >> m >> e;
    Graph G(n+m);
    densen.assign(n+m, false);
    vector<pair<int,int>> pa;
    UnionFind uf;
    uf.init(n+m);

    for (int i = n; i < n+m; ++i) {
        densen[i] = true;
    }

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        pa.push_back(make_pair(u, v));
    }

    cin >> Q;
    vector<int> ans(Q+1, 0), x(Q);
    map<int,bool> mp;
    for (int q = 0; q < Q; ++q) {
        cin >> x[q];
        x[q]--;
        mp[x[q]] = true;
    }

    int tmp = 0;

    for (int i = 0; i < e; ++i) {
        if (mp[i]) continue;
        int u = pa[i].first;
        int v = pa[i].second;
        if (densen[u] == true && densen[v] == false) {
            seen.assign(n, false);
            dfs(G, v);
            tmp += uf.size(v);
        } else if (densen[u] == false && densen[v] == true) {
            seen.assign(n, false);
            dfs(G, u);
            tmp += uf.size(u);
        }

        G[u].push_back(v);
        G[v].push_back(u);
        uf.unite(u,v);
    }

    ans[Q-1] = tmp;

    for (int q = Q-2; q >= 0; --q) {

        int u = pa[x[q+1]].first;
        int v = pa[x[q+1]].second;

        ans[q] = ans[q+1];

        if (densen[u] == true && densen[v] == false) {
            seen.assign(n, false);
            dfs(G, v);
            ans[q] += uf.size(v);
        } else if (densen[v] == true && densen[u] == false) {
            seen.assign(n, false);
            dfs(G, u);
            ans[q] += uf.size(u);
        }
        
        uf.unite(u, v);
        G[v].push_back(u);
        G[u].push_back(v);
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
