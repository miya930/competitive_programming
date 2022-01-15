#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

struct edge {
    int w;
    int u;
    int v;
    int idx;
};

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<edge> pa;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        pa.push_back({})
    }

    for (int i = 0; i < q; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge e;
        e.u = u; e.v = v; e.idx = i;
        pa.push_back(make_pair(w, e));
    }

    sort(pa.begin(),pa.end());

    UnionFind uf;
    uf.init(n);

    vector<bool> ans(q, false);
    for (int i = 0; i < (int)pa.size(); ++i) {
        int u = pa[i].second.u;
        int v = pa[i].second.v;
        int w = pa[i].first;
        int idx = pa[i].second.idx;
        
        if (idx != -1) {
            if (uf.issame(u,v)) ans[idx] = false;
            else ans[idx] = true;
            continue;
        } else {
            if (us.issame(u,v)) continue;
        }

        uf.unite(u,v);
    }

    for (int i = 0; i < (int)ans.size(); ++i) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
